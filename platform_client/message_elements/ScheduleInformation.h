#include <string>

#ifndef SCHEDULEINFORMATION_H
#define SCHEDULEINFORMATION_H

class ScheduleInformation
{
public:
	ScheduleInformation(std::string ScheduleType = "", std::string DateTime = "", std::string Location = "") :
                            ScheduleType(ScheduleType), DateTime(DateTime), Location(Location) {}
	~ScheduleInformation() {}
	std::string ScheduleType;
	std::string DateTime;
        std::string Location;
};
#endif /* SCHEDULEINFORMATION_H */
