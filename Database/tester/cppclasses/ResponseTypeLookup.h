#ifndef RESPONSE_TYPE_LOOKUP_H
#define RESPONSE_TYPE_LOOKUP_H

#include <string>
#include "SqlBase.h"

class ResponseTypeLookup : public SqlBase
{
public:
	ResponseTypeLookup(int responseTypeID);
	~ResponseTypeLookup();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ResponseTypeID;
	std::string Description;
};

#endif
