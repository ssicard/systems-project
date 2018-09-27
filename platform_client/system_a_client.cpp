#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/json.hpp"
#include <sstream>
#include <string>

int main(int argc, char **argv){
  
  int clientfd;
  char *host, *port, *name, data[MAXLINE], buf[MAXLINE];
  rio_t rio;
  fd_set read_set, ready_set;
  if (argc != 4) {
    printf("<<<---Error:Invalid number of arguments--->>>\n");
	  fprintf(stderr, "usage: %s <host> <port> <name>\n", argv[0]);
	  exit(0);
  }
  host = argv[1];
  port = argv[2];
  name = argv[3];
  std::stringstream ss;
  std::string name_string;
  //std::string name_string(name, sizeof(name));
  ss << name;
  ss >> name_string;

  clientfd = Open_clientfd(host, port); /* Open client for connection */
  Rio_readinitb(&rio, clientfd); /* initialize rio */

  FD_ZERO(&ready_set); /* Clearing ready_set*/
  FD_ZERO(&read_set); /* clearing read_set */
  FD_SET(STDIN_FILENO, &read_set); /* Adding stdin to read_set */
  FD_SET(clientfd, &read_set); /* setting client descriptors to read_set */ 
  
  while (1){
    ready_set = read_set;
    /* waiting for event */ 
    select(clientfd+1, &ready_set, NULL, NULL, NULL);
    if(FD_ISSET(STDIN_FILENO, &ready_set)){
      /* Copying username into the buffer */
      memset(&data, 0, sizeof(data));
      nlohmann::json j;
      j["identity"] = name_string;
      j["Client"] = "A";
      //strcat(data,"<");
      //strcat(data, name);
      //strcat(data, "> [+] "); 
      /*getting the inputs from stdin */
      Fgets(buf, MAXLINE, stdin);
      if(buf[0] == '\\'){
        if (buf[1] == 'q'){
          printf("\\q innitiated, are you sure you want to quit session? (enter c to continue, type any other keys to quit)\n");
          Fgets(buf, MAXLINE, stdin);
          printf("%c\n", buf[0]);
          if(buf[0]=='c'){
            printf("<<<---Continuing Session--->>>\n");
            continue;
          } else {
            printf("<<<---Session Terminating--->>>\n");
            exit(0);
          }
        }
      }
      buf[strlen(buf)-1] = '\0';
      j["message"] = buf;
      std::string send_this = j.dump(3);
      send_this += "\n";
      std::cout << send_this.c_str() << std::endl;
      //strcat(data, buf);
      char char_star[send_this.length()];
      strcpy(char_star,send_this.c_str());
      Rio_writen(clientfd, char_star, strlen(data));
      memset(&data, 0, sizeof(data));
    }
    if(FD_ISSET(clientfd, &ready_set)){
      Rio_readlineb(&rio, data, MAXLINE);
      Fputs(data, stdout);
      memset(&data, 0, sizeof(data));
    }
  }
  Close(clientfd);
  exit(0);
}

/* $end echoclientmain */
