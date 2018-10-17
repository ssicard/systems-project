#include <string>
#include "SqlBase.h"
#pragma once
using namespace std;
#include "LocationType.h"
class ScheduleInformation: public SqlBase
{
public:
	ScheduleInformation(int scheduleInformationID);
	~ScheduleInformation();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ScheduleInformationID;
	string ScheduleType;
	int DateTime;
	int LocationTypeID;

	LocationType _Location;

};

