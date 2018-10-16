#include <string>
#pragma once
using namespace std;
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

    ValueListType DeploymentStatus;


};

