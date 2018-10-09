
#include <iostream>

#include "./dependencies/pugixml/pugixml.hpp"

using namespace std;
typedef pugi::xml_node Node;
typedef pugi::xml_document Document;

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




int main()
{ 
	pugi::xml_document doc;
	pugi::xml_document doc2;


	CreateRequestResourceElement(&doc, "fdfdf-342rwe-23drftg-e999", "2323232455", "RequestResource", "Described here...", "0000-0000-0000-0000");
	CreateResponseToRequestResourceElement(&doc2, "fdfdf-342rwe-23drftg-e999", "2323232455", "ResponseToRequestResource", "Described here...", "0000-0000-0000-0000", "0000-0000-0000-0000");

	doc.print(cout);
	doc2.print(cout);
	

}

