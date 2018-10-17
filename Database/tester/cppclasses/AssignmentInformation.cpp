#include "AssignmentInformation.h"


AssignmentInformation::AssignmentInformation(int assignmentInformationID)
{
	this->AssignmentInformationID = assignmentInformationID;
}


AssignmentInformation::~AssignmentInformation()
{
}

void AssignmentInformation::getFromDatabase() {
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

		prep_stmt = con->prepareStatement("SELECT `FundCode`, `FundingInfo` FROM `Funding` WHERE `FundCode` = ?");

		prep_stmt->setString(1, this->FundCode);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->FundCode = res->getString("FundCode");
			this->FundingInfo = res->getString("FundingInfo");
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

void AssignmentInformation::insertIntoDatabase() {
	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `AssignmentInformation`(`AssignmentInformationID', 'Quantity', 'Restrctions', 'AnticipatedFunction',
			'PriceQuote', 'OrderID', 'AssignmentInstructionsID`, `FundingInfo`) VALUES (?,?)");
		prep_stmt->setString(1, this->FundCode);
		prep_stmt->setString(2, this->FundingInfo);

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