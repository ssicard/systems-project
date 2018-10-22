#include <string>

#ifndef MESSAGEPROPERTIESLOOKUP_H
#define MESSAGEPROPERTIESLOOKUP_H

class MessagePropertiesLookup {
public:
	MessagePropertiesLookup(std::string RequirementType = "", std::string RequirementDesc = "") :
													RequirementType(RequirementType), RequirementDesc(RequirementDesc) {}
	~MessagePropertiesLookup() {}

	std::string RequirementType;
	std::string RequirementDesc;
};
#endif /* MESSAGEPROPERTIESLOOKUP_H */
