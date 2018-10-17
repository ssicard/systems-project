#include <string>
#pragma once
using namespace std;
#include "ValueListType.h"
#include "TypeInfoType.h"
#include "ValueListType.h"
#include "ContactInformationType.h"
#include "OwnershipInformation.h"
#include "ResourceStatus.h"
class Resource
{
public:
	Resource(string resourceID);
	~Resource();
	string ResourceID;
	string NAME;
	int TypeStructureID;
	int TypeInfoID;
	int KeywordID;
	string Description;
	string Credentials;
	string Certifications;
	string SpecialRequirements;
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

