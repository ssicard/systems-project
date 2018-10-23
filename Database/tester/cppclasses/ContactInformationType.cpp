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


void ContactInformationType::getFromDatabase() {

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

			prep_stmt = con->prepareStatement("SELECT `ContactInformationID`, `ContactDescription`, `ContactRole`, `ContactLocationID`, `AdditionalContactInformation` FROM `ContactInformationType` WHERE `ContactInformationID` = ?");

			prep_stmt->setInt(1, this->ContactInformationID);

			
			res = prep_stmt->executeQuery();

			while (res->next()) {
				this->ContactInformationID = res->getInt("ContactInformationID");
				this->ContactDescription = res->getString("ContactDescription");
				this->ContactRole = res->getInt("ContactRole");
				this->ContactLocationID = res->getInt("ContactLocationID");
				this->AdditionalContactInformation = res->getString("AdditionalContactInformation");
			}

			this->_ContactRoleLookup.ContactRoleID = this->ContactRole;
			this->_ContactLocation.LocationTypeID = this->ContactLocationID;

			this->_ContactRoleLookup.getFromDatabase();
			this->_ContactLocation.getFromDatabase();

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

void ContactInformationType::insertIntoDatabase() {
	if (this->ContactRole != -1) {
		this->_ContactRoleLookup.ContactRoleID = this->ContactRole;
		this->_ContactRoleLookup.insertIntoDatabase();
	}

	if (this->ContactLocationID != -1) {
		this->_ContactLocation.LocationTypeID = this->ContactLocationID;
		this->_ContactLocation.insertIntoDatabase();
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

			prep_stmt = con->prepareStatement("INSERT INTO `ContactInformationType`(`ContactInformationID`, `ContactDescription`, `ContactRole`, `ContactLocationID`, `AdditionalContactInformation`) VALUES (?,?,?,?,?)");
			prep_stmt->setInt(1, this->ContactInformationID);
			prep_stmt->setString(2, this->ContactDescription);
			prep_stmt->setInt(3, this->ContactRole);
			prep_stmt->setInt(4, this->ContactLocationID);
			prep_stmt->setString(5, this->AdditionalContactInformation);


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

bool ContactInformationType::areFieldsValid() {
	return false;
}
