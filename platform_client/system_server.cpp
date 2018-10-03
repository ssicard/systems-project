#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/json.hpp"
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef struct { /* Represents a pool of connected descriptors */ 
  int maxfd;        /* Largest descriptor in read_set */   
  fd_set read_set;  /* Set of all active descriptors */
  fd_set ready_set; /* Subset of descriptors ready for reading  */
  int nready;       /* Number of ready descriptors from select */   
  int maxi;         /* Highwater index into client array */
  int clientfd[FD_SETSIZE];    /* Set of active descriptors */
  rio_t clientrio[FD_SETSIZE]; /* Set of active read buffers */
} pool; /* Connection pool struct*/

std::map<std::string, int> json_name_to_fd; // to track json client
std::map<std::string, int> xml_name_to_fd; // to track xml client
void init_pool(int listenfd, pool *p);
void add_client(int connfd, pool *p);
void communication(pool *p); 
void handle_json_client(char* tmp, int connfd);
void show_current_map(std::map<std::string, int> map);
uint32_t json_byte_cnt{0}; 
uint32_t xml_byte_cnt{0};

int main(int argc, char **argv) {
  int listenfd, connfd;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;
  static pool pool; 

  if (argc != 2) {
    printf("<<<---Error:Invalid number of arguments--->>>\n");
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(0);
  }
  printf("\n<<<---Server successfully started--->>>\n\n");

  listenfd = Open_listenfd(argv[1]); // listening to port
  init_pool(listenfd, &pool); // initializing pool

  while (1) {
    /* Wait for listening/connected descriptor(s) to become ready */
    pool.ready_set = pool.read_set;
    pool.nready = Select(pool.maxfd+1, &pool.ready_set, NULL, NULL, NULL);

    /* If listening descriptor ready, add new client to pool */
    if (FD_ISSET(listenfd, &pool.ready_set)) { 
      clientlen = sizeof(struct sockaddr_storage);
      connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen); 
      add_client(connfd, &pool);
    } 
    /* talk */
    communication(&pool); 
  }
  return 0;
}

void init_pool(int listenfd, pool *p) {
  /* Initially, there are no connected descriptors */
  int i;
  p->maxi = -1;                   
  for (i=0; i < FD_SETSIZE; i++){  
	  p->clientfd[i] = -1;        
  }
  /* Initially, listenfd is only member of select read set */
  p->maxfd = listenfd;            
  FD_ZERO(&p->read_set);
  FD_SET(listenfd, &p->read_set); 
}

void add_client(int connfd, pool *p) {
  int i;
  char* logon = "<<<---Connected to server--->>>\n";
  p->nready--;
  for (i = 0; i < FD_SETSIZE; i++){  /* Find an available slot */
    if (p->clientfd[i] < 0) { 
      /* Add connected descriptor to the pool */
      p->clientfd[i] = connfd;                 
      Rio_readinitb(&p->clientrio[i], connfd); 
      /* Add the descriptor to descriptor set */
      FD_SET(connfd, &p->read_set); 
      /* Send confirming connection to client */
      Rio_writen(p->clientfd[i], logon, strlen(logon));
      /* Update max descriptor and pool highwater mark */
      if (connfd > p->maxfd) 
	 p->maxfd = connfd; 
      if (i > p->maxi)       
	 p->maxi = i;       
      break;
    }
    if (i == FD_SETSIZE){ /* Couldn't find an empty slot */
      app_error("add_client error: Too many clients\n");
    }
  }
}

/* allows all clients to communicates with each other */
void communication(pool *p) {
  Logger l(Logger::INFO, Logger::NORMAL);
  int i, connfd, n;
  char buf[MAXLINE];
  char tmp[MAXLINE];
  rio_t rio;
  for (i = 0; (i <= p->maxi) && (p->nready > 0); i++) {
    connfd = p->clientfd[i];
    rio = p->clientrio[i];
    /* If the descriptor is ready, echo a text line from it */
    if ((connfd > 0) && (FD_ISSET(connfd, &p->ready_set))) { 
      p->nready--;
      // reading rio to buf
      if ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        int j = 0;
        strcpy(tmp, buf); // we don't wanna mess with buf
        while(p->clientfd[j] >= 0){
          //TODO: at this point we're just sending back the data 
          Rio_writen(p->clientfd[j], buf, n); // write buffer into fd
          l.log(Logger::INFO, buf);
          // but we need to convert this to xml and send back to all client 
          if (tmp[0] == '{'){ // json client
            json_byte_cnt += n; // increment bytes received by json client
            printf("Received %d (%d total) bytes by a json client with fd[%d]\n",n,json_byte_cnt,connfd);
            handle_json_client(tmp, connfd);  
          } else if (tmp[0] == '<') { // xml clients 
            xml_byte_cnt+= n; // increment bytes received by xml client 
            printf("Received %d (%d total) bytes by a xml_client with fd[%d]\n",n,xml_byte_cnt,connfd);
            //TODO: handle_xml_client(tmp, connfd);
          } else { // we don't mess with this
            printf("[error] unknown protocol\n");
          }
          j++;
        }
      } else {/* EOF detected, remove descriptor from pool */
        Close(connfd); 
	    FD_CLR(connfd, &p->read_set); 
	    p->clientfd[i] = -1; /* marks as available */         
      }
    }
  }
}

// right now only trying to see if client is new or not, if it is add to map
void handle_json_client(char* tmp, int connfd){
  nlohmann::json j = nlohmann::json::parse(tmp); // parse tmp
  std::cout << j.dump(2) << std::endl; // print whole json for debugging purposes
  std::string identity = j["identity"]; // name is here
  if (json_name_to_fd.find(identity) == json_name_to_fd.end()){
    //never seen this name before, adding to map
    printf("This is a new json client, adding %s with fd %d to map\n",identity.c_str(),connfd);
    json_name_to_fd[j["identity"]] = connfd; // addding this connection fd to map
    //show_current_map(json_name_to_fd); //for debugging purposes  
  } 
}

// if you need to look at any maps
void show_current_map(std::map<std::string, int> map){
  printf("name and connfd in map:\n");
  for (const auto it : map){
    std::cout << "Name: [" << it.first << "] Connfd: [" << it.second <<  "]" << std::endl;
  }
}


