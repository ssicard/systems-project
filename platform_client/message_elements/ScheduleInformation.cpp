#include "ScheduleInformation.h"

ScheduleInformation::ScheduleInformation(int scheduleInformationID)
{
	this->ScheduleInformationID = scheduleInformationID;
}

/*
ScheduleInformation::ScheduleInformation()
{
	this->ScheduleInformationID = -1;
}

ScheduleInformation::~ScheduleInformation()
{
	
}
*/

void ScheduleInformation::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `ScheduleInformationID`, `ScheduleType`, `DateTime`, `LocationTypeID` FROM `ScheduleInformation` WHERE `ScheduleInformationID` = ?");

		prep_stmt->setInt(1, this->ScheduleInformationID);
		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->ScheduleInformationID = res->getInt("ScheduleInformationID");
			this->ScheduleType = res->getString("ScheduleType");
			this->DateTime = res->getString("DateTime");
			this->LocationTypeID = res->getInt("LocationTypeID");
		}

		delete res;
		delete stmt;
		delete prep_stmt;
		delete con;
		
		if(this->LocationTypeID != -1){
			this->_Location.LocationTypeID = this->LocationTypeID;
			this->_Location.getFromDatabase();
			
		}

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		return;
	}
}

void ScheduleInformation::insertIntoDatabase(){
	if(this->LocationTypeID != -1){
		_Location.insertIntoDatabase();
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

		prep_stmt = con->prepareStatement("INSERT INTO `ScheduleInformation`(`ScheduleInformationID`, `ScheduleType`, `DateTime`, `LocationTypeID`) VALUES (?,?,?,?)");

		prep_stmt->setInt(1, this->ScheduleInformationID);
		prep_stmt->setString(2, this->ScheduleType);
		prep_stmt->setDateTime(3, this->DateTime);
		prep_stmt->setInt(4, this->LocationTypeID);

		prep_stmt->execute();

		if (this->LocationTypeID != -1) {
			this->_Location.LocationTypeID = this->LocationTypeID;
			this->_Location.insertIntoDatabase();
		}

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

bool ScheduleInformation::areFieldsValid(){
	return false;
}
