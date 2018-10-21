#include "TypeInfoType.h"

TypeInfoType::TypeInfoType(int typeInfoID)
{
	this->TypeInfoID = typeInfoID;
}

TypeInfoType::TypeInfoType()
{
	this->TypeInfoID = -1;
}


TypeInfoType::~TypeInfoType()
{
}

void TypeInfoType::getFromDatabase(){
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

		prep_stmt = con->prepareStatement("SELECT `TypeInfoID`, `ChildInfo` FROM `TypeInfoType` WHERE `TypeInfoID` = ?");

		prep_stmt->setInt(1, this->TypeInfoID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->TypeInfoID = res->getInt("TypeInfoID");
			this->ChildInfo = res->getString("ChildInfo");
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

void TypeInfoType::insertIntoDatabase(){
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `TypeInfoType`(`TypeInfoID`, `ChildInfo`) VALUES (?,?)");
		prep_stmt->setInt(1, this->TypeInfoID);
		prep_stmt->setString(2, this->ChildInfo);

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
bool TypeInfoType::areFieldsValid(){
	return false;
}
