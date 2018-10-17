#include <string>
#include "SqlBase.h"
#pragma once
using namespace std;
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
	string Owner;
	string OwningJurisdiction;
	string HomeDispatch;
	string HomeUnit;
};

