#include <string>

#ifndef SCHEDULEINFORMATION_H
#define SCHEDULEINFORMATION_H

class ScheduleInformation {
public:
	ScheduleInformation(int ScheduleInformationID, std::string ScheduleType, int DateTime,
						int LocationTypeID) : ScheduleInformationID(ScheduleInformationID),
						ScheduleType(ScheduleType), DateTime(DateTime), LocationTypeID(LocationTypeID) {}
	~ScheduleInformation() {}

	int ScheduleInformationID;
	std::string ScheduleType;
	int DateTime;
	int LocationTypeID;
};
#endif /* SCHEDULEINFORMATION_H */
