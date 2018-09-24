#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
//#include <map>

typedef struct { /* Represents a pool of connected descriptors */ 
  int maxfd;        /* Largest descriptor in read_set */   
  fd_set read_set;  /* Set of all active descriptors */
  fd_set ready_set; /* Subset of descriptors ready for reading  */
  int nready;       /* Number of ready descriptors from select */   
  int maxi;         /* Highwater index into client array */
  int clientfd[FD_SETSIZE];    /* Set of active descriptors */
  rio_t clientrio[FD_SETSIZE]; /* Set of active read buffers */
} pool; /* Connection pool struct*/

//std::map<std::string, int> client_list;
std::vector<std::string> client_list;
std::vector<int> client_fd_list;
void init_pool(int listenfd, pool *p);
void add_client(int connfd, pool *p);
void communication(pool *p); 
int byte_cnt = 0; /* counting total bytes received by server */

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
  char* message = "<<<---Connected to server--->>>\n";
  p->nready--;
  for (i = 0; i < FD_SETSIZE; i++){  /* Find an available slot */
    if (p->clientfd[i] < 0) { 
      /* Add connected descriptor to the pool */
      p->clientfd[i] = connfd;                 
      Rio_readinitb(&p->clientrio[i], connfd); 
      /* Add the descriptor to descriptor set */
      FD_SET(connfd, &p->read_set); 
      /* Send confirming connection to client */
      Rio_writen(p->clientfd[i], message, strlen(message));
      /* Update max descriptor and pool highwater mark */
      if (connfd > p->maxfd) 
	 p->maxfd = connfd; 
      if (i > p->maxi)       
	 p->maxi = i;       
      break;
    }
    if (i == FD_SETSIZE){ /* Couldn't find an empty slot */
      app_error("add_client error: Too many clients");
    }
  }
}

/* allows all clients to communicates with each other */
void communication(pool *p) {
  Logger l(Logger::INFO, Logger::NORMAL);
  int i, connfd, n;
  char buf[MAXLINE];
  rio_t rio;
  for (i = 0; (i <= p->maxi) && (p->nready > 0); i++) {
    connfd = p->clientfd[i];
    rio = p->clientrio[i];
    /* If the descriptor is ready, echo a text line from it */
    if ((connfd > 0) && (FD_ISSET(connfd, &p->ready_set))) { 
      p->nready--;
      if ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        byte_cnt += n; 
        printf("Server received %d (%d total) bytes on fd %d\n", n, byte_cnt, connfd);
        int j = 0;
        while(p->clientfd[j] >= 0){
          Rio_writen(p->clientfd[j], buf, n); // write buffer into fd
          j++;
          std::stringstream ss;
          std::string current_id;         
          ss << buf;
          ss >> current_id;
          l.log(Logger::INFO, buf);
          current_id.erase(remove_if(current_id.begin(), current_id.end(), [](char c) { return !isalpha(c); } ), current_id.end());
          if (std::find(client_list.begin(), client_list.end(), current_id) == client_list.end() && std::find(client_fd_list.begin(), client_fd_list.end(), p->clientfd[j]) == client_fd_list.end()){
          //if (client_list.find(current_id) == client_list.end()) {
            std::cout << "New client connected: " << current_id << std::endl;
            l.log(Logger::INFO, "New client connected: " + current_id + "\n");
            //client_list.emplace(current_id, p->clientfd[j]);
            client_list.push_back(current_id);
            client_fd_list.push_back(p->clientfd[j]);
          } else if (std::find(client_list.begin(), client_list.end(), current_id) != client_list.end() && std::find(client_fd_list.begin(), client_fd_list.end(), p->clientfd[j]) == client_fd_list.end()){
            std::cout << "[Error] same user name: " << current_id << std::endl;
            char* login_error = "Login failed";
            Rio_writen(p->clientfd[j], login_error, sizeof(login_error));
            //send_login_error();
          }
          //client_list.push_back(current_id); 
	  //Fputs(buf, stdout);
        }
      } else {/* EOF detected, remove descriptor from pool */
        Close(connfd); 
	FD_CLR(connfd, &p->read_set); 
	p->clientfd[i] = -1; /* marks as available */         
      }
    }
  }
}


