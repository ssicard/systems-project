#pragma once
#include "ResourceMessage.h"


ResourceMessage::ResourceMessage(string messageID)
{
	this->MessageID = messageID;
}

ResourceMessage::ResourceMessage()
{
	this->MessageID = "";
}


ResourceMessage::~ResourceMessage()
{
}
