#include <string>
#pragma once
using namespace std;
class LocationType
{
public:
	LocationType(int locationTypeID);
	~LocationType();
	int LocationTypeID;
	string LocationDescription;
	string Address;
	string TargetArea;
};

