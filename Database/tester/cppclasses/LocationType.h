#include <string>
#pragma once
#include "SqlBase.h"
using namespace std;
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
	string LocationDescription;
	string Address;
	string TargetArea;
};

