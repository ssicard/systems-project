#include <string>

#ifndef RESOURCE_H
#define RESOURCE_H

class Resource {
public:
	Resource(std::string ResourceID, std::string NAME, int TypeStructureID, int TypeInfoID,
				int KeywordID, std::string Description, std::string Credentials,
				std::string Certifications, std::string SpecialRequirements, int ResponsiblePartyID,
				int OwnershipInformationID, int ResourceStatusID) : ResourceID(ResourceID),
				NAME(NAME), TypeStructureID(TypeStructureID), TypeInfoID(TypeInfoID),
				KeywordID(KeywordID), Description(Description), Credentials(Credentials),
				Certifications(Certifications), SpecialRequirements(SpecialRequirements),
				ResponsiblePartyID(ResponsiblePartyID), OwnershipInformationID(OwnershipInformationID),
				ResourceStatusID(ResourceStatusID) {}
	~Resource() {}

	std::string ResourceID;
	std::string NAME;
	int TypeStructureID;
	int TypeInfoID;
	int KeywordID;
	std::string Description;
	std::string Credentials;
	std::string Certifications;
	std::string SpecialRequirements;
	int ResponsiblePartyID;
	int OwnershipInformationID;
	int ResourceStatusID;
};
#endif /* RESOURCE_H */
