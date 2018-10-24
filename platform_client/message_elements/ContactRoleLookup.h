#include <string>
#include "SqlBase.h"

#ifndef CONTACTROLELOOKUP_H
#define CONTACTROLELOOKUP_H

class ContactRoleLookup : public SqlBase
{
public:
	ContactRoleLookup(int ContactRoleID = -1, std::string Description = "") : ContactRoleID(ContactRoleID),
						Description(Description) {}
	~ContactRoleLookup() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int ContactRoleID;
	std::string Description;
};
#endif /* CONTACTROLELOOKUP_H */
