#include <string>
#include "SqlBase.h"
#include "ContactRoleLookup.h"
#include "LocationType.h"

#ifndef CONTACTINFORMATIONTYPE_H
#define CONTACTINFORMATIONTYPE_H


class ContactInformationType : public SqlBase
{
public:
	ContactInformationType(int ContactInformationID = -1) : ContactInformationID(ContactInformationID) {}
	~ContactInformationType() {}
	int ContactInformationID;
	std::string ContactDescription;
	int ContactRole;
	int ContactLocationID;
	std::string AdditionalContactInformation;
    
	void getFromDatabase();
    void insertIntoDatabase();
	bool areFieldsValid();  
	ContactRoleLookup _ContactRoleLookup;
	LocationType _ContactLocation;
};
#endif
