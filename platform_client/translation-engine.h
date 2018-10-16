#include "./dependencies/json.hpp"
#include <string>

class TranslationEngine {
public:
  TranslationEngine() {}
  ~TranslationEngine() {}

  xml_to_resource_request_msg(std::string xml_str);
  xml_to_response_to_resource_request_msg(std::string xml_str);
  std::string msg_to_xml();
}
