#include "RadioElement.h"
/*
RadioElement::RadioElement(int radioElementID)
{
	this->RadioElementID = radioElementID;
}


RadioElement::~RadioElement()
{
}
*/

void RadioElement::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `RadioElementID`, `RadioType`, `RadioChannel` FROM `RadioElement` WHERE `RadioElementID` = ?");

		prep_stmt->setInt(1, this->RadioElementID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->RadioElementID = res->getInt("RadioElementID");
			this->RadioType = res->getString("RadioType");
			this->RadioChannel = res->getString("RadioChannel");

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

void RadioElement::insertIntoDatabase(){
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `RadioElement`(`RadioElementID`, `RadioType`, `RadioChannel`) VALUES (?,?,?)");
		prep_stmt->setInt(1, this->RadioElementID);
		prep_stmt->setString(2, this->RadioType);
		prep_stmt->setString(3, this->RadioChannel);

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
bool RadioElement::areFieldsValid(){
	return false;
}
