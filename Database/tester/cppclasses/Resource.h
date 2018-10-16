#include <string>
#pragma once
using namespace std;
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

	ValueListType TypeStructure;
	TypeInfoType TypeInfo;
	ValueListType Keyword;
	ContactInformationType ResponsibleParty;
	OwnershipInformation OwnershipInformation;
	ResourceStatus ResourceStatus;



};

