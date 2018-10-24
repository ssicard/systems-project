#include <string>
#include "SqlBase.h"

#ifndef LOCATIONTYPE_H
#define LOCATIONTYPE_H

class LocationType : public SqlBase {
public:
	LocationType();
	LocationType(int locationTypeID);
	LocationType(int LocationTypeID, std::string LocationDescription, std::string Address,
					std::string TargetArea) : LocationTypeID(LocationTypeID), LocationDescription(LocationDescription),
					Address(Address), TargetArea(TargetArea) {}
	~LocationType() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int LocationTypeID;
	std::string LocationDescription;
	std::string Address;
	std::string TargetArea;
};
#endif /* LOCATIONTYPE_H */
