#ifndef RESOURCE_STATUS_H
#define RESOURCE_STATUS_H

#include <string>
#include "SqlBase.h"
// #pragma once
using namespace std;
class ResourceStatus : public SqlBase
{
public:
	ResourceStatus(int resourceStatusID);
	~ResourceStatus();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ResourceStatusID;
	int InventoryRefreshDateTime;
	int DeploymentStatus;
	string Availability;
	string HomeUnit;

    ValueListType DeploymentStatus;


};

#endif