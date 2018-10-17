#pragma once
#include "ResponseInformation.h"


ResponseInformation::ResponseInformation(string precedingResourceInfoElementID)
{
	this->PrecedingResourceInfoElementID = precedingResourceInfoElementID;
}


ResponseInformation::ResponseInformation()
{
	this->PrecedingResourceInfoElementID = -1;
}



ResponseInformation::~ResponseInformation()
{
}

// void ResponseInformation::getFromDatabase(){

// 	try {
// 		sql::Connection *con;
// 		sql::PreparedStatement *prep_stmt;
// 		sql::mysql::MySQL_Driver *driver;
// 		sql::Statement *stmt;
// 		sql::ResultSet *res;

// 		driver = sql::mysql::get_mysql_driver_instance();
// 		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
// 		stmt = con->createStatement();
// 		stmt->execute("USE " EXAMPLE_DB);

// 		prep_stmt = con->prepareStatement("SELECT `ResourceInfoElementID`, `ResponseInformation`, `Resource`, `AssignmentInformationID`, `ScheduleInformationID` FROM `ResourceInformation` WHERE `ResourceInfoElementID`=?");

// 		prep_stmt->setInt(1, this->ResourceInfoElementID);

		
// 		res = prep_stmt->executeQuery();

// 		while (res->next()) {
// 			this->ResourceInfoElementID = res->getString("ResourceInfoElementID");
// 			this->ResponseInformation = res->getString("ResponseInformation");
// 			this->Resource = res->getString("Resource");
// 			this->AssignmentInformationID = res->getInt("AssignmentInformationID");
// 			this->ScheduleInformationID = res->getInt("ScheduleInformationID");

// 		}
// 		delete res;
// 		delete stmt;
// 		delete prep_stmt;
// 		delete con;
// 		if(this->AssignmentInformationID != -1){
// 			this->_AssignmentInformation = *(new _AssignmentInformation(this->AssignmentInformationID));
// 			this->_AssignmentInformation.getFromDatabase();
			
// 		}


// 	} catch (sql::SQLException &e) {
// 		cout << "# ERR: SQLException in " << __FILE__;
// 		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
// 		cout << "# ERR: " << e.what();
// 		cout << " (MySQL error code: " << e.getErrorCode();
// 		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

// 		return;
// 	}
// }

// void ResponseInformation::insertIntoDatabase(){
// 	if(this->LocationTypeID != -1){
// 		_Location.insertIntoDatabase();
// 	}

// 	try {
		
// 		// ...
// 		sql::Connection *con;
// 		sql::PreparedStatement *prep_stmt;
// 		sql::mysql::MySQL_Driver *driver;
// 		sql::Statement *stmt;

// 		driver = sql::mysql::get_mysql_driver_instance();
// 		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
// 		stmt = con->createStatement();
// 		stmt->execute("USE " EXAMPLE_DB);

// 		prep_stmt = con->prepareStatement("INSERT INTO `ScheduleInformation`(`ScheduleInformationID`, `ScheduleType`, `DateTime`, `LocationTypeID`) VALUES (?,?,?,?)");

// 		prep_stmt->setInt(1, this->ScheduleInformationID);
// 		prep_stmt->setString(2, this->ScheduleType);
// 		prep_stmt->setDateTime(3, this->DateTime);
// 		prep_stmt->setInt(4, this->LocationTypeID);

// 		prep_stmt->execute();

// 		delete stmt;
// 		delete prep_stmt;
// 		delete con;

// 	} catch (sql::SQLException &e) {
// 		cout << "# ERR: SQLException in " << __FILE__;
// 		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
//         /* what() (derived from std::runtime_error) fetches error message */
// 		cout << "# ERR: " << e.what();
// 		cout << " (MySQL error code: " << e.getErrorCode();
// 		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

// 		return;
// 	}
// }

// bool ResponseInformation::areFieldsValid(){
// 	return false;
// }

