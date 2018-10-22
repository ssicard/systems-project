#include <string>

#ifndef OWNERSHIPINFORMATION_H
#define OWNERSHIPINFORMATION_H

class OwnershipInformation {
public:
	OwnershipInformation(std::string OwnershipInformationID = "", std::string Owner = "",
												std::string OwningJurisdiction = "", std::string HomeDispatch = ""
												std::string HomeUnit = "") : OwnershipInformationID(OwnershipInformationID),
												Owner(Owner), OwningJurisdiction(OwningJurisdiction), HomeDispatch(HomeDispatch),
												HomeUnit(HomeUnit) {}
	~OwnershipInformation() {}

	std::string OwnershipInformationID;
	std::string Owner;
	std::string OwningJurisdiction;
	std::string HomeDispatch;
	std::string HomeUnit;
};
#endif /* OWNERSHIPINFORMATION_H */
