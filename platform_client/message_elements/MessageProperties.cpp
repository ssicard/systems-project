#include "MessageProperties.h"


MessageProperties::MessageProperties(int id, std::string messageTypeName)
{
	this->id = id;
	this->MessageTypeName = messageTypeName;
}


MessageProperties::~MessageProperties()
{
}
