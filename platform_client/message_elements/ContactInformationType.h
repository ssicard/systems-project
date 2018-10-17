#include <string>
#pragma once
using namespace std;
class ContactInformationType
{
public:
	ContactInformationType(int contactInformationID);
	~ContactInformationType();
	int ContactInformationID;
	string ContactDescription;
	int ContactRole;
	int ContactLocationID;
	string AdditionalContactInformation;
};

