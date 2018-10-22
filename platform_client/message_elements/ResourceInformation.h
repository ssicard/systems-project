#include <string>

#ifndef RESOURCEINFORMATION_H
#define RESOURCEINFORMATION_H

class ResourceInformation {
public:
	ResourceInformation(std::string ResourceInfoElementID, std::string ResponseInformation,
                            std::string Resource, int AssignmentInformationID, int ScheduleInformationID) :
                            ResourceInfoElementID(ResourceInfoElementID), ResponseInformation(ResponseInformation),
                            Resource(Resource), AssignmentInformationID(AssignmentInformationID), ScheduleInformationID(ScheduleInformationID) {}
	~ResourceInformation() {}

	std::string ResourceInfoElementID;
	std::string ResponseInformation;
	std::string Resource;
	int AssignmentInformationID;
	int ScheduleInformationID;
};
#endif /* RESOURCEINFORMATION_H */
