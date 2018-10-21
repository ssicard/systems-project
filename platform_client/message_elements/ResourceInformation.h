#include <string>

#ifndef RESOURCEINFORMATION_H
#define RESOURCEINFORMATION_H
class ResourceInformation
{
public:
	ResourceInformation(std::string ResourceInfoElementID = "", std::string ResourceInformation = "",
                            std::string Resource = "", int AssignmentInformationID = 0, int ScheduleInformationID = 0) :
                            ResourceInfoElementID(std::move(ResourceInfoElementID)), ResponseInformation(std::move(ResponseInformation)),
                            Resource(std::move(Resource)), AssignmentInformationID(std::move(AssignmentInformationID)), ScheduleInformationID(std::move(ScheduleInformationID)) {}
	~ResourceInformation() {}

	std::string ResourceInfoElementID;
	std::string ResponseInformation;
	std::string Resource;
	int AssignmentInformationID;
	int ScheduleInformationID;
};
#endif /* RESOURCEINFORMATION_H */
