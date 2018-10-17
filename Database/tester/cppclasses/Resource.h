#include <string>
#pragma once
using namespace std;
#include "ValueListType.cpp"
#include "TypeInfoType.cpp"
#include "ValueListType.cpp"
#include "ContactInformationType.cpp"
#include "OwnershipInformation.cpp"
#include "ResourceStatus.cpp"
class Resource: public SqlBase
{
public:
	Resource(string resourceID);
	Resource();
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

