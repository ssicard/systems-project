#include <string>
#include "SqlBase.h"
#include "LocationType.h"

#ifndef SCHEDULEINFORMATION_H
#define SCHEDULEINFORMATION_H

class ScheduleInformation : public SqlBase
{
public:
	//ScheduleInformation(int scheduleInformationID);
	ScheduleInformation(std::string ScheduleType = "", std::string DateTime = "", std::string Location = "",
						int ScheduleInformationID = -1, int LocationTypeID = -1) :
                            ScheduleType(ScheduleType), DateTime(DateTime), 
							Location(Location), ScheduleInformationID{ScheduleInformationID},
							LocationTypeID{LocationTypeID} {}
	~ScheduleInformation() {}
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	
	std::string ScheduleType;
	std::string DateTime;
    std::string Location;
	int ScheduleInformationID;
	int LocationTypeID;

	LocationType _Location;
};
#endif /* SCHEDULEINFORMATION_H */
