#ifndef OWNERSHIP_INFORMATION_H
#define OWNERSHIP_INFORMATION_H

#include <string>
#include "SqlBase.h"

class OwnershipInformation: public SqlBase
{
public:
	OwnershipInformation(int ownershipInformationID);
	OwnershipInformation();
	~OwnershipInformation();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int OwnershipInformationID;
	std::string Owner;
	std::string OwningJurisdiction;
	std::string HomeDispatch;
	std::string HomeUnit;
};

#endif
