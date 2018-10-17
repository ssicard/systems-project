#pragma once
#include "ResponseTypeLookup.h"


ResponseTypeLookup::ResponseTypeLookup(int responseTypeID)
{
	this->ResponseTypeID = responseTypeID;
}


ResponseTypeLookup::~ResponseTypeLookup()
{
}

void ResponseTypeLookup::getFromDatabase(){


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

		prep_stmt = con->prepareStatement("SELECT `ResponseTypeID`, `Description` FROM `ResponseTypeLookup` WHERE `ResponseTypeID`=?");

		prep_stmt->setInt(1, this->ResponseTypeID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->ResponseTypeID = res->getInt("ResponseTypeID");
			this->Description = res->getString("Description");
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

void ResponseTypeLookup::insertIntoDatabase(){


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

		prep_stmt = con->prepareStatement("INSERT INTO `ResponseTypeLookup`(`ResponseTypeID`, `Description`) VALUES (?,?)");

		prep_stmt->setInt(1, this->ResponseTypeID);
		prep_stmt->setString(2, this->Description);
		prep_stmt->execute();

		delete stmt;
		delete prep_stmt;
		delete con;

	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        /* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

		return;
	}
}
bool ResponseTypeLookup::areFieldsValid(){
	return false;
}
