#include "IncidentInformation.h"

/*
IncidentInformation::IncidentInformation(std::string incidentID)
{
	this->IncidentID = incidentID;
}

IncidentInformation::IncidentInformation()
{
	this->IncidentID = "";
}


IncidentInformation::~IncidentInformation()
{
}
*/

void IncidentInformation::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `IncidentID`, `IncidentDescription` FROM `IncidentInformation` WHERE `IncidentID` = ?");

		prep_stmt->setString(1, this->IncidentID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->IncidentID = res->getString("IncidentID");
			this->IncidentDescription = res->getString("IncidentDescription");
		}
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

void IncidentInformation::insertIntoDatabase(){
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `IncidentInformation`(`IncidentID`, `IncidentDescription`) VALUES (?,?)");
		prep_stmt->setString(1, this->IncidentID);
		prep_stmt->setString(2, this->IncidentDescription);

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

bool IncidentInformation::areFieldsValid() {
	return false;
}
