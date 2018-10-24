#include <string>
#ifndef MESSAGEPROPERTIES_H
#define MESSAGEPROPERTIES_H
#include <string>
#include "SqlBase.h"
#include "MessagePropertiesLookup.h"

class MessageProperties : public SqlBase
{
public:
	MessageProperties(int id, std::string messageTypeName);
	MessageProperties();
	~MessageProperties();
	int id;
	std::string MessageTypeName;
	int MessageID=0;
	int SentDateTime=0;
	int MessageContentType = 0;
	int MessageDescription = 0;
	int OriginatingMessageID = 0;
	int PrecedingMessageID = 0;
	int IncidentInformation = 0;
	int MessageRecall = 0;
	int Funding = 0;
	int ContactInformation = 0;
	int ResourceInformation = 0;
	int IncidentID = 0;
	int IncidentDescription = 0;
	int RecalledMessageID = 0;
	int RecallType = 0;
	int FundCode = 0;
	int FundingInfo = 0;
	int ResourceInfoElementID = 0;
	int ResponseInformation = 0;
	int Resource = 0;
	int AssignmentInformation = 0;
	int ScheduleInformation = 0;
	int PrecedingResourceInfoElementID = 0;
	int ResponseType = 0;
	int ReasonCode = 0;
	int ResponseReason = 0;
	int ResourceID = 0;
	int Name = 0;
	int TypeStructure = 0;
	int TypeInfo = 0;
	int Keyword = 0;
	int Description = 0;
	int Credentials = 0;
	int Certifications = 0;
	int SpecialRequirements = 0;
	int ResponsibleParty = 0;
	int OwnershipInformation = 0;
	int HomeDispatch = 0;
	int HomeUnit = 0;
	int InventoryRefreshDateTime = 0;
	int DeploymentStatus = 0;
	int Availability = 0;
	int Quanitity = 0;
	int Restrictions = 0;
	int AnticipatedFunction = 0;
	int PriceQuote = 0;
	int OrderID = 0;
	int AssignmentInstructions = 0;
	int ModeOfTransportation = 0;
	int NavigationInstructions = 0;
	int ReportingInstructions = 0;
	int ScheduleType = 0;
	int DateTime = 0;
	int Location = 0;
	int MessagePropertyLookupID = 0;
};
#endif
