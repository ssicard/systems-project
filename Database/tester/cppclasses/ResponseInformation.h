#include <string>
#pragma once
using namespace std;
#include "ValueListType.h"
class ResponseInformation
{
public:
	ResponseInformation(string precedingResourceInfoElementID);
	~ResponseInformation();
	string PrecedingResourceInfoElementID;
	int ResponseTypeID;
	int ReasonCodeID;
	string ResponseReason;

	ValueListType _ReasonCode;
};

