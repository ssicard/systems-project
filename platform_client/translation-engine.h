#include "./dependencies/json.hpp"
#include "./dependencies/pugixml.hpp"
#include ""
#include <string>

class TranslationEngine {
public:
  TranslationEngine() {}
  ~TranslationEngine() {}

  xml_to_resource_request_msg(std::string xml_str);
  xml_to_response_to_resource_request_msg(std::string xml_str);
  std::string resource_request_msg_to_xml();
  //std::string response_to_resource_request_msg_to_xml();
}
