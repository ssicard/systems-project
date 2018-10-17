#include "IncidentInformation.h"
#include "MessageRecall.h"
#include "Funding.h"
#include "ResourceInformation.h"
#include "ResponseInformation.h"
#include "ContactInformationType.h"
#include <string>

#ifndef REQUESTRESOURCE_H
#define REQUESTRESOURCE_H

class RequestResource {
  RequestResource(IncidentInformation inc_info, MessageRecall msg_rcl,
                  Funding fund, ResourceInformation rsrc_info, ResponseInformation response_info, ContactInformationType contact_info,
                  std::string MesssageID, std::string SentDateTime = "", std::string MessageContentType = "",
                  std::string MessageDescription = "", std::string OriginatingMessageID = ""):
                  inc_info(inc_info), msg_rcl(msg_rcl), fund(fund), rsrc_info(rsrc_info), response_info(response_info), contact_info(contact_info) {}

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

#endif /* REQUESTRESOURCE_H */
