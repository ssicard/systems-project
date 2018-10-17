#pragma once
#include "MessageProperties.h"


MessageProperties::MessageProperties(int id, string messageTypeName)
{
	this->id = id;
	this->MessageTypeName = messageTypeName;
}


MessageProperties::~MessageProperties()
{
}
