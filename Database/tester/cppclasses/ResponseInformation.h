#ifndef RESPONSE_INFORMATION_H
#define RESPONSE_INFORMATION_H

#include <string>
#include "SqlBase.h"
#include "ValueListType.h"
#include "ResponseTypeLookup.h"

class ResponseInformation: public SqlBase
{
public:
	ResponseInformation(std::string precedingResourceInfoElementID);
	ResponseInformation();
	~ResponseInformation();

	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	std::string PrecedingResourceInfoElementID;
	int ResponseTypeID;
	int ReasonCodeID;
	std::string ResponseReason;

	ValueListType _ReasonCode;
	ResponseTypeLookup _ResponseType;
};

#endif
