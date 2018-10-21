#include <iostream>

RequestResource TranslationEngine::xml_to_request_response_msg(std::string xml_str) {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_string(xml_str);

  RequestResource msg();
  msg.MessageID
}

/*
ResponseToRequestResource TranslationEngine::xml_to_response_to_request_resource_msg(std::string xml_str) {


}
*/

std::string TranslationEngine::resource_request_msg_to_xml(RequestResource msg) {
  pugi::xml_document doc;

  
}

/*
std::string TranslationEngine::resource_request_msg_to_xml(ResponseToRequestResource msg) {

}
*/
