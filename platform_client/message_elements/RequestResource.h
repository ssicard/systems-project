#include "IncidentInformation.h"
#include "MessageRecall.h"
#include "Funding.h"
#include "ResourceInformation.h"
#include "ContactInformationType.h"
#include <string>

#ifndef REQUESTRESOURCE_H
#define REQUESTRESOURCE_H

class RequestResource {
public:
  RequestResource(std::string MessageID = "", std::string SentDateTime = "", std::string MessageContentType = "",
                  std::string MessageDescription = "", std::string OriginatingMessageID = ""):
                  MessageID(std::move(MessageID)), SentDateTime(std::move(SentDateTime)), MessageContentType(std::move(MessageContentType)),
                  MessageDescription(std::move(MessageDescription)), OriginatingMessageID(std::move(OriginatingMessageID)) {}

  ~RequestResource() {}

  std::string MessageID;
  std::string SentDateTime;
  std::string MessageContentType;
  std::string MessageDescription;
  std::string OriginatingMessageID;
  std::string PrecedingMessageID;

  IncidentInformation inc_info;
  MessageRecall msg_rcl;
  Funding fund;
  ResourceInformation res_info;
  ContactInformationType contact_info;
};
#endif /* REQUESTRESOURCE_H */

