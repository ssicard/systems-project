#include <string>
#pragma once
using namespace std;
class MessagePropertiesLookup
{
public:
	MessagePropertiesLookup(int requirementType);
	~MessagePropertiesLookup();
	int RequirementType;
	string RequirementDesc;
};

