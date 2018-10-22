#include "./dependencies/json.hpp"
#include "./dependencies/pugixml/pugixml.hpp"
#include "./message_elements/RequestResource.h"
#include "./message_elements/ResponseToRequestResource.h"
#include <string>

class TranslationEngine {
public:
  TranslationEngine() {}
  ~TranslationEngine() {}

  RequestResource xml_to_request_resource_msg(std::string id, const char * xml_str);
  ResponseToRequestResource xml_to_response_to_request_resource_msg(std::string id, const char * xml_str);
  std::string request_resource_msg_to_xml(RequestResource msg);
  std::string response_to_request_resource_msg_to_xml(ResponseToRequestResource msg);
};
