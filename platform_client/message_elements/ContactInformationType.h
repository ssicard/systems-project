#include <string>

#ifndef CONTACTINFORMATIONTYPE_H
#define CONTACTINFORMATIONTYPE_H

class ContactInformationType {
public:
	ContactInformationType(int ContactInformationID, std::string ContactDescription,
							int ContactRole, int ContactLocationID), std::string AdditionalContactInformation :
							ContactInformationID(ContactInformationID),	ContactDescription(ContactDescription),
							ContactRole(ContactRole), ContactLocationID(ContactLocationID),
							AdditionalContactInformation(AdditionalContactInformation) {}
	~ContactInformationType() {}

	int ContactInformationID;
	std::string ContactDescription;
	int ContactRole;
	int ContactLocationID;
	std::string AdditionalContactInformation;
};
#endif /* CONTACTINFORMATIONTYPE_H */
