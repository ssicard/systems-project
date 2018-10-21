#include "MessageRecall.h"

MessageRecall::MessageRecall(std::string recalledMessageID)
{
	this->RecalledMessageID = recalledMessageID;
}

MessageRecall::MessageRecall()
{
	this->RecalledMessageID = "";
}



MessageRecall::~MessageRecall()
{
}

void MessageRecall::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `RecalledMessageID`, `RecallType` FROM `MessageRecall` WHERE `RecalledMessageID` = ?");

		prep_stmt->setString(1, this->RecalledMessageID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->RecalledMessageID = res->getString("RecalledMessageID");
			this->RecallType = res->getString("RecallType");
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

void MessageRecall::insertIntoDatabase(){
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `MessageRecall`(`RecalledMessageID`, `RecallType`) VALUES (?,?)");
		prep_stmt->setString(1, this->RecalledMessageID);
		prep_stmt->setString(2, this->RecallType);

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
bool MessageRecall::areFieldsValid(){
	return false;
}
