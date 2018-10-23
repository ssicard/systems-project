#include "Resource.h"

Resource::Resource(std::string resourceID)
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

void Resource::getFromDatabase() {

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

			prep_stmt = con->prepareStatement("SELECT `ResourceID`, `NAME`,`TypeStructureID`, `TypeInfoID`, `KeywordID`, `Description`, `Credentials`, `Certifications`, `SpecialRequirements`, `ResponsiblePartyID`, `OwnershipInformationID`, `ResourceStatusID` FROM Resource WHERE `ResourceID` = ?");

			prep_stmt->setString(1, this->ResourceID);

			
			res = prep_stmt->executeQuery();

			while (res->next()) {
				this->ResourceID = res->getString("ResourceID");
				this->NAME = res->getString("NAME");
				this->TypeStructureID = res->getInt("TypeStructureID");
				this->TypeInfoID = res->getInt("TypeInfoID");
				this->KeywordID = res->getInt("KeywordID");
				this->Description = res->getString("Description");
				this->Credentials = res->getString("Credentials");
				this->Certifications = res->getString("Certifications");
				this->SpecialRequirements = res->getString("SpecialRequirements");
				this->ResponsiblePartyID = res->getInt("ResponsiblePartyID");
				this->OwnershipInformationID = res->getInt("OwnershipInformationID");
				this->ResourceStatusID = res->getInt("ResourceStatusID");
			}

			this->_TypeStructure.ValueListID = this->TypeStructureID;
			this->_TypeStructure.getFromDatabase();

			this->_TypeInfo.TypeInfoID = this->TypeInfoID;
			this->_TypeInfo.getFromDatabase();

			this->_Keyword.ValueListID = this->KeywordID;
			this->_Keyword.getFromDatabase();

			this->_ResponsibleParty.ContactInformationID = this->ResponsiblePartyID;
			this->_ResponsibleParty.getFromDatabase();

			this->_OwnershipInformation.OwnershipInformationID = this->OwnershipInformationID;
			this->_OwnershipInformation.getFromDatabase();

			this->_ResourceStatus.ResourceStatusID = this->ResourceStatusID;
			this->_ResourceStatus.getFromDatabase();

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

void Resource::insertIntoDatabase() {

	if (this->TypeStructureID != -1) {
		this->_TypeStructure.ValueListID = this->TypeStructureID;
		this->_TypeStructure.insertIntoDatabase();
	}

	if (this->TypeInfoID != -1) {
		this->_TypeInfo.TypeInfoID = this->TypeInfoID;
		this->_TypeInfo.insertIntoDatabase();
	}

	if (this->KeywordID != -1) {
		this->_Keyword.ValueListID = this->KeywordID;
		this->_Keyword.insertIntoDatabase();
	}

	if (this->ResponsiblePartyID != -1) {
		this->_ResponsibleParty.ContactInformationID = this->ResponsiblePartyID;
		this->_ResponsibleParty.insertIntoDatabase();
	}

	if (this->OwnershipInformationID != -1) {
		this->_OwnershipInformation.OwnershipInformationID = this->OwnershipInformationID;
		this->_OwnershipInformation.insertIntoDatabase();
	}

	if (this->ResourceStatusID != -1) {
		this->_ResourceStatus.ResourceStatusID = this->ResourceStatusID;
		this->_ResourceStatus.insertIntoDatabase();
	}

	try {
			sql::Connection *con;
			sql::PreparedStatement *prep_stmt;
			sql::mysql::MySQL_Driver *driver;
			sql::Statement *stmt;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
			stmt = con->createStatement();
			stmt->execute("USE " EXAMPLE_DB);

			prep_stmt = con->prepareStatement("INSERT INTO `Resource` (`ResourceID`, `NAME`,`TypeStructureID`, `TypeInfoID`, `KeywordID`, `Description`, `Credentials`, `Certifications`, `SpecialRequirements`, `ResponsiblePartyID`, `OwnershipInformationID`, `ResourceStatusID`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)");
			prep_stmt->setString(1, this->ResourceID);
			prep_stmt->setString(2, this->NAME);
			prep_stmt->setInt(3, this->TypeStructureID);
			prep_stmt->setInt(4, this->TypeInfoID);
			prep_stmt->setInt(5, this->KeywordID);
			prep_stmt->setString(6, this->Description);
			prep_stmt->setString(7, this->Credentials);
			prep_stmt->setString(8, this->Certifications);
			prep_stmt->setString(9, this->SpecialRequirements);
			prep_stmt->setInt(10, this->ResponsiblePartyID);
			prep_stmt->setInt(11, this->OwnershipInformationID);
			prep_stmt->setInt(12, this->ResourceStatusID);

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

bool Resource::areFieldsValid() {
	return false;
}
