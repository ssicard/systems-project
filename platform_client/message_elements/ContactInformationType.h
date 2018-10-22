#include <string>

#ifndef CONTACTINFORMATIONTYPE_H
#define CONTACTINFORMATIONTYPE_H

class ContactInformationType {
public:
	ContactInformationType(std::string ContactInformationID = "", std::string ContactDescription = "",
													std::string ContactRole = "", std::string ContactLocationID = "", std::string AdditionalContactInformation = "") :
													ContactInformationID(ContactInformationID),	ContactDescription(ContactDescription),
													ContactRole(ContactRole), ContactLocationID(ContactLocationID),
													AdditionalContactInformation(AdditionalContactInformation) {}
	~ContactInformationType() {}

	std::string ContactInformationID;
	std::string ContactDescription;
	std::string ContactRole;
	std::string ContactLocationID;
	std::string AdditionalContactInformation;
};
#endif /* CONTACTINFORMATIONTYPE_H */
