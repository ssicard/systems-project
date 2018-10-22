#include "IncidentInformation.h"
#include "MessageRecall.h"
#include "Funding.h"
#include "ResourceInformation.h"
#include "ResponseInformation.h"
#include "ContactInformationType.h"
#include <string>

#ifndef RESPONSETOREQUESTRESOURCE_H
#define RESPONSETOREQUESTRESOURCE_H

class ResponseToRequestResource {
public:
  ResponseToRequestResource(std::string MessageID = "", std::string SentDateTime = "", std::string MessageContentType = "",
                  std::string MessageDescription = "", std::string OriginatingMessageID = "") :
                  SentDateTime(SentDateTime), MessageContentType(MessageContentType),
                  MessageDescription(MessageDescription), OriginatingMessageID(OriginatingMessageID) {}

  ~ResponseToRequestResource() {}

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
  ResponseInformation response_info;
  ContactInformationType contact_info;
};

#endif /* RESPONSETOREQUESTRESOURCE_H */
