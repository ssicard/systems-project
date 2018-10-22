#include <string>
#pragma once
using namespace std;
class ResourceStatus
{
public:
	ResourceStatus(int resourceStatusID=0) {}
	~ResourceStatus() {}
	int ResourceStatusID;
	int InventoryRefreshDateTime;
	int DeploymentStatus;
	string Availability;
	string HomeUnit;
};

