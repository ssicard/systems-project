#include <string>

#ifndef LOCATIONTYPE_H
#define LOCATIONTYPE_H

class LocationType {
public:
	LocationType(int LocationTypeID, std::string LocationDescription, std::string Address,
					std::string TargetArea) : LocationTypeID(LocationTypeID), LocationDescription(LocationDescription),
					Address(Address), TargetArea(TargetArea) {}
	~LocationType() {}

	int LocationTypeID;
	std::string LocationDescription;
	std::string Address;
	std::string TargetArea;
};
#endif /* LOCATIONTYPE_H */
