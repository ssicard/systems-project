
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

#include <unistd.h>

#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/pugixml/pugixml.hpp"

using namespace std;

typedef pugi::xml_node Node;
typedef pugi::xml_document Document;

//Source: https://pugixml.org/docs/samples/save_custom_writer.cpp

struct xml_string_writer : pugi::xml_writer
{
	std::string result;

	virtual void write(const void* data, size_t size)
	{
		result.append(static_cast<const char*>(data), size);
	}
};

struct xml_memory_writer : pugi::xml_writer
{
	char* buffer;
	size_t capacity;

	size_t result;

	xml_memory_writer() : buffer(0), capacity(0), result(0)
	{
	}

	xml_memory_writer(char* buffer, size_t capacity) : buffer(buffer), capacity(capacity), result(0)
	{
	}

	size_t written_size() const
	{
		return result < capacity ? result : capacity;
	}

	virtual void write(const void* data, size_t size)
	{
		if (result < capacity)
		{
			size_t chunk = (capacity - result < size) ? capacity - result : size;

			memcpy(buffer + result, data, chunk);
		}

		result += size;
	}
};

void parse_data(string *rawXml){
	Document document;
	pugi::xml_parse_result result =  document.load_string(rawXml->c_str());
	cout << "XML Parse Result: " <<  result.description() << endl;
	Node rootNode = document.first_child();
	string nodeName = rootNode.name();
	if (nodeName.compare("RequestResource") == 0){
		cout << "Resource Requested.\n";
		cout  << "MessageID: " << rootNode.child_value("MessageID") << endl;
		cout  << "MessageDescription: " << rootNode.child_value("MessageDescription") << endl;
		cout  << "OriginatingMessageID: " << rootNode.child_value("OriginatingMessageID") << endl;
		cout  << "Incident" << endl;
		Node incidentNode = rootNode.child("IncidentInformation");
		cout << "IncidentID: " <<  incidentNode.child_value("IncidentID") << endl;
		cout << "Description of Incident: " <<  incidentNode.child_value("IncidentDescription") << endl;
		cout << "Resource Information" << endl;
		Node resourceInfoNode = rootNode.child("ResourceInformation");
		cout << "Resource Information ID: " << resourceInfoNode.child_value("ResourceInformationID") << endl;
		Node resourceNode = resourceInfoNode.child("Resource");
		cout << "ResourceID: " << resourceNode.child_value("ResourceID") << endl;
		cout << "Resource Name: " << resourceNode.child_value("Name") << endl;
		cout << "Resource Description: " << resourceNode.child_value("Description") << endl;

	} else if (nodeName.compare("ResponseToRequestResource") == 0){
		cout << "Response to Request Recieved.\n";
	}
}




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
	// Create an empty ready set
	FD_ZERO(&ready_set); 
	//Create an empty read set
	FD_ZERO(&read_set); 
	//Add Standard input to read set
	FD_SET(STDIN_FILENO, &read_set); 
	//Add socket input to read set
	FD_SET(clientfd, &read_set); 


	while (1) {
		//Get ready connections
        	ready_set = read_set;
        	Select(clientfd+1, &ready_set, NULL, NULL, NULL);
		//MESSAGE SENT
		if (FD_ISSET(STDIN_FILENO, &ready_set)) {
			memset(&data, 0, sizeof(data));
			pugi::xml_document x;

			//get filename from stdin
			Fgets(buf, MAXLINE, stdin);
			buf[strlen(buf)-1] = '\0';
			std::string filename = "./messages/";
			filename += buf;

			//read the xml
			std::ifstream stream(filename);
			pugi::xml_parse_result result = x.load(stream);
			if(result){
			    std::string send_this((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
			    std::cout <<"parse result" << send_this;
			    send_this += "\n";
			    char *msg = new char[send_this.length()];
			    //strcpy(msg, stream);
			    strcpy(msg, send_this.c_str());
			    Rio_writen(clientfd, msg, strlen(msg));
			    std::string dataString(msg);
			    logger.log(Logger::LogLevel::INFO, "Sending message from"+name_string);
			    logger.log(Logger::LogLevel::INFO, dataString);
			    memset(&data, 0, sizeof(data)); 
			    delete[] msg;
			}
			else{
			   puts("[ERROR] Not a vaild XML object\n");
			}
		}
		//MESSAGE RECIEVED
		if (FD_ISSET(clientfd, &ready_set)) {
			//Read message recieved into data buffer
			Rio_readlineb(&rio, data, MAXLINE);
			//Write message to output
                        if(data[0] == '<') {
			  Fputs(data, stdout);
			  string dataString(data);
			  logger.log(Logger::LogLevel::INFO, "[MESSAGE RECEIVED]"+dataString);
			  //Temporarily read an xml file to simulate reading an XML message
			  stringstream xmlStream(dataString);
			  string content;
			  content.assign((istreambuf_iterator<char>(xmlStream) ),
                			(istreambuf_iterator<char>()));

			  pid_t pid = fork();
			  if (pid == 0){
				cout << "Handling request in child process\n";
				parse_data(&content);
			  }

			  //Clear data buffer
			  memset(&data, 0, sizeof(data));
                        }
		}
	}
	Close(clientfd);
	exit(0);
}
