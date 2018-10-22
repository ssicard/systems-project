#include <iostream>
#include "translation-engine.h"

//very ugly hardcoded non portable
RequestResource TranslationEngine::xml_to_request_resource_msg(std::string id, const char * xml_str) {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(xml_str);

  if (!result) {
    std::cout << "parsed with errors: \n" << result.description() <<'\n';
  }

  RequestResource msg(id);

  pugi::xml_node req_res = doc.child("RequestResource");

  if(id != "") {
    msg.MessageID = std::string(req_res.child_value("MessageID"));
  }

  msg.SentDateTime = std::string(req_res.child_value("SentDateTime"));
  msg.MessageContentType = std::string(req_res.child_value("MessageContentType"));
  msg.MessageDescription = std::string(req_res.child_value("MessageDescription"));
  msg.OriginatingMessageID = std::string(req_res.child_value("MessageDescription"));
  msg.inc_info.IncidentID = std::string(req_res.child("IncidentInformation").child_value("IncidentID"));
  msg.inc_info.IncidentDescription = std::string(req_res.child("IncidentInformation").child_value("IncidentDescription"));
  msg.msg_rcl.RecalledMessageID = std::string(req_res.child("MessageRecall").child_value("RecalledMessageID"));
  msg.msg_rcl.RecallType = std::string(req_res.child("MessageRecall").child_value("RecallType"));
  msg.fund.FundCode = std::string(req_res.child("Funding").child_value("FundCode"));
  msg.fund.FundingInfo = std::string(req_res.child("Funding").child_value("FundingInfo"));
  msg.res_info.ResourceInfoElementID = std::string(req_res.child("ResourceInformation").child_value("ResourceInfoElementID"));
  msg.res_info.res.ResourceID = std::string(req_res.child("ResourceInformation").child("Resource").child_value("ResourceID"));
  msg.res_info.res.Name = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Name"));
  msg.res_info.res.TypeStructure = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeStructure"));
  msg.res_info.res.TypeInfo = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeInfo"));
  msg.res_info.res.Keyword = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Keyword"));
  msg.res_info.res.Description = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Description"));
  msg.res_info.res.Credentials = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Credentials"));
  msg.res_info.res.Certifications = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Certifications"));
  msg.res_info.res.SpecialRequirements = std::string(req_res.child("ResourceInformation").child("Resource").child_value("SpecialRequirements"));
  msg.res_info.assign_info.Quantity = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Quantity"));
  msg.res_info.assign_info.Restrictions = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Restrictions"));
  msg.res_info.assign_info.AnticipatedFunction = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("AnticipatedFunction"));
  msg.res_info.sched_info.ScheduleType = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("ScheduleType"));
  msg.res_info.sched_info.DateTime = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("DateTime"));
  msg.res_info.sched_info.Location = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("Location"));
  return msg;
}


ResponseToRequestResource TranslationEngine::xml_to_response_to_request_resource_msg(std::string id, const char * xml_str) {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(xml_str);

  if (!result) {
    std::cout << "parsed with errors: \n" << result.description() <<'\n';
  }

  ResponseToRequestResource msg(id);

  pugi::xml_node req_res = doc.child("ResponseToRequestResource");

  if(id != "") {
    msg.MessageID = std::string(req_res.child_value("MessageID"));
  }

  msg.SentDateTime = std::string(req_res.child_value("SentDateTime"));
  msg.MessageContentType = std::string(req_res.child_value("MessageContentType"));
  msg.MessageDescription = std::string(req_res.child_value("MessageDescription"));
  msg.OriginatingMessageID = std::string(req_res.child_value("MessageDescription"));
  msg.inc_info.IncidentID = std::string(req_res.child("IncidentInformation").child_value("IncidentID"));
  msg.inc_info.IncidentDescription = std::string(req_res.child("IncidentInformation").child_value("IncidentDescription"));
  msg.msg_rcl.RecalledMessageID = std::string(req_res.child("MessageRecall").child_value("RecalledMessageID"));
  msg.msg_rcl.RecallType = std::string(req_res.child("MessageRecall").child_value("RecallType"));
  msg.fund.FundCode = std::string(req_res.child("Funding").child_value("FundCode"));
  msg.fund.FundingInfo = std::string(req_res.child("Funding").child_value("FundingInfo"));
  msg.res_info.ResourceInfoElementID = std::string(req_res.child("ResourceInformation").child_value("ResourceInfoElementID"));
  msg.res_info.res.ResourceID = std::string(req_res.child("ResourceInformation").child("Resource").child_value("ResourceID"));
  msg.res_info.res.Name = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Name"));
  msg.res_info.res.TypeStructure = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeStructure"));
  msg.res_info.res.TypeInfo = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeInfo"));
  msg.res_info.res.Keyword = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Keyword"));
  msg.res_info.res.Description = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Description"));
  msg.res_info.res.Credentials = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Credentials"));
  msg.res_info.res.Certifications = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Certifications"));
  msg.res_info.res.SpecialRequirements = std::string(req_res.child("ResourceInformation").child("Resource").child_value("SpecialRequirements"));
  msg.res_info.assign_info.Quantity = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Quantity"));
  msg.res_info.assign_info.Restrictions = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Restrictions"));
  msg.res_info.assign_info.AnticipatedFunction = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("AnticipatedFunction"));
  msg.res_info.sched_info.ScheduleType = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("ScheduleType"));
  msg.res_info.sched_info.DateTime = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("DateTime"));
  msg.res_info.sched_info.Location = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("Location"));
  msg.response_info.PrecedingResourceInfoElementID = std::string(req_res.child("ResponseInformation").child_value("PrecedingResourceInfoElementID"));
  msg.response_info.ResponseType = std::string(req_res.child("ResponseInformation").child_value("ResponseType"));
  msg.response_info.ReasonCode = std::string(req_res.child("ResponseInformation").child_value("ReasonCode"));
  msg.response_info.ResponseReason = std::string(req_res.child("ResponseInformation").child_value("ResponseReason"));

  return msg;
}


//pugi::xml doesnt seem to have a good way to output the whole tree to a string
std::string TranslationEngine::request_resource_msg_to_xml(RequestResource msg) {
  std::string out;

  out.append("<RequestResource>\n");
  out.append("\t<MessageID>" + msg.MessageID + "</MessageID>\n");
  out.append("\t<SentDateTime>" + msg.SentDateTime + "</SentDateTime>\n");
  out.append("\t<MessageContentType>" + msg.MessageContentType + "</MessageContentType>\n");
  out.append("\t<MessageDescription>" + msg.MessageDescription + "</MessageDescription>\n");
  out.append("\t<OriginatingMessageID>" + msg.OriginatingMessageID + "</OriginatingMessageID>\n");
  out.append("\t<IncidentInformation>\n");
  out.append("\t\t<IncidentID>" + msg.inc_info.IncidentID + "</IncidentID>\n");
  out.append("\t\t<IncidentDescription>" + msg.inc_info.IncidentDescription + "</IncidentDescription>\n");
  out.append("\t</IncidentInformation>\n");
  out.append("\t<MessageRecall>\n");
  out.append("\t\t<RecalledMessageID>" + msg.msg_rcl.RecalledMessageID + "</RecalledMessageID>\n");
  out.append("\t\t<RecallType>" + msg.msg_rcl.RecallType + "</RecallType>\n");
  out.append("\t</MessageRecall>\n");
  out.append("\t<Funding>\n");
  out.append("\t\t<FundCode>" + msg.fund.FundCode + "</FundCode>\n");
  out.append("\t\t<FundingInfo>" + msg.fund.FundingInfo + "</FundingInfo>\n");
  out.append("\t</Funding>\n");
  out.append("\t<ResourceInformation>\n");
  out.append("\t\t<ResourceInfoElementID>" + msg.res_info.ResourceInfoElementID + "</ResourceInfoElementID>\n");
  out.append("\t\t<Resource>\n");
  out.append("\t\t\t<ResourceID>" + msg.res_info.res.ResourceID + "</ResourceID>\n");
  out.append("\t\t\t<Name>" + msg.res_info.res.Name + "</Name>\n");
  out.append("\t\t\t<TypeStructure>" + msg.res_info.res.TypeStructure + "</TypeStructure>\n");
  out.append("\t\t\t<TypeInfo>" + msg.res_info.res.TypeInfo + "</TypeInfo>\n");
  out.append("\t\t\t<Keyword>" + msg.res_info.res.Keyword + "</Keyword>\n");
  out.append("\t\t\t<Description>" + msg.res_info.res.Description + "</Description>\n");
  out.append("\t\t\t<Credentials>" + msg.res_info.res.Credentials + "</Credentials>\n");
  out.append("\t\t\t<Certifications>" + msg.res_info.res.Certifications + "</Certifications>\n");
  out.append("\t\t\t<SpecialRequirements>" + msg.res_info.res.SpecialRequirements + "</SpecialRequirements>\n");
  out.append("\t\t</Resource>\n");
  out.append("\t\t<AssignementInformation>\n");
  out.append("\t\t\t<Quantity>" + msg.res_info.assign_info.Quantity + "</Quantity>\n");
  out.append("\t\t\t<Restrictions>" + msg.res_info.assign_info.Restrictions + "</Restrictions>\n");
  out.append("\t\t\t<AnticipatedFunction>" + msg.res_info.assign_info.AnticipatedFunction + "</AnticipatedFunction>\n");
  out.append("\t\t</AssignmentInformation>\n");
  out.append("\t\t<ScheduleInformation>\n");
  out.append("\t\t\t<ScheduleType>" + msg.res_info.sched_info.ScheduleType + "</ScheduleType>\n");
  out.append("\t\t\t<DateTime>" + msg.res_info.sched_info.DateTime + "</DateTime>\n");
  out.append("\t\t\t<Location>" + msg.res_info.sched_info.Location + "</Location>\n");
  out.append("\t\t</ScheduleInformation>\n\t</ResourceInformation>\n</RequestResource>\n");

  return out;
}

std::string TranslationEngine::response_to_request_resource_msg_to_xml(ResponseToRequestResource msg) {
  std::string out;

  out.append("<RequestResource>\n");
  out.append("\t<MessageID>" + msg.MessageID + "</MessageID>\n");
  out.append("\t<SentDateTime>" + msg.SentDateTime + "</SentDateTime>\n");
  out.append("\t<MessageContentType>" + msg.MessageContentType + "</MessageContentType>\n");
  out.append("\t<MessageDescription>" + msg.MessageDescription + "</MessageDescription>\n");
  out.append("\t<OriginatingMessageID>" + msg.OriginatingMessageID + "</OriginatingMessageID>\n");
  out.append("\t<IncidentInformation>\n");
  out.append("\t\t<IncidentID>" + msg.inc_info.IncidentID + "</IncidentID>\n");
  out.append("\t\t<IncidentDescription>" + msg.inc_info.IncidentDescription + "</IncidentDescription>\n");
  out.append("\t</IncidentInformation>\n");
  out.append("\t<MessageRecall>\n");
  out.append("\t\t<RecalledMessageID>" + msg.msg_rcl.RecalledMessageID + "</RecalledMessageID>\n");
  out.append("\t\t<RecallType>" + msg.msg_rcl.RecallType + "</RecallType>\n");
  out.append("\t</MessageRecall>\n");
  out.append("\t<Funding>\n");
  out.append("\t\t<FundCode>" + msg.fund.FundCode + "</FundCode>\n");
  out.append("\t\t<FundingInfo>" + msg.fund.FundingInfo + "</FundingInfo>\n");
  out.append("\t</Funding>\n");
  out.append("\t<ResourceInformation>\n");
  out.append("\t\t<ResourceInfoElementID>" + msg.res_info.ResourceInfoElementID + "</ResourceInfoElementID>\n");
  out.append("\t\t<Resource>\n");
  out.append("\t\t\t<ResourceID>" + msg.res_info.res.ResourceID + "</ResourceID>\n");
  out.append("\t\t\t<Name>" + msg.res_info.res.Name + "</Name>\n");
  out.append("\t\t\t<TypeStructure>" + msg.res_info.res.TypeStructure + "</TypeStructure>\n");
  out.append("\t\t\t<TypeInfo>" + msg.res_info.res.TypeInfo + "</TypeInfo>\n");
  out.append("\t\t\t<Keyword>" + msg.res_info.res.Keyword + "</Keyword>\n");
  out.append("\t\t\t<Description>" + msg.res_info.res.Description + "</Description>\n");
  out.append("\t\t\t<Credentials>" + msg.res_info.res.Credentials + "</Credentials>\n");
  out.append("\t\t\t<Certifications>" + msg.res_info.res.Certifications + "</Certifications>\n");
  out.append("\t\t\t<SpecialRequirements>" + msg.res_info.res.SpecialRequirements + "</SpecialRequirements>\n");
  out.append("\t\t</Resource>\n");
  out.append("\t\t<AssignementInformation>\n");
  out.append("\t\t\t<Quantity>" + msg.res_info.assign_info.Quantity + "</Quantity>\n");
  out.append("\t\t\t<Restrictions>" + msg.res_info.assign_info.Restrictions + "</Restrictions>\n");
  out.append("\t\t\t<AnticipatedFunction>" + msg.res_info.assign_info.AnticipatedFunction + "</AnticipatedFunction>\n");
  out.append("\t\t</AssignmentInformation>\n");
  out.append("\t\t<ScheduleInformation>\n");
  out.append("\t\t\t<ScheduleType>" + msg.res_info.sched_info.ScheduleType + "</ScheduleType>\n");
  out.append("\t\t\t<DateTime>" + msg.res_info.sched_info.DateTime + "</DateTime>\n");
  out.append("\t\t\t<Location>" + msg.res_info.sched_info.Location + "</Location>\n");
  out.append("\t\t</ScheduleInformation>\n");
  out.append("\t</ResourceInformation>\n");
  out.append("\t<ResponseInformation>\n");
  out.append("\t\t<PrecedingResourceInfoElementID>" + msg.response_info.PrecedingResourceInfoElementID + "</PrecedingResourceInfoElementID>\n");
  out.append("\t\t<ResponseType>" + msg.response_info.ResponseType + "</ResponseType>\n");
  out.append("\t\t<ReasonCode>" + msg.response_info.ReasonCode + "</ReasonCode>\n");
  out.append("\t\t<ResponseReason>" + msg.response_info.ResponseReason + "</ResponseReason>\n");
  out.append("</RequestResource>\n");

  return out;
}


int main() {
  const char * msg = "<RequestResource>\n\
  <MessageID>fdfdf-342rwe-23drftg-e999</MessageID>\n\
  <SentDateTime>2323232455</SentDateTime>\n\
  <MessageContentType>RequestResource</MessageContentType>\n\
  <MessageDescription>joe</MessageDescription>\n\
  <OriginatingMessageID>0000-0000-0000-0000</OriginatingMessageID>\n\
  <IncidentInformation>\n\
    <IncidentID>001</IncidentID>\n\
    <IncidentDescription>Man some bad stuff happened</IncidentDescription>\n\
  </IncidentInformation>\n\
  <MessageRecall>\n\
    <RecalledMessageID>43r-f34-9j9-23e</RecalledMessageID>\n\
    <RecallType>URGENT</RecallType>\n\
  </MessageRecall>\n\
  <Funding>\n\
    <FundCode>FF998</FundCode>\n\
    <FundingInfo>Funded by government</FundingInfo>\n\
  </Funding>\n\
  <ResourceInformation>\n\
    <ResourceInfoElementID>1122-ff32d-f4f34f-g439j</ResourceInfoElementID>\n\
    <Resource>\n\
      <ResourceID>hello</ResourceID>\n\
      <Name>world</Name>\n\
      <TypeStructure>how</TypeStructure>\n\
      <TypeInfo>are</TypeInfo>\n\
      <Keyword>you</Keyword>\n\
      <Description>doing</Description>\n\
      <Credentials>today</Credentials>\n\
      <Certifications>?</Certifications>\n\
      <SpecialRequirements>ok</SpecialRequirements>\n\
    </Resource>\n\
    <AssignmentInformation>\n\
      <Quantity>3</Quantity>\n\
      <Restrictions>None</Restrictions>\n\
      <AnticipatedFunction>Relief Efforts</AnticipatedFunction>\n\
    </AssignmentInformation>\n\
    <ScheduleInformation>\n\
      <ScheduleType>EstimatedArrival</ScheduleType>\n\
      <DateTime>00/00/0000 0:00:0000</DateTime>\n\
      <Location>Here and there</Location>\n\
    </ScheduleInformation>\n\
  </ResourceInformation>\n\
</RequestResource>";

  TranslationEngine te;
  RequestResource test = te.xml_to_request_resource_msg("1", msg);


  std::cout << te.request_resource_msg_to_xml(test);
}
