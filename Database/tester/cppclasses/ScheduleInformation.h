#ifndef SCHEDULE_INFORMATION_H
#define SCHEDULE_INFORMATION_H

#include <string>
#include "SqlBase.h"
#include "LocationType.h"

class ScheduleInformation: public SqlBase
{
public:
	ScheduleInformation(int scheduleInformationID);
	ScheduleInformation();
	~ScheduleInformation();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ScheduleInformationID;
	std::string ScheduleType;
	std::string DateTime;
	int LocationTypeID;

	LocationType _Location;
};

#endif
