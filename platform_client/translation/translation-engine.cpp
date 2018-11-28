#include <iostream>
#include "translation-engine.h"

//very ugly hardcoded non portable
// TODO: Change return type to ResourceMessage
ResourceMessage TranslationEngine::xml_to_request_resource_msg(std::string id, const char * xml_str) {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(xml_str);

  if (!result) {
    std::cout << "parsed with errors: \n" << result.description() <<'\n';
  }

  // TODO: Change this ResourceMessage
  ResourceMessage msg(id);

  pugi::xml_node req_res = doc.child("RequestResource");

  if(id == "") {
    msg.MessageID = std::string(req_res.child_value("MessageID"));
  }

  // TODO: Add to relevant fields in ResourceMessage
  // TODO: std::string IncidientID
  // TODO: std::string RecalledMessageID
  // TODO: std::string FundCode
  // TODO: std::string ContactInformationID

  // Initialize base fields
  msg._SentDateTime = std::string(req_res.child_value("SentDateTime"));
  msg.MessageContentType = std::string(req_res.child_value("MessageContentType"));
  msg.MessageDescription = std::string(req_res.child_value("MessageDescription"));
  msg.OriginatingMessageID = std::string(req_res.child_value("OriginatingMessageID"));

  // Initialize IncidentID
  msg.IncidentID = std::string(req_res.child("IncidentInformation").child_value("IncidentID")); 

  // Initialize _IncidentInformation object
  msg._IncidentInformation.IncidentID = std::string(req_res.child("IncidentInformation").child_value("IncidentID"));
  msg._IncidentInformation.IncidentDescription = std::string(req_res.child("IncidentInformation").child_value("IncidentDescription"));

  // Initialize RecalledMessageID
  msg.RecalledMessageID = std::string(req_res.child("MessageRecall").child_value("RecalledMessageID"));

  // Intialize _MessageRecall object
  msg._MessageRecall.RecalledMessageID = std::string(req_res.child("MessageRecall").child_value("RecalledMessageID"));
  msg._MessageRecall.RecallType = std::string(req_res.child("MessageRecall").child_value("RecallType"));

  // Initialize FundCode
  msg.FundCode = std::string(req_res.child("Funding").child_value("FundCode"));

  // Intialize _Funding object
  msg._Funding.FundCode = std::string(req_res.child("Funding").child_value("FundCode"));
  msg._Funding.FundingInfo = std::string(req_res.child("Funding").child_value("FundingInfo"));

  // Intialize ResouceInfoElementID
  msg.ResourceInfoElementID = std::string(req_res.child("ResourceInformation").child_value("ResourceInfoElementID"));

  // Intialize ResourceInformation Object
  msg._ResourceInformation.ResourceInfoElementID = std::string(req_res.child("ResourceInformation").child_value("ResourceInfoElementID"));

  // Intialize ResourceID in _ResourceInformation object
  msg._ResourceInformation.ResourceID = std::string(req_res.child("ResourceInformation").child("Resource").child_value("ResourceID"));

  // Intiailzie _Resource child object in _ResourceInformation object
  msg._ResourceInformation._Resource.ResourceID = std::string(req_res.child("ResourceInformation").child("Resource").child_value("ResourceID"));
  msg._ResourceInformation._Resource.Name = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Name"));
  msg._ResourceInformation._Resource.TypeStructure = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeStructure"));
  msg._ResourceInformation._Resource.TypeInfo = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeInfo"));
  msg._ResourceInformation._Resource.Keyword = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Keyword"));
  msg._ResourceInformation._Resource.Description = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Description"));
  msg._ResourceInformation._Resource.Credentials = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Credentials"));
  msg._ResourceInformation._Resource.Certifications = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Certifications"));
  msg._ResourceInformation._Resource.SpecialRequirements = std::string(req_res.child("ResourceInformation").child("Resource").child_value("SpecialRequirements"));

  // TODO: WITHOUT IDs, _AssignmentInformation WILL NOT BE STORED IN DB 
  // Initialize _AssignmentInformation child object in _ResourceInformation 
  msg._ResourceInformation._AssignmentInformation.Quantity = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Quantity"));
  msg._ResourceInformation._AssignmentInformation.Restrictions = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Restrictions"));
  msg._ResourceInformation._AssignmentInformation.AnticipatedFunction = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("AnticipatedFunction"));
 
  // TODO: WITHOUT IDs, ScheduleInformation WILL NOT BE STORED IN DB 
  // Intiailize _ScheduleInformation child object in _ResourceInformation
  msg._ResourceInformation._ScheduleInformation.ScheduleType = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("ScheduleType"));
  msg._ResourceInformation._ScheduleInformation.DateTime = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("DateTime"));
  msg._ResourceInformation._ScheduleInformation.Location = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("Location"));

  return msg;
}

// TODO: Change return type to ResourceMessage
ResourceMessage TranslationEngine::xml_to_response_to_request_resource_msg(std::string id, const char * xml_str) {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(xml_str);

  if (!result) {
    std::cout << "parsed with errors: \n" << result.description() <<'\n';
  }

  ResourceMessage msg(id);

  pugi::xml_node req_res = doc.child("ResponseToRequestResource");

  if(id == "") {
    msg.MessageID = std::string(req_res.child_value("MessageID"));
  }

  // TODO: Add to relevant fields in ResourceMessage
  // TODO: std::string IncidientID
  // TODO: std::string RecalledMessageID
  // TODO: std::string FundCode
  // TODO: std::string ContactInformationID
  // TODO: Initialize ResponseInformation information in Resource object

  std::cout << "Before initializing base fields\n"; 
  // Initalize base fields
  msg._SentDateTime = std::string(req_res.child_value("SentDateTime"));
  msg.MessageContentType = std::string(req_res.child_value("MessageContentType"));
  msg.MessageDescription = std::string(req_res.child_value("MessageDescription"));
  msg.OriginatingMessageID = std::string(req_res.child_value("OriginatingMessageID"));

  // Initialize IncidentID
  msg.IncidentID = std::string(req_res.child("IncidentInformation").child_value("IncidentID"));

  // Initialize _IncidentInformation object
  msg._IncidentInformation.IncidentID = std::string(req_res.child("IncidentInformation").child_value("IncidentID"));
  msg._IncidentInformation.IncidentDescription = std::string(req_res.child("IncidentInformation").child_value("IncidentDescription"));

  // Initialize RecalledMessageID
  msg.RecalledMessageID = std::string(req_res.child("MessageRecall").child_value("RecalledMessageID"));

  // Initialize _MessageRecall object
  msg._MessageRecall.RecalledMessageID = std::string(req_res.child("MessageRecall").child_value("RecalledMessageID"));
  msg._MessageRecall.RecallType = std::string(req_res.child("MessageRecall").child_value("RecallType"));

  // Initialize FundCode
  msg.FundCode = std::string(req_res.child("Funding").child_value("FundCode"));

  // Initialize _Funding object
  msg._Funding.FundCode = std::string(req_res.child("Funding").child_value("FundCode"));
  msg._Funding.FundingInfo = std::string(req_res.child("Funding").child_value("FundingInfo"));

  // Intialize ResourceInfoElementID
  msg.ResourceInfoElementID = std::string(req_res.child("ResourceInformation").child_value("ResourceInfoElementID"));
 
  // Initialize _ResourceInformation object 
  msg._ResourceInformation.ResourceInfoElementID = std::string(req_res.child("ResourceInformation").child_value("ResourceInfoElementID"));
  
  // Intialize ResourceID in _ResourceInformation object
  msg._ResourceInformation.ResourceID = std::string(req_res.child("ResourceInformation").child("Resource").child_value("ResourceID"));

  // Initialize _Resource child object in _ResourceInformation
  msg._ResourceInformation._Resource.ResourceID = std::string(req_res.child("ResourceInformation").child("Resource").child_value("ResourceID"));
  msg._ResourceInformation._Resource.Name = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Name"));
  msg._ResourceInformation._Resource.TypeStructure = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeStructure"));
  msg._ResourceInformation._Resource.TypeInfo = std::string(req_res.child("ResourceInformation").child("Resource").child_value("TypeInfo"));
  msg._ResourceInformation._Resource.Keyword = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Keyword"));
  msg._ResourceInformation._Resource.Description = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Description"));
  msg._ResourceInformation._Resource.Credentials = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Credentials"));
  msg._ResourceInformation._Resource.Certifications = std::string(req_res.child("ResourceInformation").child("Resource").child_value("Certifications"));
  msg._ResourceInformation._Resource.SpecialRequirements = std::string(req_res.child("ResourceInformation").child("Resource").child_value("SpecialRequirements"));

  // TODO: WITHOUT IDs, _AssignmentInformation WILL NOT BE STORED IN DB 
  // Intialize _AssignmentInformation child object in _ResourceInformation object 
  msg._ResourceInformation._AssignmentInformation.Quantity = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Quantity"));
  msg._ResourceInformation._AssignmentInformation.Restrictions = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("Restrictions"));
  msg._ResourceInformation._AssignmentInformation.AnticipatedFunction = std::string(req_res.child("ResourceInformation").child("AssignmentInformation").child_value("AnticipatedFunction"));

  // TODO: WITHOUT IDs, _ScheduleInformation WILL NOT BE STORED IN DB 
  // Initialize _ScheduleInformation child object in _ResourceInformation object
  msg._ResourceInformation._ScheduleInformation.ScheduleType = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("ScheduleType"));
  msg._ResourceInformation._ScheduleInformation.DateTime = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("DateTime"));
  msg._ResourceInformation._ScheduleInformation.Location = std::string(req_res.child("ResourceInformation").child("ScheduleInformation").child_value("Location"));
  
  // Initialize ResponseInformationID in _ResourceInformation object
  msg._ResourceInformation.ResponseInformationID = std::string(req_res.child("ResponseInformation").child_value("PrecedingResourceInfoElementID"));
 
  // Initialize _ResponseInformation object in _ResourceInformation object 
  msg._ResourceInformation._ResponseInformation.PrecedingResourceInfoElementID = std::string(req_res.child("ResponseInformation").child_value("PrecedingResourceInfoElementID"));
  msg._ResourceInformation._ResponseInformation.ResponseType = std::string(req_res.child("ResponseInformation").child_value("ResponseType"));
  msg._ResourceInformation._ResponseInformation.ReasonCode = std::string(req_res.child("ResponseInformation").child_value("ReasonCode"));
  msg._ResourceInformation._ResponseInformation.ResponseReason = std::string(req_res.child("ResponseInformation").child_value("ResponseReason"));

  return msg;
}

// TODO: Change return type to ResourceMessage
ResourceMessage TranslationEngine::json_to_request_resource_msg(std::string id, const char * json_str) {
  std::string cpp_json_str(json_str);
  ResourceMessage msg(id);

  auto json_obj = nlohmann::json::parse(cpp_json_str);
  auto req_res = json_obj["RequestResource"];
  if(id == "") {
    msg.MessageID = req_res["MessageID"] == nullptr ? "" : req_res["MessageID"];
  }


  
  // Intialize base fields
  msg._SentDateTime = req_res["SentDateTime"] == nullptr ? "" : req_res["SentDateTime"];
  msg.MessageContentType = req_res["MessageContentType"] == nullptr ? "" : req_res["MessageContentType"];
  msg.MessageDescription = req_res["MessageDescription"] == nullptr ? "" : req_res["MessageDescription"];
  msg.OriginatingMessageID = req_res["OriginatingMessageID"] == nullptr ? "" : req_res["OriginatingMessageID"];

  // Intialize IncidentID
  msg.IncidentID = req_res["IncidentInformation"]["IncidentID"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentID"];

  // Intialize _IncidentInformation
  msg._IncidentInformation.IncidentID = req_res["IncidentInformation"]["IncidentID"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentID"];
  msg._IncidentInformation.IncidentDescription = req_res["IncidentInformation"]["IncidentDescription"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentDescription"];

  // Initialize RecalledMessageID
  msg.RecalledMessageID = req_res["MessageRecall"]["RecalledMessageID"] == nullptr ? "" : req_res["MessageRecall"]["RecalledMessageID"];

  // Intialize _MessageRecall object
  msg._MessageRecall.RecalledMessageID = req_res["MessageRecall"]["RecalledMessageID"] == nullptr ? "" : req_res["MessageRecall"]["RecalledMessageID"];
  msg._MessageRecall.RecallType = req_res["MessageRecall"]["RecallType"] == nullptr ? "" : req_res["MessageRecall"]["RecallType"];
 
  // Initilalize FundCode 
  msg.FundCode = req_res["Funding"]["FundCode"] == nullptr ? "" : req_res["Funding"]["FundCode"];

  // Initialize _Funding object
  msg._Funding.FundCode = req_res["Funding"]["FundCode"] == nullptr ? "" : req_res["Funding"]["FundCode"];
  msg._Funding.FundingInfo = req_res["Funding"]["FundingInfo"] == nullptr ? "" : req_res["Funding"]["FundingInfo"];

  // Initialize ResourceInfoElementID
  msg.ResourceInfoElementID = req_res["ResourceInformation"]["ResourceInfoElementID"] == nullptr ? "" : req_res["ResourceInformation"]["ResourceInfoElementID"];

  // Initialize _ResourceInformation object
  msg._ResourceInformation.ResourceInfoElementID = req_res["ResourceInformation"]["ResourceInfoElementID"] == nullptr ? "" : req_res["ResourceInformation"]["ResourceInfoElementID"];

  // Initialize ResourceID field in _ResourceInformation object
  msg._ResourceInformation.ResourceID = req_res["ResourceInformation"]["Resource"]["ResourceID"]  == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceID"];

  // Initialize _Resource child object in ResourceInformation object
  msg._ResourceInformation._Resource.ResourceID = req_res["ResourceInformation"]["Resource"]["ResourceID"]  == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceID"];
  msg._ResourceInformation._Resource.Name = req_res["ResourceInformation"]["Resource"]["Name"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Name"];
  msg._ResourceInformation._Resource.TypeStructure = req_res["ResourceInformation"]["Resource"]["TypeStructure"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeStructure"];
  msg._ResourceInformation._Resource.TypeInfo = req_res["ResourceInformation"]["Resource"]["TypeInfo"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeInfo"];
  msg._ResourceInformation._Resource.Keyword = req_res["ResourceInformation"]["Resource"]["Keyword"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Keyword"];
  msg._ResourceInformation._Resource.Description = req_res["ResourceInformation"]["Resource"]["Description"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Description"];
  msg._ResourceInformation._Resource.Credentials = req_res["ResourceInformation"]["Resource"]["Credentials"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Credentials"];
  msg._ResourceInformation._Resource.Certifications = req_res["ResourceInformation"]["Resource"]["Certifications"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Certifications"];
  msg._ResourceInformation._Resource.SpecialRequirements = req_res["ResourceInformation"]["Resource"]["SpecialRequirements"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["SpecialRequirements"];

  // TODO: WITHOUT IDs, _AssignmentInformation WILL NOT BE STORED IN DB
  // Initialize _AssignmentInformation child object in _ResourceInformation object
  msg._ResourceInformation._AssignmentInformation.Quantity = req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"];
  msg._ResourceInformation._AssignmentInformation.Restrictions = req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"];
  msg._ResourceInformation._AssignmentInformation.AnticipatedFunction = req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"];

  // TODO: WITHOUT IDs, _ScheduleInformation WILL NOT BE STORED IN DB
  // Initialize _ScheduleInformation child object in _ResourceInformation object
  msg._ResourceInformation._ScheduleInformation.ScheduleType = req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"];
  msg._ResourceInformation._ScheduleInformation.DateTime = req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"];
  msg._ResourceInformation._ScheduleInformation.Location = req_res["ResourceInformation"]["ScheduleInformation"]["Location"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["Location"];

  return msg;
}


// TODO: Change return type to ResourceMessage
ResourceMessage TranslationEngine::json_to_response_to_request_resource_msg(std::string id, const char * json_str) {
  std::string cpp_json_str(json_str);
  ResourceMessage msg(id);

  auto json_obj = nlohmann::json::parse(cpp_json_str);
  auto req_res = json_obj["ResponseToRequestResource"];
  if(id == "") {
    msg.MessageID = req_res["MessageID"] == nullptr ? "" : req_res["MessageID"];
  }

  // Initialize base fields for ResourceMessage
  std::cout << "SentDateTime: " << msg._SentDateTime << std::endl;
  msg._SentDateTime = req_res["SentDateTime"] == nullptr ? "" : req_res["SentDateTime"];
  msg.MessageContentType = req_res["MessageContentType"] == nullptr ? "" : req_res["MessageContentType"];
  msg.MessageDescription = req_res["MessageDescription"] == nullptr ? "" : req_res["MessageDescription"];
  msg.OriginatingMessageID = req_res["OriginatingMessageID"] == nullptr ? "" : req_res["OriginatingMessageID"];
  
  // Initialize IncidentID
  msg.IncidentID = req_res["IncidentInformation"]["IncidentID"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentID"];
  
  // Initialize _IncidentInformation object
  msg._IncidentInformation.IncidentID = req_res["IncidentInformation"]["IncidentID"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentID"];
  msg._IncidentInformation.IncidentDescription = req_res["IncidentInformation"]["IncidentDescription"] == nullptr ? "" : req_res["IncidentInformation"]["IncidentDescription"];
  
  // Initialize RecalledMessageID
  msg.RecalledMessageID = req_res["MessageRecall"]["RecalledMessageID"] == nullptr ? "" : req_res["MessageRecall"]["RecalledMessageID"];

  // Initiailze _MessageRecall object
  msg._MessageRecall.RecalledMessageID = req_res["MessageRecall"]["RecalledMessageID"] == nullptr ? "" : req_res["MessageRecall"]["RecalledMessageID"];
  msg._MessageRecall.RecallType = req_res["MessageRecall"]["RecallType"] == nullptr ? "" : req_res["MessageRecall"]["RecallType"];
  
  // Intialize FundCode
  msg.FundCode = req_res["Funding"]["FundCode"] == nullptr ? "" : req_res["Funding"]["FundCode"];
  
  // Initialize _Funding object
  msg._Funding.FundCode = req_res["Funding"]["FundCode"] == nullptr ? "" : req_res["Funding"]["FundCode"];
  msg._Funding.FundingInfo = req_res["Funding"]["FundingInfo"] == nullptr ? "" : req_res["Funding"]["FundingInfo"];
  
  // Initiailze ResourceInfoElementID
  msg.ResourceInfoElementID = req_res["ResourceInformation"]["ResourceInfoElementID"] == nullptr ? "" : req_res["ResourceInformation"]["ResourceInfoElementID"];

  // Initiailze _ResourceInformation object
  msg._ResourceInformation.ResourceInfoElementID = req_res["ResourceInformation"]["ResourceInfoElementID"] == nullptr ? "" : req_res["ResourceInformation"]["ResourceInfoElementID"];

  // Intiialize ResourceID field in _ResourceInformation object
  msg._ResourceInformation.ResourceID = req_res["ResourceInformation"]["Resource"]["ResourceID"]  == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceID"];

  // Initialize _Resource child object in _ResourceInformation
  msg._ResourceInformation._Resource.ResourceID = req_res["ResourceInformation"]["Resource"]["ResourceID"]  == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["ResourceID"];
  msg._ResourceInformation._Resource.Name = req_res["ResourceInformation"]["Resource"]["Name"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Name"];
  msg._ResourceInformation._Resource.TypeStructure = req_res["ResourceInformation"]["Resource"]["TypeStructure"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeStructure"];
  msg._ResourceInformation._Resource.TypeInfo = req_res["ResourceInformation"]["Resource"]["TypeInfo"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["TypeInfo"];
  msg._ResourceInformation._Resource.Keyword = req_res["ResourceInformation"]["Resource"]["Keyword"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Keyword"];
  msg._ResourceInformation._Resource.Description = req_res["ResourceInformation"]["Resource"]["Description"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Description"];
  msg._ResourceInformation._Resource.Credentials = req_res["ResourceInformation"]["Resource"]["Credentials"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Credentials"];
  msg._ResourceInformation._Resource.Certifications = req_res["ResourceInformation"]["Resource"]["Certifications"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["Certifications"];
  msg._ResourceInformation._Resource.SpecialRequirements = req_res["ResourceInformation"]["Resource"]["SpecialRequirements"] == nullptr ? "" : req_res["ResourceInformation"]["Resource"]["SpecialRequirements"];
  
  // TODO: WITHOUT IDs, _AssignmentInformation OBJECT WILL NOT BE SAVED TO DB
  // Initialize _AssignmentInformation child object in _ResourceInformation
  msg._ResourceInformation._AssignmentInformation.Quantity = req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Quantity"];
  msg._ResourceInformation._AssignmentInformation.Restrictions = req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["Restrictions"];
  msg._ResourceInformation._AssignmentInformation.AnticipatedFunction = req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] == nullptr ? "" : req_res["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"];

  // TODO: WITHOUT IDs, _ScheduleInformation OBJECT WILL NOT BE SAVED TO DB
  // Initialize _ScheduleInformation child object in _ResourceInformation
  msg._ResourceInformation._ScheduleInformation.ScheduleType = req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["ScheduleType"];
  msg._ResourceInformation._ScheduleInformation.DateTime = req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["DateTime"];
  msg._ResourceInformation._ScheduleInformation.Location = req_res["ResourceInformation"]["ScheduleInformation"]["Location"] == nullptr ? "" : req_res["ResourceInformation"]["ScheduleInformation"]["Location"];

  // Initialize ResponseInformationID field in _ResourceInformation object
  msg._ResourceInformation.ResponseInformationID = req_res["ResponseInformation"]["PrecedingResourceInfoElementID"] == nullptr ? "" : req_res["ResponseInformation"]["PrecedingResourceInfoElementID"];

  // Initialize _ResponseInformation child object in _ResourceInformation object
  msg._ResourceInformation._ResponseInformation.PrecedingResourceInfoElementID = req_res["ResponseInformation"]["PrecedingResourceInfoElementID"] == nullptr ? "" : req_res["ResponseInformation"]["PrecedingResourceInfoElementID"];
  msg._ResourceInformation._ResponseInformation.ResponseType = req_res["ResponseInformation"]["ResponseType"] == nullptr ? "" : req_res["ResponseInformation"]["ResponseType"];
  msg._ResourceInformation._ResponseInformation.ReasonCode = req_res["ResponseInformation"]["ReasonCode"] == nullptr ? "" :req_res["ResponseInformation"]["ReasonCode"];
  msg._ResourceInformation._ResponseInformation.ResponseReason = req_res["ResponseInformation"]["ResponseReason"] == nullptr ? "" : req_res["ResponseInformation"]["ResponseReason"];

  return msg;
}


// TODO: Change paramter type to ResourceMessage
//pugi::xml doesnt seem to have a good way to output the whole tree to a string
std::string TranslationEngine::request_resource_msg_to_xml(ResourceMessage msg) {
  std::string out;

  out.append("<RequestResource>");
  out.append("<MessageID>" + msg.MessageID + "</MessageID>");
  out.append("<SentDateTime>" + msg._SentDateTime + "</SentDateTime>");
  out.append("<MessageContentType>" + msg.MessageContentType + "</MessageContentType>");
  out.append("<MessageDescription>" + msg.MessageDescription + "</MessageDescription>");
  out.append("<OriginatingMessageID>" + msg.OriginatingMessageID + "</OriginatingMessageID>");
  out.append("<IncidentInformation>");
  out.append("<IncidentID>" + msg._IncidentInformation.IncidentID + "</IncidentID>");
  out.append("<IncidentDescription>" + msg._IncidentInformation.IncidentDescription + "</IncidentDescription>");
  out.append("</IncidentInformation>");
  out.append("<MessageRecall>");
  out.append("<RecalledMessageID>" + msg._MessageRecall.RecalledMessageID + "</RecalledMessageID>");
  out.append("<RecallType>" + msg._MessageRecall.RecallType + "</RecallType>");
  out.append("</MessageRecall>");
  out.append("<Funding>");
  out.append("<FundCode>" + msg._Funding.FundCode + "</FundCode>");
  out.append("<FundingInfo>" + msg._Funding.FundingInfo + "</FundingInfo>");
  out.append("</Funding>");
  out.append("<ResourceInformation>");
  out.append("<ResourceInfoElementID>" + msg._ResourceInformation.ResourceInfoElementID + "</ResourceInfoElementID>");
  out.append("<Resource>");
  out.append("<ResourceID>" + msg._ResourceInformation._Resource.ResourceID + "</ResourceID>");
  out.append("<Name>" + msg._ResourceInformation._Resource.Name + "</Name>");
  out.append("<TypeStructure>" + msg._ResourceInformation._Resource.TypeStructure + "</TypeStructure>");
  out.append("<TypeInfo>" + msg._ResourceInformation._Resource.TypeInfo + "</TypeInfo>");
  out.append("<Keyword>" + msg._ResourceInformation._Resource.Keyword + "</Keyword>");
  out.append("<Description>" + msg._ResourceInformation._Resource.Description + "</Description>");
  out.append("<Credentials>" + msg._ResourceInformation._Resource.Credentials + "</Credentials>");
  out.append("<Certifications>" + msg._ResourceInformation._Resource.Certifications + "</Certifications>");
  out.append("<SpecialRequirements>" + msg._ResourceInformation._Resource.SpecialRequirements + "</SpecialRequirements>");
  out.append("</Resource>");
  out.append("<AssignmentInformation>");
  out.append("<Quantity>" + msg._ResourceInformation._AssignmentInformation.Quantity + "</Quantity>");
  out.append("<Restrictions>" + msg._ResourceInformation._AssignmentInformation.Restrictions + "</Restrictions>");
  out.append("<AnticipatedFunction>" + msg._ResourceInformation._AssignmentInformation.AnticipatedFunction + "</AnticipatedFunction>");
  out.append("</AssignmentInformation>");
  out.append("<ScheduleInformation>");
  out.append("<ScheduleType>" + msg._ResourceInformation._ScheduleInformation.ScheduleType + "</ScheduleType>");
  out.append("<DateTime>" + msg._ResourceInformation._ScheduleInformation.DateTime + "</DateTime>");
  out.append("<Location>" + msg._ResourceInformation._ScheduleInformation.Location + "</Location>");
  out.append("</ScheduleInformation></ResourceInformation></RequestResource>");

  return out;
}

// TODO: Change parameter type to ResourceMessage
std::string TranslationEngine::response_to_request_resource_msg_to_xml(ResourceMessage msg) {
  std::string out;

  std::cout << "SentDateTime: in response_to_request_resource_msg_to_xml: " << msg._SentDateTime << std::endl; 

  out.append("<RequestResource>");
  out.append("<MessageID>" + msg.MessageID + "</MessageID>");
  out.append("<SentDateTime>" + msg._SentDateTime + "</SentDateTime>");
  out.append("<MessageContentType>" + msg.MessageContentType + "</MessageContentType>");
  out.append("<MessageDescription>" + msg.MessageDescription + "</MessageDescription>");
  out.append("<OriginatingMessageID>" + msg.OriginatingMessageID + "</OriginatingMessageID>");
  out.append("<IncidentInformation>");
  out.append("<IncidentID>" + msg._IncidentInformation.IncidentID + "</IncidentID>");
  out.append("<IncidentDescription>" + msg._IncidentInformation.IncidentDescription + "</IncidentDescription>");
  out.append("</IncidentInformation>");
  out.append("<MessageRecall>");
  out.append("<RecalledMessageID>" + msg._MessageRecall.RecalledMessageID + "</RecalledMessageID>");
  out.append("<RecallType>" + msg._MessageRecall.RecallType + "</RecallType>");
  out.append("</MessageRecall>");
  out.append("<Funding>");
  out.append("<FundCode>" + msg._Funding.FundCode + "</FundCode>");
  out.append("<FundingInfo>" + msg._Funding.FundingInfo + "</FundingInfo>");
  out.append("</Funding>");
  out.append("<ResourceInformation>");
  out.append("<ResourceInfoElementID>" + msg._ResourceInformation.ResourceInfoElementID + "</ResourceInfoElementID>");
  out.append("<Resource>");
  out.append("<ResourceID>" + msg._ResourceInformation._Resource.ResourceID + "</ResourceID>");
  out.append("<Name>" + msg._ResourceInformation._Resource.Name + "</Name>");
  out.append("<TypeStructure>" + msg._ResourceInformation._Resource.TypeStructure + "</TypeStructure>");
  out.append("<TypeInfo>" + msg._ResourceInformation._Resource.TypeInfo + "</TypeInfo>");
  out.append("<Keyword>" + msg._ResourceInformation._Resource.Keyword + "</Keyword>");
  out.append("<Description>" + msg._ResourceInformation._Resource.Description + "</Description>");
  out.append("<Credentials>" + msg._ResourceInformation._Resource.Credentials + "</Credentials>");
  out.append("<Certifications>" + msg._ResourceInformation._Resource.Certifications + "</Certifications>");
  out.append("<SpecialRequirements>" + msg._ResourceInformation._Resource.SpecialRequirements + "</SpecialRequirements>");
  out.append("</Resource>");
  out.append("<AssignementInformation>");
  out.append("<Quantity>" + msg._ResourceInformation._AssignmentInformation.Quantity + "</Quantity>");
  out.append("<Restrictions>" + msg._ResourceInformation._AssignmentInformation.Restrictions + "</Restrictions>");
  out.append("<AnticipatedFunction>" + msg._ResourceInformation._AssignmentInformation.AnticipatedFunction + "</AnticipatedFunction>");
  out.append("</AssignmentInformation>");
  out.append("<ScheduleInformation>");
  out.append("<ScheduleType>" + msg._ResourceInformation._ScheduleInformation.ScheduleType + "</ScheduleType>");
  out.append("<DateTime>" + msg._ResourceInformation._ScheduleInformation.DateTime + "</DateTime>");
  out.append("<Location>" + msg._ResourceInformation._ScheduleInformation.Location + "</Location>");
  out.append("</ScheduleInformation>");
  out.append("</ResourceInformation>");
  out.append("<ResponseInformation>");
  out.append("<PrecedingResourceInfoElementID>" + msg._ResourceInformation._ResponseInformation.PrecedingResourceInfoElementID + "</PrecedingResourceInfoElementID>");
  out.append("<ResponseType>" + msg._ResourceInformation._ResponseInformation.ResponseType + "</ResponseType>");
  out.append("<ReasonCode>" + msg._ResourceInformation._ResponseInformation.ReasonCode + "</ReasonCode>");
  out.append("<ResponseReason>" + msg._ResourceInformation._ResponseInformation.ResponseReason + "</ResponseReason>");
  out.append("</RequestResource>");

  return out;
}

// TODO: Change parameter type to ResourceMessage
std::string TranslationEngine::request_resource_msg_to_json(ResourceMessage msg) {
  nlohmann::json j;

  j["RequestResource"]["SentDateTime"] = msg._SentDateTime;
  j["RequestResource"]["MessageContentType"] = msg.MessageContentType;
  j["RequestResource"]["MessageDescription"] = msg.MessageDescription;
  j["RequestResource"]["OriginatingMessageID"] = msg.OriginatingMessageID;
  j["RequestResource"]["IncidentInformation"]["IncidentID"] = msg._IncidentInformation.IncidentID;
  j["RequestResource"]["IncidentInformation"]["IncidentDescription"] = msg._IncidentInformation.IncidentDescription;
  j["RequestResource"]["MessageRecall"]["RecalledMessageID"] = msg._MessageRecall.RecalledMessageID;
  j["RequestResource"]["MessageRecall"]["RecallType"] = msg._MessageRecall.RecallType;
  j["RequestResource"]["Funding"]["FundCode"] = msg._Funding.FundCode;
  j["RequestResource"]["Funding"]["FundingInfo"] = msg._Funding.FundingInfo;
  j["RequestResource"]["ResourceInformation"]["ResourceInfoElementID"] = msg._ResourceInformation.ResourceInfoElementID;
  j["RequestResource"]["ResourceInformation"]["Resource"]["ResourceID"] = msg._ResourceInformation._Resource.ResourceID;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Name"] = msg._ResourceInformation._Resource.Name;
  j["RequestResource"]["ResourceInformation"]["Resource"]["TypeStructure"] = msg._ResourceInformation._Resource.TypeStructure;
  j["RequestResource"]["ResourceInformation"]["Resource"]["TypeInfo"] = msg._ResourceInformation._Resource.TypeInfo;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Keyword"] = msg._ResourceInformation._Resource.Keyword;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Description"] = msg._ResourceInformation._Resource.Description;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Credentials"] = msg._ResourceInformation._Resource.Credentials;
  j["RequestResource"]["ResourceInformation"]["Resource"]["Certifications"] = msg._ResourceInformation._Resource.Certifications;
  j["RequestResource"]["ResourceInformation"]["Resource"]["SpecialRequirements"] = msg._ResourceInformation._Resource.SpecialRequirements;
  j["RequestResource"]["ResourceInformation"]["AssignmentInformation"]["Quantity"] = msg._ResourceInformation._AssignmentInformation.Quantity;
  j["RequestResource"]["ResourceInformation"]["AssignmentInformation"]["Restrictions"] = msg._ResourceInformation._AssignmentInformation.Restrictions;
  j["RequestResource"]["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] = msg._ResourceInformation._AssignmentInformation.AnticipatedFunction;
  j["RequestResource"]["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] = msg._ResourceInformation._ScheduleInformation.ScheduleType;
  j["RequestResource"]["ResourceInformation"]["ScheduleInformation"]["DateTime"] = msg._ResourceInformation._ScheduleInformation.DateTime;
  j["RequestResource"]["ResourceInformation"]["ScheduleInformation"]["Location"] = msg._ResourceInformation._ScheduleInformation.Location;

  return j.dump();
}

// TODO: Change parameter type to ResourceMessage
std::string TranslationEngine::response_to_request_resource_msg_to_json(ResourceMessage msg) {
  nlohmann::json j;

  j["ResponseToRequestResource"]["SentDateTime"] = msg._SentDateTime;
  j["ResponseToRequestResource"]["MessageContentType"] = msg.MessageContentType;
  j["ResponseToRequestResource"]["MessageDescription"] = msg.MessageDescription;
  j["ResponseToRequestResource"]["OriginatingMessageID"] = msg.OriginatingMessageID;
  j["ResponseToRequestResource"]["IncidentInformation"]["IncidentID"] = msg._IncidentInformation.IncidentID;
  j["ResponseToRequestResource"]["IncidentInformation"]["IncidentDescription"] = msg._IncidentInformation.IncidentDescription;
  j["ResponseToRequestResource"]["MessageRecall"]["RecalledMessageID"] = msg._MessageRecall.RecalledMessageID;
  j["ResponseToRequestResource"]["MessageRecall"]["RecallType"] = msg._MessageRecall.RecallType;
  j["ResponseToRequestResource"]["Funding"]["FundCode"] = msg._Funding.FundCode;
  j["ResponseToRequestResource"]["Funding"]["FundingInfo"] = msg._Funding.FundingInfo;
  j["ResponseToRequestResource"]["ResourceInformation"]["ResourceInfoElementID"] = msg._ResourceInformation.ResourceInfoElementID;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["ResourceID"] = msg._ResourceInformation._Resource.ResourceID;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Name"] = msg._ResourceInformation._Resource.Name;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["TypeStructure"] = msg._ResourceInformation._Resource.TypeStructure;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["TypeInfo"] = msg._ResourceInformation._Resource.TypeInfo;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Keyword"] = msg._ResourceInformation._Resource.Keyword;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Description"] = msg._ResourceInformation._Resource.Description;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Credentials"] = msg._ResourceInformation._Resource.Credentials;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["Certifications"] = msg._ResourceInformation._Resource.Certifications;
  j["ResponseToRequestResource"]["ResourceInformation"]["Resource"]["SpecialRequirements"] = msg._ResourceInformation._Resource.SpecialRequirements;
  j["ResponseToRequestResource"]["ResourceInformation"]["AssignmentInformation"]["Quantity"] = msg._ResourceInformation._AssignmentInformation.Quantity;
  j["ResponseToRequestResource"]["ResourceInformation"]["AssignmentInformation"]["Restrictions"] = msg._ResourceInformation._AssignmentInformation.Restrictions;
  j["ResponseToRequestResource"]["ResourceInformation"]["AssignmentInformation"]["AnticipatedFunction"] = msg._ResourceInformation._AssignmentInformation.AnticipatedFunction;
  j["ResponseToRequestResource"]["ResourceInformation"]["ScheduleInformation"]["ScheduleType"] = msg._ResourceInformation._ScheduleInformation.ScheduleType;
  j["ResponseToRequestResource"]["ResourceInformation"]["ScheduleInformation"]["DateTime"] = msg._ResourceInformation._ScheduleInformation.DateTime;
  j["ResponseToRequestResource"]["ResourceInformation"]["ScheduleInformation"]["Location"] = msg._ResourceInformation._ScheduleInformation.Location;
  j["ResponseToRequestResource"]["ResponseInformation"]["PrecedingResourceInfoElementID"] = msg._ResourceInformation._ResponseInformation.PrecedingResourceInfoElementID;
  j["ResponseToRequestResource"]["ResponseInformation"]["ResponseInfo"] = msg._ResourceInformation._ResponseInformation.ResponseType;
  j["ResponseToRequestResource"]["ResponseInformation"]["ReasonCode"] = msg._ResourceInformation._ResponseInformation.ReasonCode ;
  j["ResponseToRequestResource"]["ResponseInformation"]["ResponseReason"] = msg._ResourceInformation._ResponseInformation.ResponseReason;

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

  //RequestResource test = te.xml_to_request_resource_msg("1", msg);
  ResourceMessage test = te.xml_to_request_resource_msg("1", msg);

  std::cout << te.request_resource_msg_to_xml(test) << "\n\n\n";
  std::cout << te.request_resource_msg_to_json(test) << std::endl;

}

