#include <string>
#ifndef RESOURCESTATUS_H
#define RESOURCESTATUS_H
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
#endif
