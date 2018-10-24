#include <string>
#include "SqlBase.h"

#ifndef MESSAGEPROPERTIESLOOKUP_H
#define MESSAGEPROPERTIESLOOKUP_H

class MessagePropertiesLookup : public SqlBase {
public:
	MessagePropertiesLookup(int RequirementType = -1, std::string RequirementDesc = "") :
							RequirementType(RequirementType), RequirementDesc(RequirementDesc) {}
	~MessagePropertiesLookup() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int RequirementType;
	std::string RequirementDesc;
};
#endif /* MESSAGEPROPERTIESLOOKUP_H */
