#pragma once
#include "LocationType.h"


LocationType::LocationType(int locationTypeID)
{
	this->LocationTypeID = locationTypeID;
}
LocationType::LocationType(){
	this->LocationTypeID = -1;
}


LocationType::~LocationType()
{
}
void LocationType::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `LocationTypeID`, `LocationDescription`, `Address`, `TargetArea` FROM `LocationType` WHERE `LocationTypeID` = ?");

		prep_stmt->setInt(1, this->LocationTypeID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->LocationTypeID = res->getInt("LocationTypeID");
			this->LocationDescription = res->getString("LocationDescription");
			this->Address = res->getString("Address");
			this->TargetArea = res->getString("TargetArea");
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

void LocationType::insertIntoDatabase(){
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `LocationType`(`LocationTypeID`, `LocationDescription`, `Address`, `TargetArea`) VALUES (?,?,?,?)");
		prep_stmt->setInt(1, this->LocationTypeID);
		prep_stmt->setString(2, this->LocationDescription);
		prep_stmt->setString(3, this->Address);
		prep_stmt->setString(4, this->TargetArea);

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
bool LocationType::areFieldsValid(){
	return false;
}