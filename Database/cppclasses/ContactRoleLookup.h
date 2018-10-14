#include <string>
#pragma once
using namespace std;
class ContactRoleLookup
{
public:
	ContactRoleLookup(int contactRoleID);
	~ContactRoleLookup();
	int ContactRoleID;
	string Description;
};

