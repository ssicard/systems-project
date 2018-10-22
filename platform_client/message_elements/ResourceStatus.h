#include <string>

#ifndef RESOURCESTATUS_H
#define RESOURCESTATUS_H

class ResourceStatus {
public:
	ResourceStatus(int ResourceStatusID, int InventoryRefreshDateTime, int DeploymentStatus,
					std::string Availability, std::string HomeUnit) : ResourceStatusID(ResourceStatusID),
					InventoryRefreshDateTime(InventoryRefreshDateTime), DeploymentStatus(DeploymentStatus),
					Availability(Availability), HomeUnit(HomeUnit) {}
	~ResourceStatus() {}

	int ResourceStatusID;
	int InventoryRefreshDateTime;
	int DeploymentStatus;
	std::string Availability;
	std::string HomeUnit;
};
#endif /* RESOURCESTATUS_H */
