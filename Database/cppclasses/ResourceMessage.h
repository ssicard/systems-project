#include <string>

#ifndef RESOURCEMESSAGE_H
#define RESOURCEMESSAGE_H

class ResourceMessage {
public:
  ResourceMessage() {}
  ResourceMessage(std::string MessageID, long SentDateTime=0L, std::string MessageContentType="",
                  std::string MessageDescription, std::string OriginatingMessageID="", std::string PrecedingMessageID="",
                  std::string IncidentID="", std::string RecalledMessageID="", std::string FundCode="",
                  std::string ContactInformationID="", std::string ResourceInfoElementID="") :
                  MessageID(MessageID), SentDateTime(SentDateTime), MessageContentType(MessageContentType),
                  MessageDescription(MessageDescription), OriginatingMessageID(OriginatingMessageID), PrecedingMessageID(PrecedingMessageID),
                  IncidentID(IncidentID), RecalledMessageID(RecalledMessageID), FundCode(FundCode),
                  ContactInformationID(ContactInformationID), ResourceInfoElementID(ResourceInfoElementID) {}

  ~ResourceMessage() {}

  std::string MessageID;
  long SentDateTime;
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

#endif /* RESOURCEMESSAGE_H */
