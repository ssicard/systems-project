#include <string>
#pragma once
#include "cppclasses/SqlBase.h"
using namespace std;
#include "cppclasses/AssignmentInformation.h"
#include "cppclasses/AssignmentInstructions.h"
#include "cppclasses/ContactInformationType.h"
#include "cppclasses/ContactRoleLookup.h"
#include "cppclasses/Funding.h"
#include "cppclasses/IncidentInformation.h"
#include "cppclasses/LocationType.h"
#include "cppclasses/MessageProperties.h"
#include "cppclasses/MessagePropertiesLookup.h"
#include "cppclasses/MessageRecall.h"
#include "cppclasses/OwnershipInformation.h"
#include "cppclasses/RadioElement.h"
#include "cppclasses/Resource.h"
#include "cppclasses/ResourceInformation.h"
#include "cppclasses/ResourceMessage.h"
#include "cppclasses/ResourceStatus.h"
#include "cppclasses/ResponseInformation.h"
#include "cppclasses/ResponseTypeLookup.h"
#include "cppclasses/ScheduleInformation.h"
#include "cppclasses/TypeInfoType.h"
#include "cppclasses/ValueListType.h"

class MessageObjectBase: public SqlBase
{
	public:
		MessageObjectBase();
		MessageProperties _MessageProperties;
		ResourceMessage _ResourceMessage;
        void getFromDatabase();
        void insertIntoDatabase();
        bool areFieldsValid();
        bool getResourceMessage(string MessageObjectName);

};

