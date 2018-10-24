#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/json.hpp"
#include "./translation/translation-engine.h"
#include "./message_elements/RequestResource.h"
#include "./message_elements/ResponseToRequestResource.h"
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
void handle_json_client(std::string json_str, int connfd);
void handle_xml_client(std::string xml_str, int connfd);
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

  for(;;) {
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
  char logon[] = "<<<---Connected to server--->>>\n";
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
      char too_many_clients[] = "add_client error: Too many clients\n";
      app_error(too_many_clients);
    }
  }
}

/* allows all clients to communicates with each other */
void communication(pool *p) {
  Logger l(Logger::INFO, Logger::NORMAL);

  int i, connfd, n;

  char buf[MAXLINE];
  char tmp[MAXLINE];

  TranslationEngine t_engine;
  rio_t rio;
  for (i = 0; (i <= p->maxi) && (p->nready > 0); i++) {
    connfd = p->clientfd[i];
    rio = p->clientrio[i];
    // check if any fd is ready 
    if ((connfd > 0) && (FD_ISSET(connfd, &p->ready_set))) { 
      p->nready--;
      // reading rio to buf
      if ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        int j = 0; // going through all j
        strcpy(tmp, buf); // we don't wanna mess with buf

        while(p->clientfd[j] >= 0){
          std::string tmp_std_str(tmp);

          // TODO: at this point we're just sending back the data to all p->client[j]
          // but we need to convert this buf to both formats
          // and iterate through both maps and send the right format to the right client
          //Rio_writen(p->clientfd[j], buf, n); // write buffer into fd
          //l.log(Logger::INFO, buf); //
          if (tmp[0] == '{' || tmp[0] == '['){ // json client
            json_byte_cnt += n; // increment bytes received by json client
        
            printf("Received %d (%d total) bytes by a json client with fd[%d]\n",n,json_byte_cnt,connfd);
            stringstream logMessage;
            logMessage << "Received "<<n<<"("<<json_byte_cnt<<" total) bytes by a json client with fd["<<connfd<<"]";
            l.log(Logger::LogLevel::INFO, logMessage.str());
            handle_json_client(tmp, connfd);
            if(tmp_std_str.find("RequestResource") != std::string::npos) {
              RequestResource request = t_engine.json_to_request_resource_msg("", tmp);
              std::string out = t_engine.request_resource_msg_to_xml(request) + "\n";

			  // save to datbase
			  std::cout << request.MessageID << std::endl;
			  std::cout << request.SentDateTime << std::endl;
			  std::cout << request.inc_info.IncidentID << std::endl;

			  request.res_info._AssignmentInformation = request.res_info.assign_info;
			  request.res_info._ScheduleInformation = request.res_info.sched_info;
			  request.res_info._ScheduleInformation.LocationTypeID = 1;
			  request.res_info._ScheduleInformation._Location.LocationTypeID = 1;
			  request.res_info._ScheduleInformation._Location.LocationDescription = request.res_info._ScheduleInformation.Location;

			  request.inc_info.insertIntoDatabase();
			  request.msg_rcl.insertIntoDatabase();
			  request.fund.insertIntoDatabase();
			  request.res_info.insertIntoDatabase();
			  request.contact_info.insertIntoDatabase();

              //strcpy(tmp_xml, out.c_str());
              stringstream logMessageIn;
              logMessageIn << "[RequestResource Message]"<<tmp;
              l.log(Logger::LogLevel::INFO, logMessageIn.str());
              handle_xml_client(out, p->clientfd[j]);
              stringstream logMessageOut;
              logMessageOut << "[Sent Message to "<<p->clientfd[j]<<"]"<<out;
              l.log(Logger::LogLevel::INFO, logMessageOut.str());
            } else if(tmp_std_str.find("ResponseToRequestResource") != std::string::npos) {
              ResponseToRequestResource response = t_engine.json_to_response_to_request_resource_msg("", tmp);
              std::string out = t_engine.response_to_request_resource_msg_to_xml(response) + "\n";
              //strcpy(tmp_xml, out.c_str());
              stringstream logMessageIn;
              logMessageIn << "[ResponseToRequestResource Message]"<<tmp;
              l.log(Logger::LogLevel::INFO, logMessageIn.str());
              handle_xml_client(out, p->clientfd[j]);
              stringstream logMessageOut;
              logMessageOut << "[Sent Message to "<<p->clientfd[j]<<"]"<<out;
              l.log(Logger::LogLevel::INFO, logMessageOut.str());
            }
          } else if (tmp[0] == '<') { // xml clients 
            xml_byte_cnt+= n; // increment bytes received by xml client 
            printf("Received %d (%d total) bytes by a xml_client with fd[%d]\n",n,xml_byte_cnt,connfd);
            stringstream logMessage;
            logMessage << "Received "<<n<<"("<<xml_byte_cnt<<" total) bytes by a xml client with fd["<<connfd<<"]";
            l.log(Logger::LogLevel::INFO, logMessage.str());
            if(tmp_std_str.find("RequestResource") != std::string::npos) {
              RequestResource request = t_engine.xml_to_request_resource_msg("", tmp);
              std::string out = t_engine.request_resource_msg_to_json(request) + "\n";
              //strcpy(tmp_json, out.c_str());
              stringstream logMessageIn;
              logMessageIn << "[RequestResource Message]"<<tmp;
              l.log(Logger::LogLevel::INFO, logMessageIn.str());
              handle_json_client(out, p->clientfd[j]);
              stringstream logMessageOut;
              logMessageOut << "[Sent Message to "<<p->clientfd[j]<<"]"<<out;
              l.log(Logger::LogLevel::INFO, logMessageOut.str());
              
            } else if(tmp_std_str.find("ResponseToRequestResource") != std::string::npos) {
              ResponseToRequestResource response = t_engine.xml_to_response_to_request_resource_msg("", tmp);
              std::string out = t_engine.response_to_request_resource_msg_to_json(response) + "\n";
              //strcpy(tmp_json, out.c_str());
              stringstream logMessageIn;
              logMessageIn << "[ResponseToRequestResource Message]"<<tmp;
              l.log(Logger::LogLevel::INFO, logMessageIn.str());
              handle_json_client(out, p->clientfd[j]);
              stringstream logMessageOut;
              logMessageOut << "[Sent Message to "<<p->clientfd[j]<<"]"<<out;
              l.log(Logger::LogLevel::INFO, logMessageOut.str());
            }
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
void handle_json_client(std::string out, int connfd){
  //std::cout << std::string(tmp) << '\n'; // print whole json for debugging purposes
  //std::string identity = j["identity"]; // name is here
  //if (json_name_to_fd.find(identity) == json_name_to_fd.end()){
    //never seen this name before, adding to map
    //printf("[This is a new json client, adding %s with fd %d to map]\n",identity.c_str(),connfd);
    //json_name_to_fd[j["identity"]] = connfd; // addding this connection fd to map
    //show_current_map(json_name_to_fd); //for debugging purposes
  //}
  char json_str[MAXLINE];
  strcpy(json_str, out.c_str());
  Rio_writen(connfd, json_str, out.size());
}

void handle_xml_client(std::string out, int connfd) {
  char xml_str[MAXLINE];
  strcpy(xml_str, out.c_str());
  Rio_writen(connfd, xml_str, out.size());
}
// if you need to look at any maps
void show_current_map(std::map<std::string, int> map){
  printf("name and connfd in map:\n");
  for (const auto it : map){
    std::cout << "Name: [" << it.first << "] Connfd: [" << it.second <<  "]" << std::endl;
  }
}


