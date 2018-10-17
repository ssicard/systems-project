#pragma once
#include <string>
#include "SqlBase.h"

using namespace std;
#include "LocationType.cpp"
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
	string ScheduleType;
	string DateTime;
	int LocationTypeID;

	LocationType _Location;

};

