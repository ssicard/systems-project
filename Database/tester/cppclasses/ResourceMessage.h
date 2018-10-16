#include <string>
#pragma once
using namespace std;
class ResourceMessage
{
public:
	ResourceMessage(string messageID);
	~ResourceMessage();
	string MessageID;
	int SentDateTime;
	string MessageContentType;
	string MessageDescription;
	string OriginatingMessageID;
	string PrecedingMessageID;

	IncidentInformation IncidentInformation;
	MessageRecall MessageRecall;
	Funding Funding;
	ContactInformation ContactInformation;
	ResourceInformation ResourceInformation;

	string IncidentID;
	string RecalledMessageID;
	string FundCode;
	string ContactInformationID;
	string ResourceInfoElementID;
};

