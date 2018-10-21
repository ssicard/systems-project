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
  ResponseToRequestResource(std::string MesssageID, std::string SentDateTime = "", std::string MessageContentType = "",
                  std::string MessageDescription = "", std::string OriginatingMessageID = ""):
                  SentDateTime(SentDateTime), MessageContentType(MessageContentType),
                  MessageDescription(MessageDescription), OriginatingMessageID(OriginatingMessageID) {}

  ~RequestResource() {}

  std::string MessageID;
  std::string SentDateTime;
  std::string MessageContentType;
  std::string MessageDescription;
  std::string OriginatingMessageID;

  IncidentInformation inc_info;
  MessageRecall msg_rcl;
  Funding fund;
  ResourceInformation rsrc_info;
  ResponseInformation response_info;
  ContactInformationType contact_info;
};

#endif /* RESPONSETOREQUESTRESOURCE_H */
