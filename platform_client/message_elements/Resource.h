#include <string>
#include "./OwnershipInformation.h"
#include "./ResourceStatus.h"

#ifndef RESOURCE_H
#define RESOURCE_H
class Resource
{
public:
	Resource(std::string ResourceID = "", std::string Name = "", std::string TypeStructure = "",
                 std::string TypeInfo = "", std::string Keyword = "", std::string Description = "", std::string Credentials = "",
                 std::string Certifications = "", std::string SpecialRequirements = "", std::string ResponsibleParty = "") :
                 ResourceID(ResourceID), Name(Name), TypeStructure(TypeStructure),
                 TypeInfo(TypeInfo), Keyword(Keyword), Description(Description),
                 Credentials(Credentials), Certifications(Certifications), SpecialRequirements(SpecialRequirements),
                 ResponsibleParty(ResponsibleParty) {}
	~Resource() {}
	std::string ResourceID;
	std::string Name;
	std::string TypeStructure;
	std::string TypeInfo;
	std::string Keyword;
	std::string Description;
	std::string Credentials;
	std::string Certifications;
	std::string SpecialRequirements;
	std::string ResponsibleParty;
	OwnershipInformation own_info;
	ResourceStatus res_stat;
};
#endif /* RESOURCE_H */
