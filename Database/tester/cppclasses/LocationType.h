#ifndef LOCATION_TYPE_H
#define LOCATION_TYPE_H

#include <string>
#include "SqlBase.h"

class LocationType: public SqlBase
{
public:
	LocationType();
	LocationType(int locationTypeID);
	~LocationType();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int LocationTypeID;
	std::string LocationDescription;
	std::string Address;
	std::string TargetArea;
};

#endif
