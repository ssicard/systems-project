#include <string>
#pragma once
using namespace std;
class ScheduleInformation
{
public:
	ScheduleInformation(int scheduleInformationID);
	~ScheduleInformation();
	int ScheduleInformationID;
	string ScheduleType;
	int DateTime;
	int LocationTypeID;

	LocationType Location;

};

