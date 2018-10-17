#ifndef MESSAGE_PROPERTIES_LOOKUP_H
#define MESSAGE_PROPERTIES_LOOKUP_H

#include "SqlBase.h"
#include <string>
// #pragma once
using namespace std;
class MessagePropertiesLookup : public SqlBase
{
public:
	MessagePropertiesLookup(int requirementType);
	~MessagePropertiesLookup();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int RequirementType;
	string RequirementDesc;
};

#endif