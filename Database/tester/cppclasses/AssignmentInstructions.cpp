#include "AssignmentInstructions.h"


AssignmentInstructions::AssignmentInstructions(int assignmentInstructionsID)
{
	this->AssignmentInstructionsID = assignmentInstructionsID;
}


AssignmentInstructions::~AssignmentInstructions()
{
}

void AssignmentInstructions::getFromDatabase() {
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

			prep_stmt = con->prepareStatement("SELECT `AssignmentInstructionsID`, `ModeOfTransportation`, `NavigationInstructions`, `ReportingInstructions` FROM `AssignmentInstructions` WHERE `AssignmentInstructionsID` = ?");

			prep_stmt->setInt(1, this->AssignmentInstructionsID);

			
			res = prep_stmt->executeQuery();

			while (res->next()) {
				this->AssignmentInstructionsID = res->getInt("AssignmentInstructionsID");
				this->ModeOfTransportation = res->getString("ModeOfTransportation");
				this->NavigationInstructions = res->getString("NavigationInstructions");
				this->ReportingInstructions = res->getString("ReportingInstructions");
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

void AssignmentInstructions::insertIntoDatabase() {
try {
			sql::Connection *con;
			sql::PreparedStatement *prep_stmt;
			sql::mysql::MySQL_Driver *driver;
			sql::Statement *stmt;

			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
			stmt = con->createStatement();
			stmt->execute("USE " EXAMPLE_DB);

			prep_stmt = con->prepareStatement("INSERT INTO `AssignmentInstructions`(`AssignmentInstructionsID`, `ModeOfTransportation`,`NavigationInstructions`, `ReportingInstructions`) VALUES (?,?,?,?)");
			prep_stmt->setInt(1, this->AssignmentInstructionsID);
			prep_stmt->setString(2, this->ModeOfTransportation);
			prep_stmt->setString(3, this->NavigationInstructions);
			prep_stmt->setString(4, this->ReportingInstructions);

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

bool AssignmentInstructions::areFieldsValid() {
	return false;
}