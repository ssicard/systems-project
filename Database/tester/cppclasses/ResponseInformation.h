#include <string>
#pragma once
using namespace std;
#include "ValueListType.cpp"
class ResponseInformation
{
public:
	ResponseInformation(string precedingResourceInfoElementID);
	ResponseInformation();
	~ResponseInformation();

	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	string PrecedingResourceInfoElementID;
	int ResponseTypeID;
	int ReasonCodeID;
	string ResponseReason;

	ValueListType _ReasonCode;
};

