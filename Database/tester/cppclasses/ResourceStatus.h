#include <string>
#pragma once
using namespace std;

#include "ValueListType.h"

class ResourceStatus
class ResourceStatus : public SqlBase
{
public:
	ResourceStatus(int resourceStatusID);
	ResourceStatus();
	~ResourceStatus();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ResourceStatusID;
	int InventoryRefreshDateTime;
	int DeploymentStatus;
	string Availability;
	string HomeUnit;

    ValueListType _DeploymentStatus;


};

