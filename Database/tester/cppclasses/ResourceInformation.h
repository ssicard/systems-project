#include <string>
#pragma once
using namespace std;
#include "ResponseInformation.cpp"
#include "Resource.cpp"
#include "AssignmentInformation.cpp"
#include "ScheduleInformation.cpp"
class ResourceInformation: public SqlBase
{
public:
	ResourceInformation(string resourceInfoElementID);
	~ResourceInformation();
	string ResourceInfoElementID;
	string ResponseInformationID;
	string ResourceID;
	int AssignmentInformationID;
	int ScheduleInformationID;

    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	ResponseInformation _ResponseInformation;
	Resource _Resource;
	AssignmentInformation _AssignmentInformation;
	ScheduleInformation _ScheduleInformation;

};

