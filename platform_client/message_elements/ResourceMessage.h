#include <string>
#include "SqlBase.h"
#include "IncidentInformation.h"
#include "MessageRecall.h"
#include "Funding.h"
#include "ContactInformationType.h"
#include "ResourceInformation.h"

#ifndef RESOURSEMESSAGE_H
#define RESOURSEMESSAGE_H

class ResourceMessage : public SqlBase
{
public:
	ResourceMessage(std::string MessageID = "", int SentDateTime = -1, std::string MessageContentType = "",
					std::string MessageDescription = "", std::string OriginatingMessageID = "",
					std::string PrecedingMessageID = "", std::string IncidentID = "", std::string RecalledMessageID = "",
					std::string FundCode = "", std::string ContactInformationID = "", std::string ResourceInfoElementID = "", std::string _SentDateTime = "", int _ContactInformationID = -1) :
					MessageID(MessageID), SentDateTime(SentDateTime), MessageContentType(MessageContentType),
					MessageDescription(MessageDescription), OriginatingMessageID(OriginatingMessageID),
					PrecedingMessageID(PrecedingMessageID), IncidentID(IncidentID),
					RecalledMessageID(RecalledMessageID), FundCode(FundCode), ContactInformationID(ContactInformationID),
					ResourceInfoElementID(ResourceInfoElementID),
				    _SentDateTime{_SentDateTime},
					_ContactInformationID{_ContactInformationID} {}
	~ResourceMessage() {}
	void getFromDatabase();
	void insertIntoDatabase();
	bool areFieldsValid();

	std::string MessageID;
	int SentDateTime;
	std::string MessageContentType;
	std::string MessageDescription;
	std::string OriginatingMessageID;
	std::string PrecedingMessageID;
	std::string IncidentID;
	std::string RecalledMessageID;
	std::string FundCode;
	std::string ContactInformationID;
	std::string ResourceInfoElementID;
	
	IncidentInformation _IncidentInformation;
	MessageRecall _MessageRecall;
	Funding _Funding;
	ContactInformationType _ContactInformationType;
	ResourceInformation _ResourceInformation;

	// TODO: Change this
	std::string _SentDateTime;
	int _ContactInformationID;
};
#endif /* RESOURSEMESSAGE_H */
