#include <string>

#ifndef CONTACTROLELOOKUP_H
#define CONTACTROLELOOKUP_H

class ContactRoleLookup {
public:
	ContactRoleLookup(std::string ContactRoleID = "", std::string Description = "") :
										ContactRoleID(ContactRoleID), Description(Description) {}
	~ContactRoleLookup() {}

	std::string ContactRoleID;
	std::string Description;
};
#endif /* CONTACTROLELOOKUP_H */
