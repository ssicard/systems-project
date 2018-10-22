#include <string>

#ifndef CONTACTROLELOOKUP_H
#define CONTACTROLELOOKUP_H

class ContactRoleLookup {
public:
	ContactRoleLookup(int ContactRoleID, std::string Description) : ContactRoleID(ContactRoleID),
						Description(Description) {}
	~ContactRoleLookup() {}

	int ContactRoleID;
	std::string Description;
};
#endif /* CONTACTROLELOOKUP_H */
