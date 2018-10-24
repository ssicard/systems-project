#include <string>
#include "SqlBase.h"
#ifndef OWNERSHIPINFORMATION_H
#define OWNERSHIPINFORMATION_H
using namespace std;
class OwnershipInformation
{
public:
	OwnershipInformation(int ownershipInformationID = -1) {}
	~OwnershipInformation() {}
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int OwnershipInformationID;
	string Owner;
	string OwningJurisdiction;
	string HomeDispatch;
	string HomeUnit;
};
#endif
