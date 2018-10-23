#include "ContactRoleLookup.h"

ContactRoleLookup::ContactRoleLookup() {
	this->ContactRoleID = -1;
}

ContactRoleLookup::ContactRoleLookup(int contactRoleID)
{
	this->ContactRoleID = contactRoleID;
}


ContactRoleLookup::~ContactRoleLookup()
{
}

void ContactRoleLookup::getFromDatabase() {
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

			prep_stmt = con->prepareStatement("SELECT `ContactRoleID`, `Description` FROM `ContactRoleLookup` WHERE `ContactRoleID` = ?");

			prep_stmt->setInt(1, this->ContactRoleID);

			
			res = prep_stmt->executeQuery();

			while (res->next()) {
				this->ContactRoleID = res->getInt("ContactRoleID");
				this->Description = res->getString("Description");
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
 
void ContactRoleLookup::insertIntoDatabase() {
	try {
			sql::Connection *con;
			sql::PreparedStatement *prep_stmt;
			sql::mysql::MySQL_Driver *driver;
			sql::Statement *stmt;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
			stmt = con->createStatement();
			stmt->execute("USE " EXAMPLE_DB);

			prep_stmt = con->prepareStatement("INSERT INTO `ContactRoleLookup`(`ContactRoleID`, `Description`) VALUES (?,?)");
			prep_stmt->setInt(1, this->ContactRoleID);
			prep_stmt->setString(2, this->Description);

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

 bool ContactRoleLookup::areFieldsValid() {
 	return false;
 }
