#include "MessagePropertiesLookup.h"


MessagePropertiesLookup::MessagePropertiesLookup(int requirementType)
{
	this->RequirementType = requirementType;
}


MessagePropertiesLookup::~MessagePropertiesLookup()
{
}

void MessagePropertiesLookup::getFromDatabase() {
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

			prep_stmt = con->prepareStatement("SELECT * FROM `MessagePropertiesLookup` WHERE `RequirementType` = ?");

			prep_stmt->setInt(1, this->RequirementType);

			
			res = prep_stmt->executeQuery();

			while (res->next()) {
				this->RequirementType = res->getInt("RequirementType");
				this->RequirementDesc = res->getString("RequirementDesc");
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

void MessagePropertiesLookup::insertIntoDatabase() {
try {
			sql::Connection *con;
			sql::PreparedStatement *prep_stmt;
			sql::mysql::MySQL_Driver *driver;
			sql::Statement *stmt;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
			stmt = con->createStatement();
			stmt->execute("USE " EXAMPLE_DB);

			prep_stmt = con->prepareStatement("INSERT INTO `MessagePropertiesLookup`(`RequirementType`, `RequirementDesc`) VALUES (?,?)");
			prep_stmt->setInt(1, this->RequirementType);
			prep_stmt->setString(2, this->RequirementDesc);

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

bool MessagePropertiesLookup::areFieldsValid() {
	return false;
}