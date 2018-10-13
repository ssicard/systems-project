
#include <iostream>
#include "./csapp/csapp.h"
#include "../logger/logger.cpp"
#include "./dependencies/pugixml/pugixml.hpp"
#include <sstream>
#include <string>


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
// end::code[]

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


string node_to_string(pugi::xml_node *node)
{
	xml_string_writer writer;
	node->print(writer);

	return writer.result;
}

//End Source

void append_data_to_node(Node *node, string title, string data) {
	node->append_child(title.c_str()).append_child(pugi::node_pcdata).set_value(data.c_str());
}

void AppendResourceElement(Node *docNode, string resourceID, string Name, string TypeStructure, string TypeInfo, string keyword, string description, string credentials, string certifications, string SpecialReqs) {
	Node node = docNode->append_child("Resource");
	append_data_to_node(&node, "ResourceID", resourceID);
	append_data_to_node(&node, "Name", Name);
	append_data_to_node(&node, "TypeStructure", TypeStructure);
	append_data_to_node(&node, "TypeInfo", TypeInfo);
	append_data_to_node(&node, "Keyword", keyword);
	append_data_to_node(&node, "Description", description);
	append_data_to_node(&node, "Credentials", credentials);
	append_data_to_node(&node, "Certifications", certifications);
	append_data_to_node(&node, "SpecialRequirements", SpecialReqs);
	
}

void AppendFundingElement(Node *docNode, string FundCode, string FundingInfo) {
	Node node = docNode->append_child("Funding");
	append_data_to_node(&node, "FundCode"   ,FundCode);
	append_data_to_node(&node, "FundingInfo",FundingInfo);
}

void AppendIncidentElement(Node *docNode, string IncidentID, string IncidentDescription) {
	Node node = docNode->append_child("IncidentInformation");
	append_data_to_node(&node, "IncidentID",IncidentID);
	append_data_to_node(&node, "IncidentDescription",IncidentDescription);
}

void AppendMessageRecall(Node *docNode, string messageRecallId, string recallType) {
	Node node = docNode->append_child("MessageRecall");
	append_data_to_node(&node, "RecalledMessageID", messageRecallId);
	append_data_to_node(&node, "RecallType", recallType);
}

void AppendAssignmentElement(Node *docNode, string Quantity, string Restrictions, string AnticipatedFunction) {
	Node node = docNode->append_child("AssignmentInfo");
	append_data_to_node(&node, "Quantity", Quantity);
	append_data_to_node(&node, "Restrictions", Restrictions);
	append_data_to_node(&node, "AnticipatedFunction", AnticipatedFunction);
}

void AppendScheduleInformationElement(Node *docNode, string scheduleType, string datetime, string location) {
	Node node = docNode->append_child("ScheduleInformation");
	append_data_to_node(&node, "ScheduleType", scheduleType);
	append_data_to_node(&node, "DateTime", datetime);
	append_data_to_node(&node, "Location", location);
}

void AppendResourceInformationElement(Node *docNode, string ResourceInfoElementID) {
	Node node = docNode->append_child("ResourceInformation");
	append_data_to_node(&node, "ResourceInformationID",ResourceInfoElementID);
	AppendResourceElement(&node, "hello", "world", "how", "are", "you", "doing", "today", "?", "ok");
	AppendAssignmentElement(&node, "3", "None", "Relief Efforts");
	AppendScheduleInformationElement(&node, "EstimatedArrival", "00/00/0000 0:00:0000", "Here and there");
}

void CreateRequestResourceElement(Document *doc, string MessageID, string SentDateTime, string MessageContentType, string MessageDescription, string OriginatingMessageID) {
	Node node = doc->append_child("RequestResource");
	append_data_to_node(&node, "MessageID", MessageID);
	append_data_to_node(&node, "SentDateTime", SentDateTime);
	append_data_to_node(&node, "MessageContentType", MessageContentType);
	append_data_to_node(&node, "MessageDescription", MessageDescription);
	append_data_to_node(&node, "OriginatingMessageID", OriginatingMessageID);
	AppendIncidentElement(&node, "001", "Man some bad stuff happened");
	AppendMessageRecall(&node, "43r-f34-9j9-23e", "URGENT");
	AppendFundingElement(&node, "FF998", "Funded by government");
	
	AppendResourceInformationElement(&node, "1122-ff32d-f4f34f-g439j");
	
}

void CreateResponseToRequestResourceElement(Document *doc, string MessageID, string SentDateTime, string MessageContentType, string MessageDescription, string OriginatingMessageID, string precedingMessageId) {
	Node node = doc->append_child("ResponseToRequestResource");
	append_data_to_node(&node, "MessageID",MessageID);
	append_data_to_node(&node, "SentDateTime",SentDateTime);
	append_data_to_node(&node, "MessageContentType",MessageContentType);
	append_data_to_node(&node, "MessageDescription", MessageDescription);
	append_data_to_node(&node, "OriginatingMessageID",OriginatingMessageID);
	append_data_to_node(&node, "PrecedingMessageID", precedingMessageId);
	AppendIncidentElement(&node, "0002", "Describing the incident here right now.");
	AppendMessageRecall(&node, "4234-234-5345-123", "Urgent");
	AppendFundingElement(&node, "FF990", "Funding info here");
	AppendResourceInformationElement(&node, "0001");
}




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

	pugi::xml_document doc;
	//Set the description to the third argument for now..
	CreateRequestResourceElement(&doc, "fdfdf-342rwe-23drftg-e999", "2323232455", "RequestResource", argv[3], "0000-0000-0000-0000");

	clientfd = Open_clientfd(host, port); /* Open client for connection */
	Rio_readinitb(&rio, clientfd); /* initialize rio */

	FD_ZERO(&ready_set); /* Clearing ready_set*/
	FD_ZERO(&read_set); /* clearing read_set */
	FD_SET(STDIN_FILENO, &read_set); /* Adding stdin to read_set */
	FD_SET(clientfd, &read_set); /* setting client descriptors to read_set */

	while (1) {
		ready_set = read_set;
		/* waiting for event */
		select(clientfd + 1, &ready_set, NULL, NULL, NULL);
		if (FD_ISSET(STDIN_FILENO, &ready_set)) {
			memset(&data, 0, sizeof(data));
			
			/*getting the inputs from stdin */
			Fgets(buf, MAXLINE, stdin);
			if (buf[0] == '\\') {
				if (buf[1] == 'q') {
					printf("\\q innitiated, are you sure you want to quit session");
					printf("(enter c to continue, type any other keys to quit)?\n");
					Fgets(buf, MAXLINE, stdin);
					printf("%c\n", buf[0]);
					if (buf[0] == 'c') {
						printf("<<<---Continuing Session--->>>\n");
						continue;
					}
					else {
						printf("<<<---Session Terminating--->>>\n");
						// TODO: send log out message
						exit(0);
					}
				}
			}
			buf[strlen(buf) - 1] = '\0';
			
			Node rootNode = doc.first_child();
			std::string send_this = node_to_string(&rootNode);
			//Remove newline characters
			send_this.erase(
				std::remove(send_this.begin(), send_this.end(), '\n'), 
				send_this.end());
			send_this += "\n";
			char char_star[send_this.length()];
			strcpy(char_star, send_this.c_str());
			Rio_writen(clientfd, char_star, strlen(char_star));
			memset(&data, 0, sizeof(data));
		}
		if (FD_ISSET(clientfd, &ready_set)) {
			Rio_readlineb(&rio, data, MAXLINE);
			Fputs(data, stdout);
			memset(&data, 0, sizeof(data));
		}
	}
	Close(clientfd);
	exit(0);
}