#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include "SqlBase.h"
#include "ValueListType.h"
#include "TypeInfoType.h"
#include "ValueListType.h"
#include "ContactInformationType.h"
#include "OwnershipInformation.h"
#include "ResourceStatus.h"

class Resource: public SqlBase
{
public:
	Resource(std::string resourceID);
	Resource();
	~Resource();
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

	void getFromDatabase();
	void insertIntoDatabase();
	bool areFieldsValid();

	ValueListType _TypeStructure;
	TypeInfoType _TypeInfo;
	ValueListType _Keyword;
	ContactInformationType _ResponsibleParty;
	OwnershipInformation _OwnershipInformation;
	ResourceStatus _ResourceStatus;
};

#endif

