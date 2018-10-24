#include <string>
#include "SqlBase.h"
#include "ValueListType.h"
#include "TypeInfoType.h"
#include "ValueListType.h"
#include "ContactInformationType.h"
#include "OwnershipInformation.h"
#include "ResourceStatus.h"

#ifndef RESOURCE_H
#define RESOURCE_H
class Resource : public SqlBase
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
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
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

	// TODO: Change this
	int TypeStructureID;
	int TypeInfoID;
	int KeywordID;
	int ResponsiblePartyID;
	int OwnershipInformationID;
	int ResourceStatusID;

	ValueListType _TypeStructure;
	TypeInfoType _TypeInfo;
	ValueListType _Keyword;
	ContactInformationType _ResponsibleParty;
	OwnershipInformation _OwnershipInformation;
	ResourceStatus _ResourceStatus;
};
#endif /* RESOURCE_H */
