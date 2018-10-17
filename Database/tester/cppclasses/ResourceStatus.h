#include <string>
#pragma once
using namespace std;

#include "ValueListType.h"

class ResourceStatus
{
public:
	ResourceStatus(int resourceStatusID);
	~ResourceStatus();
	int ResourceStatusID;
	int InventoryRefreshDateTime;
	int DeploymentStatus;
	string Availability;
	string HomeUnit;

    ValueListType _DeploymentStatus;


};

