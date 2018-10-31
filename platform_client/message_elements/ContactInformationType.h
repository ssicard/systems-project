#include <string>
#ifndef CONTACTINFORMATIONTYPE_H
#define CONTACTINFORMATIONTYPE_H
using namespace std;
class ContactInformationType
{
public:
	ContactInformationType(int ContactInformationID = 0) : ContactInformationID(ContactInformationID) {}
	~ContactInformationType() {}
	int ContactInformationID;
	string ContactDescription;
	int ContactRole;
	int ContactLocationID;
	string AdditionalContactInformation;
};
#endif
