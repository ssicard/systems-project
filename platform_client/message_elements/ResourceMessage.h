#include <string>

#ifndef RESOURSEMESSAGE_H
#define RESOURSEMESSAGE_H

class ResourceMessage {
public:
	ResourceMessage(std::string MessageID = "", std::string SentDateTime = "", std::string MessageContentType = "",
					std::string MessageDescription = "", std::string OriginatingMessageID = "",
					std::string PrecedingMessageID = "", std::string IncidentID = "", std::string RecalledMessageID = "",
					std::string FundCode = "", std::string ContactInformationID = "", std::string ResourceInfoElementID = "") :
					MessageID(MessageID), SentDateTime(SentDateTime), MessageContentType(MessageContentType),
					MessageDescription(MessageDescription), OriginatingMessageID(OriginatingMessageID),
					PrecedingMessageID(PrecedingMessageID), IncidentID(IncidentID),
					RecalledMessageID(RecalledMessageID), FundCode(FundCode), ContactInformationID(ContactInformationID),
					ResourceInfoElementID(ResourceInfoElementID) {}
	~ResourceMessage() {}

	std::string MessageID;
	std::string SentDateTime;
	std::string MessageContentType;
	std::string MessageDescription;
	std::string OriginatingMessageID;
	std::string PrecedingMessageID;
	std::string IncidentID;
	std::string RecalledMessageID;
	std::string FundCode;
	std::string ContactInformationID;
	std::string ResourceInfoElementID;
};
#endif /* RESOURSEMESSAGE_H */
