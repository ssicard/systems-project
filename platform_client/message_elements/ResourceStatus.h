#include <string>
#include "SqlBase.h"
#include "ValueListType.h"

#ifndef RESOURCESTATUS_H
#define RESOURCESTATUS_H

class ResourceStatus : public SqlBase
{
public:
	ResourceStatus(int resourceStatusID = -1) : ResourceStatusID{resourceStatusID} {}
	~ResourceStatus() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ResourceStatusID;
	int InventoryRefreshDateTime;
	int DeploymentStatus;
	std::string Availability;
	std::string HomeUnit;

	// TODO: Change this
	std::string _InventoryRefreshDateTime;

	ValueListType _DeploymentStatus;
};
#endif
