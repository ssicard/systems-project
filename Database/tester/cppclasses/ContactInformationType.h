#ifndef CONTACT_INFORMATION_TYPE_H
#define CONTACT_INFORMATION_TYPE_H

#include <string>
#include "SqlBase.h"
#include "ContactRoleLookup.h"
#include "LocationType.h"

class ContactInformationType: public SqlBase
{
public:
	ContactInformationType(int contactInformationID);
	ContactInformationType();
	~ContactInformationType();
	int ContactInformationID;
	std::string ContactDescription;
	int ContactRole;
	int ContactLocationID;
	std::string AdditionalContactInformation;

    void getFromDatabase();
    void insertIntoDatabase();
	bool areFieldsValid();  
	ContactRoleLookup contactRoleLookup{ContactRole};
	LocationType contactLocation{ContactLocationID};
};

#endif
