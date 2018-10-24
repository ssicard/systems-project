#include <string>
#include "SqlBase.h"
#include "LocationType.h"

#ifndef SCHEDULEINFORMATION_H
#define SCHEDULEINFORMATION_H

class ScheduleInformation : public SqlBase
{
public:
	ScheduleInformation(int scheduleInformationID);
	ScheduleInformation(std::string ScheduleType = "", std::string DateTime = "", std::string Location = "") :
                            ScheduleType(ScheduleType), DateTime(DateTime), Location(Location) {}
	~ScheduleInformation() {}
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ScheduleInformationID;
	std::string ScheduleType;
	std::string DateTime;
    std::string Location;
	int LocationTypeID;

	LocationType _Location;
};
#endif /* SCHEDULEINFORMATION_H */
