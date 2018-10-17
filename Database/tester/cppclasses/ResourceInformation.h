#include <string>
#pragma once
using namespace std;
#include "ResponseInformation.h"
#include "Resource.h"
#include "AssignmentInformation.h"
#include "ScheduleInformation.h"
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

	ResponseInformation _ResponseInformation;
	Resource _Resource;
	AssignmentInformation _AssignmentInformation;
	ScheduleInformation _ScheduleInformation;

};

