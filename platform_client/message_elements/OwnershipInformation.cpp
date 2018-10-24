#include "OwnershipInformation.h"

/*
OwnershipInformation::OwnershipInformation(int ownershipInformationID)
{
	this->OwnershipInformationID = ownershipInformationID;
}

OwnershipInformation::OwnershipInformation()
{
	this->OwnershipInformationID = -1;
}


OwnershipInformation::~OwnershipInformation()
{
}
*/

void OwnershipInformation::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `OwnershipInformationID`, `Owner`, `OwningJurisdiction`, `HomeDispatch`, `HomeUnit` FROM `OwnershipInformation` WHERE `OwnershipInformationID`=?");

		prep_stmt->setInt(1, this->OwnershipInformationID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->OwnershipInformationID = res->getInt("OwnershipInformationID");
			this->Owner = res->getString("Owner");
			this->OwningJurisdiction = res->getString("OwningJurisdiction");
			this->HomeDispatch = res->getString("HomeDispatch");
			this->HomeUnit = res->getString("HomeUnit");

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

void OwnershipInformation::insertIntoDatabase(){
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `OwnershipInformation`(`OwnershipInformationID`, `Owner`, `OwningJurisdiction`, `HomeDispatch`, `HomeUnit`) VALUES (?,?,?,?,?)");
		prep_stmt->setInt(1, this->OwnershipInformationID);
		prep_stmt->setString(2, this->Owner);
		prep_stmt->setString(3, this->OwningJurisdiction);
		prep_stmt->setString(4, this->HomeDispatch);
		prep_stmt->setString(5, this->HomeUnit);

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
bool OwnershipInformation::areFieldsValid(){
	return false;
}
