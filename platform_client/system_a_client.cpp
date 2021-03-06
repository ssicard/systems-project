#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/json.hpp"
#include <sstream>
#include <string>
#include "./message_elements/Message.h"

int main(int argc, char **argv){
  Logger logger(Logger::LogLevel::INFO, Logger::LogMode::NORMAL);
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

  bool connection_msg_seen = true;

  while (1){
    ready_set = read_set;
    /* waiting for event */
    select(clientfd+1, &ready_set, NULL, NULL, NULL);
    if(FD_ISSET(STDIN_FILENO, &ready_set)){
      memset(&data, 0, sizeof(data));
      nlohmann::json j;

      /*getting the filename from stdin */
      Fgets(buf, MAXLINE, stdin);
      buf[strlen(buf)-1] = '\0';
      std::string filename = "./messages/";
      filename += buf;

      //read the json file
      std::ifstream i(filename);
      try {
        i >> j;
        std::string send_this = j.dump();
        send_this += "\n";
        char *msg = new char[send_this.length()];
        strcpy(msg,send_this.c_str());
		std::cout << "Sending to server!\n";
        Rio_writen(clientfd, msg, strlen(msg));
		std::cout << "After send to server!\n";
        string dataString(msg);
        logger.log(Logger::LogLevel::INFO, "Sending message from "+name_string);
        logger.log(Logger::LogLevel::INFO, dataString);
        memset(&data, 0, sizeof(data));
        delete[] msg;
      } catch (nlohmann::detail::parse_error e) {
        puts("[ERROR] Not a valid JSON object\n");
      }
    }
    if(FD_ISSET(clientfd, &ready_set)){
	  //std::cout << "Reading from server\n";
      Rio_readlineb(&rio, data, MAXLINE);
	  //std::cout << "After read from server\n";
      logger.log(Logger::LogLevel::INFO, "Message Recieved by "+name_string);
      logger.log(Logger::LogLevel::INFO, data);
      if(!connection_msg_seen) {
        if(data[0] == '<') Fputs(data, stdout);
      }
      else if(data[0] == '{' || data[0] == '[') {
        Fputs(data, stdout);
      }
      memset(&data, 0, sizeof(data));
    }
  }
  Close(clientfd);
  exit(0);
}

/* $end echoclientmain */
