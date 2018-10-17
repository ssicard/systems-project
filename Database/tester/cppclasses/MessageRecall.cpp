#include "MessageRecall.h"


MessageRecall::MessageRecall(string recalledMessageID)
{
	this->RecalledMessageID = recalledMessageID;
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
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

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
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

		return;
	}
}
bool MessageRecall::areFieldsValid(){
	return false;
}
