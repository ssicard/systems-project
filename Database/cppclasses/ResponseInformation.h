#include <string>
#pragma once
using namespace std;
class ResponseInformation
{
public:
	ResponseInformation(string precedingResourceInfoElementID);
	~ResponseInformation();
	string PrecedingResourceInfoElementID;
	int ResponseTypeID;
	int ReasonCodeID;
	string ResponseReason;
};

