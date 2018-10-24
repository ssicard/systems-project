#include <string>
#ifndef OWNERSHIPINFORMATION_H
#define OWNERSHIPINFORMATION_H
using namespace std;
class OwnershipInformation
{
public:
	OwnershipInformation(int ownershipInformationID = 0) {}
	~OwnershipInformation() {}
	int OwnershipInformationID;
	string Owner;
	string OwningJurisdiction;
	string HomeDispatch;
	string HomeUnit;
};
#endif
