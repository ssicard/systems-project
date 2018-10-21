#include <string>
#include "./Resource.h"
#include "./AssignmentInformation.h"
#include "./ScheduleInformation.h"


#ifndef RESOURCEINFORMATION_H
#define RESOURCEINFORMATION_H
class ResourceInformation
{
public:
	ResourceInformation(std::string ResourceInfoElementID = "", std::string ResponseInformation = "") :
                            ResourceInfoElementID(std::move(ResourceInfoElementID)), ResponseInformation(std::move(ResponseInformation)) {}
	~ResourceInformation() {}

	std::string ResourceInfoElementID;
	std::string ResponseInformation;
	Resource res;
	AssignmentInformation assign_info;
	ScheduleInformation sched_info;
};
#endif /* RESOURCEINFORMATION_H */
