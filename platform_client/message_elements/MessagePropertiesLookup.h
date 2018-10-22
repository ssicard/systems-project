#include <string>

#ifndef MESSAGEPROPERTIESLOOKUP_H
#define MESSAGEPROPERTIESLOOKUP_H

class MessagePropertiesLookup {
public:
	MessagePropertiesLookup(int RequirementType, std::string RequirementDesc) :
							RequirementType(RequirementType), RequirementDesc(RequirementDesc) {}
	~MessagePropertiesLookup() {}

	int RequirementType;
	std::string RequirementDesc;
};
#endif /* MESSAGEPROPERTIESLOOKUP_H */
