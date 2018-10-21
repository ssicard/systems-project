#include "MessageProperties.h"


MessageProperties::MessageProperties(int id, std::string messageTypeName)
{
	this->id = id;
	this->MessageTypeName = messageTypeName;
}

MessageProperties::MessageProperties()
{
	this->id = -1;
}


MessageProperties::~MessageProperties()
{
}

void MessageProperties::getFromDatabase() {
try {
			sql::Connection *con;
			sql::PreparedStatement *prep_stmt;
			sql::mysql::MySQL_Driver *driver;
			sql::Statement *stmt;
			sql::ResultSet *res;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
			stmt = con->createStatement();
			stmt->execute("USE " EXAMPLE_DB);

			prep_stmt = con->prepareStatement("SELECT * FROM `MessageProperties` WHERE `id` = ?");

			prep_stmt->setInt(1, this->id);

			
			res = prep_stmt->executeQuery();

			while (res->next()) {
				this->id = res->getInt("id");
				this->MessageTypeName = res->getString("MessageTypeName");

				this->MessageID = res->getInt("MessageID");
				this->SentDateTime = res->getInt("SentDateTime");
				this->MessageContentType = res->getInt("MessageContentType");
				this->MessageDescription = res->getInt("MessageDescription");
				this->OriginatingMessageID = res->getInt("OriginatingMessageID");
				this->PrecedingMessageID = res->getInt("PrecedingMessageID");
				this->IncidentInformation = res->getInt("Incident Information");
				this->MessageRecall = res->getInt("MessageRecall");
				this->Funding = res->getInt("Funding");
				this->ContactInformation = res->getInt("ContactInformation");
				this->ResourceInformation = res->getInt("Resource Information");
				this->IncidentID = res->getInt("IncidentID");
				this->IncidentDescription = res->getInt("IncidentDescription");
				this->RecalledMessageID = res->getInt("RecalledMessageID");
				this->RecallType = res->getInt("RecallType");
				this->FundCode = res->getInt("FundCode");
				this->FundingInfo = res->getInt("FundingInfo");
				this->ResourceInfoElementID = res->getInt("ResourceInfoElementID");
				this->ResponseInformation = res->getInt("Response Information");
				this->Resource = res->getInt("Resource");
				this->AssignmentInformation = res->getInt("AssignmentInformation");
				this->ScheduleInformation = res->getInt("ScheduleInformation");
				this->PrecedingResourceInfoElementID = res->getInt("PrecedingResourceInfoElementID");
				this->ResponseType = res->getInt("ResponseType");
				this->ReasonCode = res->getInt("ReasonCode");
				this->ResponseReason = res->getInt("ResponseReason");
				this->ResourceID = res->getInt("ResourceID");
				this->Name = res->getInt("Name");
				this->TypeStructure = res->getInt("TypeStructure");
				this->TypeInfo = res->getInt("TypeInfo");
				this->Keyword = res->getInt("Keyword");
				this->Description = res->getInt("Description");
				this->Credentials = res->getInt("Credentials");
				this->Certifications = res->getInt("Certifications");
				this->SpecialRequirements = res->getInt("SpecialRequirements");
				this->ResponsibleParty = res->getInt("ResponsibleParty");
				this->OwnershipInformation = res->getInt("OwnershipInformation");
				this->ResourceStatus = res->getInt("Resource Status");
				this->Owner = res->getInt("Owner");
				this->OwningJurisdiction = res->getInt("OwningJurisdiction");

				this->HomeDispatch = res->getInt("HomeDispatch");
				this->HomeUnit = res->getInt("HomeUnit");
				this->InventoryRefreshDateTime = res->getInt("InventoryRefreshDateTime");
				this->DeploymentStatus = res->getInt("DeploymentStatus");
				this->Availability = res->getInt("Availability");
				this->Quantity = res->getInt("Quantity");
				this->Restrictions = res->getInt("Restrictions");
				this->AnticipatedFunction = res->getInt("AnticipatedFunction");
				this->PriceQuote = res->getInt("PriceQuote");
				this->OrderID = res->getInt("OrderID");
				this->AssignmentInstructions = res->getInt("Assignment Instructions");
				this->ModeOfTransportation = res->getInt("ModeOfTransportation");
				this->NavigationInstructions = res->getInt("NavigationInstructions");
				this->ReportingInstructions = res->getInt("ReportingInstructions");
				this->ScheduleType = res->getInt("ScheduleType");
				this->DateTime = res->getInt("DateTime");
				this->Location = res->getInt("Location");
				this->MessagePropertyLookupID = res->getInt("MessagePropertyLookupID");
			}

			this->messagePropertiesLookup.RequirementType = this->MessagePropertyLookupID;
			this->messagePropertiesLookup.getFromDatabase();

			delete res;
			delete stmt;
			delete prep_stmt;
			delete con;

		} catch (sql::SQLException &e) {
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

			return;
		}
}

void MessageProperties::insertIntoDatabase() {
try {
			sql::Connection *con;
			sql::PreparedStatement *prep_stmt;
			sql::mysql::MySQL_Driver *driver;
			sql::Statement *stmt;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
			stmt = con->createStatement();
			stmt->execute("USE " EXAMPLE_DB);

			// 58 values?
			std::string prep_stmt_str = std::string("INSERT INTO `MessageProperties` ") + 
			"(`id`, `MessageTypeName`,`MessageID`, `SentDateTime`, `MessageContentType`, " +
			"`MessageDescription`, `OriginatingMessageID`, `PrecedingMessageID`, `Incident Information`, " +
			"`MessageRecall`, `Funding`, `ContactInformation`, `Resource Information`, " +
			"`IncidentID`, `IncidentDescription`, `RecalledMessageID`, `RecallType`, " +
			"`FundCode`, `FundingInfo`, `ResourceInfoElementID`, `Response Information`, " +
			"`Resource`, `AssignmentInformation`, `ScheduleInformation`, `PrecedingResourceInfoElementID`, " +
			"`ResponseType`, `ReasonCode`, `ResponseReason`, `ResourceID`, " +
			"`Name`, `TypeStructure`, `TypeInfo`, `Keyword`, " +
			"`Description`, `Credentials`, `Certifications`, `SpecialRequirements`, " +
			"`ResponsibleParty`, `OwnershipInformation`, " + 
			"`Resource Status`, `Owner`, `OwningJurisdiction`, " +
			"`HomeDispatch`, `HomeUnit`, " +
			"`InventoryRefreshDateTime`, `DeploymentStatus`, `Availability`, `Quantity`, " +
			"`Restrictions`, `AnticipatedFunction`, `PriceQuote`, `OrderID`, " +
			"`Assignment Instructions`, `ModeOfTransportation`, `NavigationInstructions`, `ReportingInstructions`, " +
			"`ScheduleType`, `DateTime`, `Location`, `MessagePropertyLookupID`) " +
			"VALUES (?,?,?,?,?,?,?,?,?,?," +
			"?,?,?,?,?,?,?,?,?,?," +
			"?,?,?,?,?,?,?,?,?,?," +
			"?,?,?,?,?,?,?,?,?,?," +
			"?,?,?,?,?,?,?,?,?,?," +
			"?,?,?,?,?,?,?," +
			"?,?,?" +
			")";

			// prep_stmt = con->prepareStatement("INSERT INTO `AssignmentInstructions`(`AssignmentInstructionsID`, `ModeOfTransportation`,`NavigationInstructions`, `ReportingInstructions`) VALUES (?,?,?,?)");
			prep_stmt = con->prepareStatement(prep_stmt_str);
			prep_stmt->setInt(1, this->id);
			prep_stmt->setString(2, this->MessageTypeName);

			// should be implicit this
			int class_values[] = {
				this->MessageID,
				this->SentDateTime,
				this->MessageContentType,
				this->MessageDescription,
				this->OriginatingMessageID,
				this->PrecedingMessageID,
				this->IncidentInformation,
				this->MessageRecall,
				this->Funding,
				this->ContactInformation,
				this->ResourceInformation,
				this->IncidentID,
				this->IncidentDescription,
				this->RecalledMessageID,
				this->RecallType,
				this->FundCode,
				this->FundingInfo,
				this->ResourceInfoElementID,
				this->ResponseInformation,
				this->Resource,
				this->AssignmentInformation,
				this->ScheduleInformation,
				this->PrecedingResourceInfoElementID,
				this->ResponseType,
				this->ReasonCode,
				this->ResponseReason,
				this->ResourceID,
				this->Name,
				this->TypeStructure,
				this->TypeInfo,
				this->Keyword,
				this->Description,
				this->Credentials,
				this->Certifications,
				this->SpecialRequirements,
				this->ResponsibleParty,
				this->OwnershipInformation,

				// adding these
				this->ResourceStatus,
				this->Owner,
				this->OwningJurisdiction,

				this->HomeDispatch,
				this->HomeUnit,
				this->InventoryRefreshDateTime,
				this->DeploymentStatus,
				this->Availability,
				this->Quantity,
				this->Restrictions,
				this->AnticipatedFunction,
				this->PriceQuote,
				this->OrderID,
				this->AssignmentInstructions,
				this->ModeOfTransportation,
				this->NavigationInstructions,
				this->ReportingInstructions,
				this->ScheduleType,
				this->DateTime,
				this->Location,
				this->MessagePropertyLookupID,
			};

			// TODO: remove magic numbers
			for (unsigned int i = 3; i < 61; ++i) {
				prep_stmt->setInt(i, class_values[i-3]);
			}

			
			

			prep_stmt->execute();

			delete stmt;
			delete prep_stmt;
			delete con;

		} catch (sql::SQLException &e) {
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

			return;
		}
}

bool MessageProperties::areFieldsValid() {
	return false;
}
