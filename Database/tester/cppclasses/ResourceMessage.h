#ifndef RESOURCE_MESSAGE_H
#define RESOURCE_MESSAGE_H

#include <string>
#include "SqlBase.h"
#include "IncidentInformation.h"
#include "MessageRecall.h"
#include "Funding.h"
#include "ContactInformationType.h"
#include "ResourceInformation.h"

class ResourceMessage: public SqlBase
{
public:
	ResourceMessage(std::string messageID);
	ResourceMessage();
	~ResourceMessage();
	void getFromDatabase();
	void insertIntoDatabase();
	bool areFieldsValid();

	std::string MessageID;
	std::string SentDateTime;
	std::string MessageContentType;
	std::string MessageDescription;
	std::string OriginatingMessageID;
	std::string PrecedingMessageID;

	IncidentInformation _IncidentInformation;
	MessageRecall _MessageRecall;
	Funding _Funding;
	ContactInformationType _ContactInformationType;
	ResourceInformation _ResourceInformation;

	std::string IncidentID;
	std::string RecalledMessageID;
	std::string FundCode;
	int ContactInformationID;
	std::string ResourceInfoElementID;
};

#endif
