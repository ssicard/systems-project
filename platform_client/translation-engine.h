#include "./dependencies/json.hpp"
#include "./dependencies/pugixml.hpp"
#include "./message_elements/ResourceRequest.h"
#include <string>

class TranslationEngine {
public:
  TranslationEngine() {}
  ~TranslationEngine() {}

  RequestResource xml_to_request_response_msg(std::string xml_str);
  //ResponseToRequestResource xml_to_response_to_request_resource_msg(std::string xml_str);
  std::string resource_request_msg_to_xml(RequestResource msg);
  //std::string response_to_request_resource_msg_to_xml(ResponseToRequestResource msg);
}
