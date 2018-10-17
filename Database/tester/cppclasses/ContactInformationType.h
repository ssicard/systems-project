#include <string>
#pragma once
using namespace std;
class ContactInformationType: public SqlBase
{
public:
	ContactInformationType(int contactInformationID);
	ContactInformationType();
	~ContactInformationType();
	int ContactInformationID;
	string ContactDescription;
	int ContactRole;
	int ContactLocationID;
	string AdditionalContactInformation;
};

