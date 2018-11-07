#include "ResourceMessage.h"

/*
ResourceMessage::ResourceMessage(std::string messageID)
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
*/

void ResourceMessage::getFromDatabase() {

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

		prep_stmt = con->prepareStatement("SELECT `MessageID`, `SentDateTime`, `MessageContentType`, `MessageDescription`, `OriginatingMessageID`, `PrecedingMessageID`, `IncidentID`, `RecalledMessageID`, `FundCode`, `ContactInformationID`, `ResourceInfoElementID` FROM `ResourceMessage` WHERE `MessageID` = ?");

		prep_stmt->setString(1, this->MessageID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->MessageID = res->getString("MessageID");
			this->_SentDateTime = res->getString("SentDateTime");
			this->MessageContentType = res->getString("MessageContentType");
			this->MessageDescription = res->getString("MessageDescription");
			this->OriginatingMessageID = res->getString("OriginatingMessageID");
			this->PrecedingMessageID = res->getString("PrecedingMessageID");
			this->IncidentID = res->getString("IncidentID");
			this->RecalledMessageID = res->getString("RecalledMessageID");
			this->FundCode = res->getString("FundCode");
			this->_ContactInformationID = res->getInt("ContactInformationID");
			this->ResourceInfoElementID = res->getString("ResourceInfoElementID");		
		}

		delete res;
		delete stmt;
		delete prep_stmt;
		delete con;
		
		this->_IncidentInformation.IncidentID = this->IncidentID;
		this->_IncidentInformation.getFromDatabase();

		this->_MessageRecall.RecalledMessageID = this->RecalledMessageID;
		this->_MessageRecall.getFromDatabase();

		this->_Funding.FundCode = this->FundCode;
		this->_Funding.getFromDatabase();

		this->_ContactInformationType.ContactInformationID = this->_ContactInformationID;
		this->_ContactInformationType.getFromDatabase();

		this->_ResourceInformation.ResourceInfoElementID = this->ResourceInfoElementID;
		this->_ResourceInformation.getFromDatabase();

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		return;
	}
}

void ResourceMessage::insertIntoDatabase() {
		if (this->IncidentID != "") {
			this->_IncidentInformation.IncidentID = this->IncidentID;
			this->_IncidentInformation.insertIntoDatabase();
		}

		if (this->RecalledMessageID != "") {
			this->_MessageRecall.RecalledMessageID = this->RecalledMessageID;
			this->_MessageRecall.insertIntoDatabase();
		}

		if (this->FundCode != "") {
			this->_Funding.FundCode = this->FundCode;
			this->_Funding.insertIntoDatabase();
		}

		if (this->_ContactInformationID != -1) {
			this->_ContactInformationType.ContactInformationID = this->_ContactInformationID;
			this->_ContactInformationType.insertIntoDatabase();
		}

		if (this->ResourceInfoElementID != "") {
			this->_ResourceInformation.ResourceInfoElementID = this->ResourceInfoElementID;
			this->_ResourceInformation.insertIntoDatabase();
		}
		char* strUuid;
	sprintf(strUuid, "%x%x-%x-%x-%x-%x%x%x", 
    rand(), rand(),                 // Generates a 64-bit Hex number
    rand(),                         // Generates a 32-bit Hex number
    ((rand() & 0x0fff) | 0x4000),   // Generates a 32-bit Hex number of the form 4xxx (4 indicates the UUID version)
    rand() % 0x3fff + 0x8000,       // Generates a 32-bit Hex number in the range [0x8000, 0xbfff]
    rand(), rand(), rand());        // Generates a 96-bit Hex number

	try {
			std::cout << strUuid << std::endl;
			this->MessageID = strUuid;
		// ...
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `ResourceMessage`(`MessageID`, `SentDateTime`, `MessageContentType`, `MessageDescription`, `OriginatingMessageID`, `PrecedingMessageID`, `IncidentID`, `RecalledMessageID`, `FundCode`, `ContactInformationID`, `ResourceInfoElementID`) VALUES (?,?,?,?,?,?,?,?,?,?,?)");

		prep_stmt->setString(1, this->MessageID);
		prep_stmt->setString(2, this->_SentDateTime);
		prep_stmt->setString(3, this->MessageContentType);
		prep_stmt->setString(4, this->MessageDescription);
		prep_stmt->setString(5, this->OriginatingMessageID);
		prep_stmt->setString(6, this->PrecedingMessageID);
		prep_stmt->setString(7, this->IncidentID);
		prep_stmt->setString(8, this->RecalledMessageID);
		prep_stmt->setString(9, this->FundCode);
		prep_stmt->setInt(10, this->_ContactInformationID);
		prep_stmt->setString(11, this->ResourceInfoElementID);

		prep_stmt->execute();

		delete stmt;
		delete prep_stmt;
		delete con;

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        /* what() (derived from std::runtime_error) fetches error message */
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		return;
	}
}

bool ResourceMessage::areFieldsValid() {
	return false;
}
