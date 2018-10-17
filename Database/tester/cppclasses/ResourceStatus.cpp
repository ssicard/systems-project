#pragma once
#include "ResourceStatus.h"


ResourceStatus::ResourceStatus(int resourceStatusID)
{
	this->ResourceStatusID = resourceStatusID;
}

ResourceStatus::ResourceStatus()
{
	this->ResourceStatusID = -1;
}


ResourceStatus::~ResourceStatus()
{
}

void ResourceStatus::getFromDatabase() {

}

void ResourceStatus::insertIntoDatabase() {

}

bool ResourceStatus::areFieldsValid() {
	return false;
}