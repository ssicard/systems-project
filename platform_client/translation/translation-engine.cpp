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

  if(id == "") {
    msg.MessageID = std::string(req_res.child_value("MessageID"));
  }

  msg.SentDateTime = std::string(req_res.child_value("SentDateTime"));
  msg.MessageContentType = std::string(req_res.child_value("MessageContentType"));
  msg.MessageDescription = std::string(req_res.child_value("MessageDescription"));
  msg.OriginatingMessageID = std::string(req_res.child_value("OriginatingMessageID"));
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

  if(id == "") {
    msg.MessageID = std::string(req_res.child_value("MessageID"));
  }

  msg.SentDateTime = std::string(req_res.child_value("SentDateTime"));
  msg.MessageContentType = std::string(req_res.child_value("MessageContentType"));
  msg.MessageDescription = std::string(req_res.child_value("MessageDescription"));
  msg.OriginatingMessageID = std::string(req_res.child_value("OriginatingMessageID"));
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


RequestResource TranslationEngine::json_to_request_resource_msg(std::string id, const char * json_str) {
  std::string cpp_json_str(json_str);
  RequestResource msg(id);

  auto json_obj = nlohmann::json::parse(cpp_json_str);
  auto req_res = json_obj["RequestResource"];
  if(id == "") {
    msg.MessageID = req_res["MessageID"] == nullptr ? "" : req_res["MessageID"];
  }

  msg.SentDateTime = req_res["SentDateTime"] == nullptr ? "" : req_res["SentDateTime"];
  msg.MessageContentType = req_res["MessageContentType"] == nullptr ? "" : req_res["MessageContentType"];
  msg.MessageDescription = req_res["MessageDescription"] == nullptr ? "" : req_res["MessageDescription"];
  msg.OriginatingMessageID = req_res["OriginatingMessageID"] == nullptr ? "" : req_res["OriginatingMessageID"];
  msg.inc_info.IncidentID = req_res["IncidentInformation"]["IncidentID"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentID"];
  msg.inc_info.IncidentDescription = req_res["IncidentInformation"]["IncidentDescription"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentDescription"];
  msg.msg_rcl.RecalledMessageID = req_res["MessageRecall"]["RecalledMessageID"] == nullptr ? "" : req_res["MessageRecall"]["RecalledMessageID"];
  msg.msg_rcl.RecallType = req_res["MessageRecall"]["RecallType"] == nullptr ? "" : req_res["MessageRecall"]["RecallType"];
  msg.fund.FundCode = req_res["Funding"]["FundCode"] == nullptr ? "" : req_res["Funding"]["FundCode"];
  msg.fund.FundingInfo = req_res["Funding"]["FundingInfo"] == nullptr ? "" : req_res["Funding"]["FundingInfo"];
  msg.res_info.ResourceInfoElementID = req_res["ResourceInformation"]["Resource"]["ResourceInfoElementID"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceInfoElementID"];
  msg.res_info.res.ResourceID = req_res["ResourceInformation"]["Resource"]["ResourceID"]  == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceID"];
  msg.res_info.res.Name = req_res["ResourceInformation"]["Resource"]["Name"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Name"];
  msg.res_info.res.TypeStructure = req_res["ResourceInformation"]["Resource"]["TypeStructure"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeStructure"];
  msg.res_info.res.TypeInfo = req_res["ResourceInformation"]["Resource"]["TypeInfo"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeInfo"];
  msg.res_info.res.Keyword = req_res["ResourceInformation"]["Resource"]["Keyword"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Keyword"];
  msg.res_info.res.Description = req_res["ResourceInformation"]["Resource"]["Description"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Description"];
  msg.res_info.res.Credentials = req_res["ResourceInformation"]["Resource"]["Credentials"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Credentials"];
  msg.res_info.res.Certifications = req_res["ResourceInformation"]["Resource"]["Certifications"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Certifications"];
  msg.res_info.res.SpecialRequirements = req_res["ResourceInformation"]["Resource"]["SpecialRequirements"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["SpecialRequirements"];
  msg.res_info.assign_info.Quantity = req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"];
  msg.res_info.assign_info.Restrictions = req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"];
  msg.res_info.assign_info.AnticipatedFunction = req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"];
  msg.res_info.sched_info.ScheduleType = req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"];
  msg.res_info.sched_info.DateTime = req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"];
  msg.res_info.sched_info.Location = req_res["ResourceInformation"]["ScheduleInformation"]["Location"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["Location"];

  return msg;
}


ResponseToRequestResource TranslationEngine::json_to_response_to_request_resource_msg(std::string id, const char * json_str) {
  std::string cpp_json_str(json_str);
  ResponseToRequestResource msg(id);

  auto json_obj = nlohmann::json::parse(cpp_json_str);
  auto req_res = json_obj["ResponseToRequestResource"];
  if(id == "") {
    msg.MessageID = req_res["MessageID"] == nullptr ? "" : req_res["MessageID"];
  }

  msg.SentDateTime = req_res["SentDateTime"] == nullptr ? "" : req_res["SentDateTime"];
  msg.MessageContentType = req_res["MessageContentType"] == nullptr ? "" : req_res["MessageContentType"];
  msg.MessageDescription = req_res["MessageDescription"] == nullptr ? "" : req_res["MessageDescription"];
  msg.OriginatingMessageID = req_res["OriginatingMessageID"] == nullptr ? "" : req_res["OriginatingMessageID"];
  msg.inc_info.IncidentID = req_res["IncidentInformation"]["IncidentID"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentID"];
  msg.inc_info.IncidentDescription = req_res["IncidentInformation"]["IncidentDescription"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentDescription"];
  msg.msg_rcl.RecalledMessageID = req_res["MessageRecall"]["RecalledMessageID"] == nullptr ? "" : req_res["MessageRecall"]["RecalledMessageID"];
  msg.msg_rcl.RecallType = req_res["MessageRecall"]["RecallType"] == nullptr ? "" : req_res["MessageRecall"]["RecallType"];
  msg.fund.FundCode = req_res["Funding"]["FundCode"] == nullptr ? "" : req_res["Funding"]["FundCode"];
  msg.fund.FundingInfo = req_res["Funding"]["FundingInfo"] == nullptr ? "" : req_res["Funding"]["FundingInfo"];
  msg.res_info.ResourceInfoElementID = req_res["ResourceInformation"]["Resource"]["ResourceInfoElementID"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceInfoElementID"];
  msg.res_info.res.ResourceID = req_res["ResourceInformation"]["Resource"]["ResourceID"]  == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceID"];
  msg.res_info.res.Name = req_res["ResourceInformation"]["Resource"]["Name"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Name"];
  msg.res_info.res.TypeStructure = req_res["ResourceInformation"]["Resource"]["TypeStructure"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeStructure"];
  msg.res_info.res.TypeInfo = req_res["ResourceInformation"]["Resource"]["TypeInfo"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeInfo"];
  msg.res_info.res.Keyword = req_res["ResourceInformation"]["Resource"]["Keyword"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Keyword"];
  msg.res_info.res.Description = req_res["ResourceInformation"]["Resource"]["Description"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Description"];
  msg.res_info.res.Credentials = req_res["ResourceInformation"]["Resource"]["Credentials"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Credentials"];
  msg.res_info.res.Certifications = req_res["ResourceInformation"]["Resource"]["Certifications"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Certifications"];
  msg.res_info.res.SpecialRequirements = req_res["ResourceInformation"]["Resource"]["SpecialRequirements"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["SpecialRequirements"];
  msg.res_info.assign_info.Quantity = req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"];
  msg.res_info.assign_info.Restrictions = req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"];
  msg.res_info.assign_info.AnticipatedFunction = req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"];
  msg.res_info.sched_info.ScheduleType = req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"];
  msg.res_info.sched_info.DateTime = req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"];
  msg.res_info.sched_info.Location = req_res["ResourceInformation"]["ScheduleInformation"]["Location"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["Location"];
  msg.response_info.PrecedingResourceInfoElementID = req_res["ResponseInformation"]["PrecedingResourceInfoElementID"] == nullptr ? "" : req_res["ResponseInformation"]["PrecedingResourceInfoElementID"];
  msg.response_info.ResponseType = req_res["ResponseInformation"]["ResponseType"] == nullptr ? "" : req_res["ResponseInformation"]["ResponseType"];
  msg.response_info.ReasonCode = req_res["ResponseInformation"]["ReasonCode"] == nullptr ? "" :req_res["ResponseInformation"]["ReasonCode"];
  msg.response_info.ResponseReason = req_res["ResponseInformation"]["ResponseReason"] == nullptr ? "" : req_res["ResponseInformation"]["ResponseReason"];

  return msg;
}


//pugi::xml doesnt seem to have a good way to output the whole tree to a string
std::string TranslationEngine::request_resource_msg_to_xml(RequestResource msg) {
  std::string out;

  out.append("<RequestResource>");
  out.append("<MessageID>" + msg.MessageID + "</MessageID>");
  out.append("<SentDateTime>" + msg.SentDateTime + "</SentDateTime>");
  out.append("<MessageContentType>" + msg.MessageContentType + "</MessageContentType>");
  out.append("<MessageDescription>" + msg.MessageDescription + "</MessageDescription>");
  out.append("<OriginatingMessageID>" + msg.OriginatingMessageID + "</OriginatingMessageID>");
  out.append("<IncidentInformation>");
  out.append("<IncidentID>" + msg.inc_info.IncidentID + "</IncidentID>");
  out.append("<IncidentDescription>" + msg.inc_info.IncidentDescription + "</IncidentDescription>");
  out.append("</IncidentInformation>");
  out.append("<MessageRecall>");
  out.append("<RecalledMessageID>" + msg.msg_rcl.RecalledMessageID + "</RecalledMessageID>");
  out.append("<RecallType>" + msg.msg_rcl.RecallType + "</RecallType>");
  out.append("</MessageRecall>");
  out.append("<Funding>");
  out.append("<FundCode>" + msg.fund.FundCode + "</FundCode>");
  out.append("<FundingInfo>" + msg.fund.FundingInfo + "</FundingInfo>");
  out.append("</Funding>");
  out.append("<ResourceInformation>");
  out.append("<ResourceInfoElementID>" + msg.res_info.ResourceInfoElementID + "</ResourceInfoElementID>");
  out.append("<Resource>");
  out.append("<ResourceID>" + msg.res_info.res.ResourceID + "</ResourceID>");
  out.append("<Name>" + msg.res_info.res.Name + "</Name>");
  out.append("<TypeStructure>" + msg.res_info.res.TypeStructure + "</TypeStructure>");
  out.append("<TypeInfo>" + msg.res_info.res.TypeInfo + "</TypeInfo>");
  out.append("<Keyword>" + msg.res_info.res.Keyword + "</Keyword>");
  out.append("<Description>" + msg.res_info.res.Description + "</Description>");
  out.append("<Credentials>" + msg.res_info.res.Credentials + "</Credentials>");
  out.append("<Certifications>" + msg.res_info.res.Certifications + "</Certifications>");
  out.append("<SpecialRequirements>" + msg.res_info.res.SpecialRequirements + "</SpecialRequirements>");
  out.append("</Resource>");
  out.append("<AssignmentInformation>");
  out.append("<Quantity>" + msg.res_info.assign_info.Quantity + "</Quantity>");
  out.append("<Restrictions>" + msg.res_info.assign_info.Restrictions + "</Restrictions>");
  out.append("<AnticipatedFunction>" + msg.res_info.assign_info.AnticipatedFunction + "</AnticipatedFunction>");
  out.append("</AssignmentInformation>");
  out.append("<ScheduleInformation>");
  out.append("<ScheduleType>" + msg.res_info.sched_info.ScheduleType + "</ScheduleType>");
  out.append("<DateTime>" + msg.res_info.sched_info.DateTime + "</DateTime>");
  out.append("<Location>" + msg.res_info.sched_info.Location + "</Location>");
  out.append("</ScheduleInformation></ResourceInformation></RequestResource>");

  return out;
}

std::string TranslationEngine::response_to_request_resource_msg_to_xml(ResponseToRequestResource msg) {
  std::string out;

  out.append("<RequestResource>");
  out.append("<MessageID>" + msg.MessageID + "</MessageID>");
  out.append("<SentDateTime>" + msg.SentDateTime + "</SentDateTime>");
  out.append("<MessageContentType>" + msg.MessageContentType + "</MessageContentType>");
  out.append("<MessageDescription>" + msg.MessageDescription + "</MessageDescription>");
  out.append("<OriginatingMessageID>" + msg.OriginatingMessageID + "</OriginatingMessageID>");
  out.append("<IncidentInformation>");
  out.append("<IncidentID>" + msg.inc_info.IncidentID + "</IncidentID>");
  out.append("<IncidentDescription>" + msg.inc_info.IncidentDescription + "</IncidentDescription>");
  out.append("</IncidentInformation>");
  out.append("<MessageRecall>");
  out.append("<RecalledMessageID>" + msg.msg_rcl.RecalledMessageID + "</RecalledMessageID>");
  out.append("<RecallType>" + msg.msg_rcl.RecallType + "</RecallType>");
  out.append("</MessageRecall>");
  out.append("<Funding>");
  out.append("<FundCode>" + msg.fund.FundCode + "</FundCode>");
  out.append("<FundingInfo>" + msg.fund.FundingInfo + "</FundingInfo>");
  out.append("</Funding>");
  out.append("<ResourceInformation>");
  out.append("<ResourceInfoElementID>" + msg.res_info.ResourceInfoElementID + "</ResourceInfoElementID>");
  out.append("<Resource>");
  out.append("<ResourceID>" + msg.res_info.res.ResourceID + "</ResourceID>");
  out.append("<Name>" + msg.res_info.res.Name + "</Name>");
  out.append("<TypeStructure>" + msg.res_info.res.TypeStructure + "</TypeStructure>");
  out.append("<TypeInfo>" + msg.res_info.res.TypeInfo + "</TypeInfo>");
  out.append("<Keyword>" + msg.res_info.res.Keyword + "</Keyword>");
  out.append("<Description>" + msg.res_info.res.Description + "</Description>");
  out.append("<Credentials>" + msg.res_info.res.Credentials + "</Credentials>");
  out.append("<Certifications>" + msg.res_info.res.Certifications + "</Certifications>");
  out.append("<SpecialRequirements>" + msg.res_info.res.SpecialRequirements + "</SpecialRequirements>");
  out.append("</Resource>");
  out.append("<AssignementInformation>");
  out.append("<Quantity>" + msg.res_info.assign_info.Quantity + "</Quantity>");
  out.append("<Restrictions>" + msg.res_info.assign_info.Restrictions + "</Restrictions>");
  out.append("<AnticipatedFunction>" + msg.res_info.assign_info.AnticipatedFunction + "</AnticipatedFunction>");
  out.append("</AssignmentInformation>");
  out.append("<ScheduleInformation>");
  out.append("<ScheduleType>" + msg.res_info.sched_info.ScheduleType + "</ScheduleType>");
  out.append("<DateTime>" + msg.res_info.sched_info.DateTime + "</DateTime>");
  out.append("<Location>" + msg.res_info.sched_info.Location + "</Location>");
  out.append("</ScheduleInformation>");
  out.append("</ResourceInformation>");
  out.append("<ResponseInformation>");
  out.append("<PrecedingResourceInfoElementID>" + msg.response_info.PrecedingResourceInfoElementID + "</PrecedingResourceInfoElementID>");
  out.append("<ResponseType>" + msg.response_info.ResponseType + "</ResponseType>");
  out.append("<ReasonCode>" + msg.response_info.ReasonCode + "</ReasonCode>");
  out.append("<ResponseReason>" + msg.response_info.ResponseReason + "</ResponseReason>");
  out.append("</RequestResource>");

  return out;
}

std::string TranslationEngine::request_resource_msg_to_json(RequestResource msg) {
  nlohmann::json j;

  j["RequestResource"]["SentDateTime"] = msg.SentDateTime;
  j["RequestResource"]["MessageContentType"] = msg.MessageContentType;
  j["RequestResource"]["MessageDescription"] = msg.MessageDescription;
  j["RequestResource"]["OriginatingMessageID"] = msg.OriginatingMessageID;
  j["RequestResource"]["IncidentInformation"]["IncidentID"] = msg.inc_info.IncidentID;
  j["RequestResource"]["IncidentInformation"]["IncidentDescription"] = msg.inc_info.IncidentDescription;
  j["RequestResource"]["MessageRecall"]["RecalledMessageID"] = msg.msg_rcl.RecalledMessageID;
  j["RequestResource"]["MessageRecall"]["RecallType"] = msg.msg_rcl.RecallType;
  j["RequestResource"]["Funding"]["FundCode"] = msg.fund.FundCode;
  j["RequestResource"]["Funding"]["FundingInfo"] = msg.fund.FundingInfo;
  j["RequestResource"]["ResourceInformation"]["ResourceInfoElementID"] = msg.res_info.ResourceInfoElementID;
  j["RequestResource"]["ResourceInformation"]["Resource"]["ResourceID"] = msg.res_info.res.ResourceID;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Name"] = msg.res_info.res.Name;
  j["RequestResource"]["ResourceInformation"]["Resource"]["TypeStructure"] = msg.res_info.res.TypeStructure;
  j["RequestResource"]["ResourceInformation"]["Resource"]["TypeInfo"] = msg.res_info.res.TypeInfo;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Keyword"] = msg.res_info.res.Keyword;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Description"] = msg.res_info.res.Description;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Credentials"] = msg.res_info.res.Credentials;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Certifications"] = msg.res_info.res.Certifications;
  j["RequestResource"]["ResourceInformation"]["Resource"]["SpecialRequirements"] = msg.res_info.res.SpecialRequirements;
  j["RequestResource"]["ResourceInformation"]["AssignmentInformation"]["Quantity"] = msg.res_info.assign_info.Quantity;
  j["RequestResource"]["ResourceInformation"]["AssignmentInformation"]["Restrictions"] = msg.res_info.assign_info.Restrictions;
  j["RequestResource"]["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] = msg.res_info.assign_info.AnticipatedFunction;
  j["RequestResource"]["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] = msg.res_info.sched_info.ScheduleType;
  j["RequestResource"]["ResourceInformation"]["ScheduleInformation"]["DateTime"] = msg.res_info.sched_info.DateTime;
  j["RequestResource"]["ResourceInformation"]["ScheduleInformation"]["Location"] = msg.res_info.sched_info.Location;

  return j.dump();
}

std::string TranslationEngine::response_to_request_resource_msg_to_json(ResponseToRequestResource msg) {
  nlohmann::json j;

  j["ResponseToRequestResource"]["SentDateTime"] = msg.SentDateTime;
  j["ResponseToRequestResource"]["MessageContentType"] = msg.MessageContentType;
  j["ResponseToRequestResource"]["MessageDescription"] = msg.MessageDescription;
  j["ResponseToRequestResource"]["OriginatingMessageID"] = msg.OriginatingMessageID;
  j["ResponseToRequestResource"]["IncidentInformation"]["IncidentID"] = msg.inc_info.IncidentID;
  j["ResponseToRequestResource"]["IncidentInformation"]["IncidentDescription"] = msg.inc_info.IncidentDescription;
  j["ResponseToRequestResource"]["MessageRecall"]["RecalledMessageID"] = msg.msg_rcl.RecalledMessageID;
  j["ResponseToRequestResource"]["MessageRecall"]["RecallType"] = msg.msg_rcl.RecallType;
  j["ResponseToRequestResource"]["Funding"]["FundCode"] = msg.fund.FundCode;
  j["ResponseToRequestResource"]["Funding"]["FundingInfo"] = msg.fund.FundingInfo;
  j["ResponseToRequestResource"]["ResourceInformation"]["ResourceInfoElementID"] = msg.res_info.ResourceInfoElementID;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["ResourceID"] = msg.res_info.res.ResourceID;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Name"] = msg.res_info.res.Name;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["TypeStructure"] = msg.res_info.res.TypeStructure;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["TypeInfo"] = msg.res_info.res.TypeInfo;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Keyword"] = msg.res_info.res.Keyword;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Description"] = msg.res_info.res.Description;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Credentials"] = msg.res_info.res.Credentials;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Certifications"] = msg.res_info.res.Certifications;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["SpecialRequirements"] = msg.res_info.res.SpecialRequirements;
  j["ResponseToRequestResource"]["ResourceInformation"]["AssignmentInformation"]["Quantity"] = msg.res_info.assign_info.Quantity;
  j["ResponseToRequestResource"]["ResourceInformation"]["AssignmentInformation"]["Restrictions"] = msg.res_info.assign_info.Restrictions;
  j["ResponseToRequestResource"]["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] = msg.res_info.assign_info.AnticipatedFunction;
  j["ResponseToRequestResource"]["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] = msg.res_info.sched_info.ScheduleType;
  j["ResponseToRequestResource"]["ResourceInformation"]["ScheduleInformation"]["DateTime"] = msg.res_info.sched_info.DateTime;
  j["ResponseToRequestResource"]["ResourceInformation"]["ScheduleInformation"]["Location"] = msg.res_info.sched_info.Location;
  j["ResponseToRequestResource"]["ResponseInformation"]["PrecedingResourceInfoElementID"] = msg.response_info.PrecedingResourceInfoElementID;
  j["ResponseToRequestResource"]["ResponseInformation"]["ResponseInfo"] = msg.response_info.ResponseType;
  j["ResponseToRequestResource"]["ResponseInformation"]["ReasonCode"] = msg.response_info.ReasonCode ;
  j["ResponseToRequestResource"]["ResponseInformation"]["ResponseReason"] = msg.response_info.ResponseReason;

  return j.dump();
}


int test() {
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

  std::cout << te.request_resource_msg_to_xml(test) << "\n\n\n";
  std::cout << te.request_resource_msg_to_json(test) << std::endl;

}

