#ifndef CONTACTROLELOOKUP_H
#define CONTACTROLELOOKUP_H

#include <string>
#include "SqlBase.h"

class ContactRoleLookup : public SqlBase
{
public:
	ContactRoleLookup(int contactRoleID);
	~ContactRoleLookup();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ContactRoleID;
	std::string Description;
};

#endif
