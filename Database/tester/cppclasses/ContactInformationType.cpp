#pragma once
#include "ContactInformationType.h"


ContactInformationType::ContactInformationType(int contactInformationID)
{
	this->ContactInformationID = contactInformationID;
}

ContactInformationType::ContactInformationType()
{
	this->ContactInformationID = -1;
}

ContactInformationType::~ContactInformationType()
{
}
