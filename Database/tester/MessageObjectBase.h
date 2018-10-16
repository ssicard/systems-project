#include <string>
#pragma once
using namespace std;
#include "AssignmentInformation.h"
#include "AssignmentInstructions.h"
#include "ContactInformationType.h"
#include "ContactRoleLookup.h"
#include "Funding.h"
#include "IncidentInformation.h"
#include "LocationType.h"
#include "MessageProperties.h"
#include "MessagePropertiesLookup.h"
#include "MessageRecall.h"
#include "OwnershipInformation.h"
#include "RadioElement.h"
#include "Resource.h"
#include "ResourceInformation.h"
#include "ResourceMessage.h"
#include "ResourceStatus.h"
#include "ResponseInformation.h"
#include "ResponseTypeLookup.h"
#include "ScheduleInformation.h"
#include "TypeInfoType.h"
#include "ValueListType.h"
#include "SqlBase"
class MessageObjectBase: public SqlBase
{
	public:
		MessageObjectBase();
		MessageProperties MessageProperties;
		ResourceMessage ResourceMessage;
        void getFromDatabase();
        void updateToDatabase();
        bool areFieldsValid();
        bool getResourceMessage(string MessageObjectName);

};

