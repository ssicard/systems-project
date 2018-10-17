#include <string>
#pragma once
using namespace std;
#include "IncidentInformation.h"
#include "MessageRecall.h"
#include "Funding.h"
#include "ContactInformationType.h"
#include "ResourceInformation.h"
class ResourceMessage: public SqlBase
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

	IncidentInformation _IncidentInformation;
	MessageRecall _MessageRecall;
	Funding _Funding;
	ContactInformationType _ContactInformationType;
	ResourceInformation _ResourceInformation;

	string IncidentID;
	string RecalledMessageID;
	string FundCode;
	string ContactInformationID;
	string ResourceInfoElementID;
};

