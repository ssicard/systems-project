#include "ResponseInformation.h"

/*
ResponseInformation::ResponseInformation(std::string precedingResourceInfoElementID)
{
	this->PrecedingResourceInfoElementID = precedingResourceInfoElementID;
}


ResponseInformation::ResponseInformation()
{
	this->PrecedingResourceInfoElementID = "";
}



ResponseInformation::~ResponseInformation()
{
}
*/

void platform::ResponseInformation::getFromDatabase(){

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

		prep_stmt = con->prepareStatement("SELECT `PrecedingResourceInfoElementID`, `ResponseTypeID`, `ReasonCodeID`, `ResponseReason` FROM `ResponseInformation` WHERE `PrecedingResourceInfoElementID`=?");

		prep_stmt->setString(1, this->PrecedingResourceInfoElementID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->ResponseTypeID = res->getInt("ResponseTypeID");
			this->PrecedingResourceInfoElementID = res->getString("PrecedingResourceInfoElementID");
			this->ResponseReason = res->getString("ResponseReason");
			this->ReasonCodeID = res->getInt("ReasonCodeID");
			

		}
		delete res;
		delete stmt;
		delete prep_stmt;
		delete con;
		if(this->ReasonCodeID != -1){
			this->_ReasonCode = this->ReasonCodeID;
			this->_ReasonCode.getFromDatabase();
			
		}

		if (this->ResponseTypeID != -1) {
			this->_ResponseType.ResponseTypeID = this->ResponseTypeID;
			this->_ResponseType.getFromDatabase();
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

void platform::ResponseInformation::insertIntoDatabase(){

	if(this->ReasonCodeID != -1){
		this->_ReasonCode.ValueListID = this->ReasonCodeID;
		this->_ReasonCode.insertIntoDatabase();
	}

	if(this->ResponseTypeID != -1) {
		this->_ResponseType.ResponseTypeID = this->ResponseTypeID;
		this->_ResponseType.insertIntoDatabase();
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

		prep_stmt = con->prepareStatement("INSERT INTO `ResponseInformation`(`PrecedingResourceInfoElementID`, `ResponseTypeID`, `ReasonCodeID`, `ResponseReason`) VALUES (?,?,?,?)");

		prep_stmt->setString(1, this->PrecedingResourceInfoElementID);
		prep_stmt->setInt(2, this->ResponseTypeID);
		prep_stmt->setInt(3, this->ReasonCodeID);
		prep_stmt->setString(4, this->ResponseReason);

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

bool platform::ResponseInformation::areFieldsValid(){
	return false;
}


