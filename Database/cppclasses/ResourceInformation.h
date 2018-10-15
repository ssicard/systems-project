#include <string>
#pragma once
using namespace std;
class ResourceInformation
{
public:
	ResourceInformation(string resourceInfoElementID);
	~ResourceInformation();
	string ResourceInfoElementID;
	string ResponseInformation;
	string Resource;
	int AssignmentInformationID;
	int ScheduleInformationID;
};

