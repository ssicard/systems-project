#ifndef RESOURCE_INFORMATION_H
#define RESOURCE_INFORMATION_H

#include <string>
#include "SqlBase.h"
#include "ResponseInformation.h"
#include "Resource.h"
#include "AssignmentInformation.h"
#include "ScheduleInformation.h"

class ResourceInformation: public SqlBase
{
public:
	ResourceInformation(std::string resourceInfoElementID);
	ResourceInformation();
	~ResourceInformation();
	std::string ResourceInfoElementID;
	std::string ResponseInformationID;
	std::string ResourceID;
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

#endif
