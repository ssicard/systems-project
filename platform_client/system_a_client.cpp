#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/json.hpp"
#include <sstream>
#include <string>
#include "./message_elements/Message.h"

int main(int argc, char **argv){
  
  int clientfd;
  char *host, *port, data[MAXLINE], buf[MAXLINE];
  rio_t rio;
  fd_set read_set, ready_set;
  if (argc != 4) {
    printf("<<<---Error:Invalid number of arguments--->>>\n");
	  fprintf(stderr, "usage: %s <host> <port> <name>\n", argv[0]);
	  exit(0);
  }
  host = argv[1];
  port = argv[2];
  std::string name_string(argv[3]);

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
      memset(&data, 0, sizeof(data));
      nlohmann::json j;

      /*getting the inputs from stdin */
      Fgets(buf, MAXLINE, stdin);
      if(buf[0] == '\\'){
        if (buf[1] == 'q'){
          printf("\\q innitiated, are you sure you want to quit session"); 
          printf("(enter c to continue, type any other keys to quit)?\n");
          Fgets(buf, MAXLINE, stdin);
          printf("%c\n", buf[0]);
          if(buf[0]=='c'){
            printf("<<<---Continuing Session--->>>\n");
            continue;
          } else {
            printf("<<<---Session Terminating--->>>\n");
            // TODO: send log out message
            exit(0);
          }
        }
      }
      buf[strlen(buf)-1] = '\0';

      //read the json file
      std::string filename = "./sample_messages/";
      filename += buf;

      //read the json file
      std::ifstream i(filename);
      i >> j;
      std::string send_this = j.dump();
      send_this += "\n";
      char char_star[send_this.length()];
      strcpy(char_star,send_this.c_str());
      Rio_writen(clientfd, char_star, strlen(char_star));
      memset(&data, 0, sizeof(data));
    }
    if(FD_ISSET(clientfd, &ready_set)){
      Rio_readlineb(&rio, data, MAXLINE);
      if(data[0] == '{' || data[0] == '[') {
        Fputs(data, stdout);
      }
      memset(&data, 0, sizeof(data));
    }
  }
  Close(clientfd);
  exit(0);
}

/* $end echoclientmain */
