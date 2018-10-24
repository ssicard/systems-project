#include "ValueListType.h"

/*
ValueListType::ValueListType(int valueListID)
{
	this->ValueListID = valueListID;
}

ValueListType::ValueListType()
{
	this->ValueListID = -1;
}


ValueListType::~ValueListType()
{
}
*/

void ValueListType::getFromDatabase(){


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

		prep_stmt = con->prepareStatement("SELECT `ValueListID`, `ValueListURN`, `ValueType` FROM `ValueListType` WHERE `ValueListID` = ?");

		prep_stmt->setInt(1, this->ValueListID);
		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->ValueListID = res->getInt("ValueListID");
			this->ValueListURN = res->getString("ValueListURN");
			this->ValueType = res->getString("ValueType");

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

void ValueListType::insertIntoDatabase(){


	try {
		
		// ...
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `ValueListType` (`ValueListID`, `ValueListURN`, `ValueType`) VALUES (?,?,?)");

		prep_stmt->setInt(1, this->ValueListID);
		prep_stmt->setString(2, this->ValueListURN);
		prep_stmt->setString(3, this->ValueType);
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
bool ValueListType::areFieldsValid(){
	return false;
}
