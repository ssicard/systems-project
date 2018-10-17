#pragma once
#include "ResourceInformation.h"


ResourceInformation::ResourceInformation(string resourceInfoElementID)
{
	this->ResourceInfoElementID = resourceInfoElementID;

}

ResourceInformation::ResourceInformation()
{
	this->ResourceInfoElementID = "";

}

ResourceInformation::~ResourceInformation()
{
}

void ResourceInformation::getFromDatabase(){

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

		prep_stmt = con->prepareStatement("SELECT `ResourceInfoElementID`, `ResponseInformation`, `Resource`, `AssignmentInformationID`, `ScheduleInformationID` FROM `ResourceInformation` WHERE `ResourceInfoElementID`=?");

		prep_stmt->setString(1, this->ResourceInfoElementID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->ResourceInfoElementID = res->getString("ResourceInfoElementID");
			this->ResponseInformationID = res->getString("ResponseInformationID");
			this->ResourceID = res->getString("ResourceID");
			this->AssignmentInformationID = res->getInt("AssignmentInformationID");
			this->ScheduleInformationID = res->getInt("ScheduleInformationID");

		}
		delete res;
		delete stmt;
		delete prep_stmt;
		delete con;
		if(this->AssignmentInformationID != -1){
			this->_AssignmentInformation = *(new AssignmentInformation(this->AssignmentInformationID));
			//todo link
			//this->_AssignmentInformation.getFromDatabase();
			
		}
		if(this->ResponseInformationID != ""){
			this->_ResponseInformation = *(new ResponseInformation(this->ResponseInformationID));
			this->_ResponseInformation.getFromDatabase();
			
		}

		if(this->ResourceID != ""){
			this->_Resource = *(new Resource(this->ResourceID));
			//todo link
			//this->_Resource.getFromDatabase();
			
		}

		if(this->ScheduleInformationID != -1){
			this->_ScheduleInformation = *(new ScheduleInformation(this->ScheduleInformationID));
			this->_ScheduleInformation.getFromDatabase();
			
		}

	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

		return;
	}
}

void ResourceInformation::insertIntoDatabase(){
	if(this->AssignmentInformationID != -1){
		//todo link
		//this->_AssignmentInformation.insertIntoDatabase();
	}
		if(this->ResponseInformationID != ""){
		this->_ResponseInformation.insertIntoDatabase();
	}
		if(this->ScheduleInformationID != -1){
		this->_ScheduleInformation.insertIntoDatabase();
	}
		if(this->ResourceID != ""){
			//todo link
		//this->_Resource.insertIntoDatabase();
	}


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

		prep_stmt = con->prepareStatement("INSERT INTO `ResourceInformation`(`ResourceInfoElementID`, `ResponseInformation`, `Resource`, `AssignmentInformationID`, `ScheduleInformationID`) VALUES (?,?,?,?,?)");

		prep_stmt->setString(1, this->ResourceInfoElementID);
		prep_stmt->setString(2, this->ResponseInformationID);
		prep_stmt->setString(3, this->ResourceID);
		prep_stmt->setInt(4, this->AssignmentInformationID);
		prep_stmt->setInt(5, this->ScheduleInformationID);

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

bool ResourceInformation::areFieldsValid(){
	return false;
}
