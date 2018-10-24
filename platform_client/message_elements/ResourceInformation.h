#include <string>
#include "SqlBase.h"
#include "./ResponseInformation.h"
#include "./Resource.h"
#include "./AssignmentInformation.h"
#include "./ScheduleInformation.h"

#ifndef RESOURCEINFORMATION_H
#define RESOURCEINFORMATION_H

class ResourceInformation : public SqlBase
{
public:
	ResourceInformation(std::string ResourceInfoElementID = "", std::string ResponseInformation = "") :
                            ResourceInfoElementID(std::move(ResourceInfoElementID)), ResponseInformation(std::move(ResponseInformation)) {}
	~ResourceInformation() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	std::string ResourceInfoElementID;
	std::string ResponseInformation;
	Resource res;
	AssignmentInformation assign_info;
	ScheduleInformation sched_info;

	// TODO: Change this
	std::string ResourceID;
	std::string ResponseInformationID;
	int AssignmentInformationID;
	int ScheduleInformationID;
	platform::ResponseInformation _ResponseInformation;
	Resource _Resource;
	AssignmentInformation _AssignmentInformation;
	ScheduleInformation _ScheduleInformation;
};
#endif /* RESOURCEINFORMATION_H */
