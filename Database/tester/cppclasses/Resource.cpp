#pragma once
#include "Resource.h"


Resource::Resource(string resourceID)
{
	this->ResourceID = resourceID;
}

Resource::Resource()
{
	this->ResourceID = -1;
}



Resource::~Resource()
{
}
