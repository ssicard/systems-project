#ifndef RESOURCE_STATUS_H
#define RESOURCE_STATUS_H

#include <string>
#include "SqlBase.h"
#include "ValueListType.h"

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
	std::string InventoryRefreshDateTime;
	int DeploymentStatus;
	std::string Availability;
	std::string HomeUnit;

    ValueListType _DeploymentStatus;
};

#endif
