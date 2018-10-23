#include "AssignmentInformation.h"


AssignmentInformation::AssignmentInformation(int assignmentInformationID)
{
	this->AssignmentInformationID = assignmentInformationID;
}
AssignmentInformation::AssignmentInformation()
{
	this->AssignmentInformationID = -1;
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

		prep_stmt = con->prepareStatement("SELECT `AssignmentInformationID`, `Quantity`, `Restrictions`, `AnticipatedFunction`, `PriceQuote`, `OrderID`, `AssignmentInstructionsID` FROM `AssignmentInformation` WHERE `AssignmentInformationID` = ?");

		prep_stmt->setInt(1, this->AssignmentInformationID);

		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->AssignmentInformationID = res->getInt("AssignmentInformationID");
			this->Quantity = res->getString("Quantity");
			this->Restrictions = res->getString("Restrictions");
			this->AnticipatedFunction = res->getString("AnticipatedFunction");
			this->PriceQuote = res->getString("PriceQuote");
			this->OrderID = res->getString("OrderID");
			this->AssignmentInstructionsID = res->getInt("AssignmentInstructionsID");
		}

		this->_AssignmentInstructions.AssignmentInstructionsID = this->AssignmentInstructionsID;

		this->_AssignmentInstructions.getFromDatabase();

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

		prep_stmt = con->prepareStatement("INSERT INTO `AssignmentInformation`(`AssignmentInformationID`, `Quantity`, `Restrictions`, `AnticipatedFunction`, `PriceQuote`, `OrderID`, `AssignmentInstructionsID`) VALUES (?,?,?,?,?,?,?)");
		prep_stmt->setInt(1, this->AssignmentInformationID);
		prep_stmt->setString(2, this->Quantity);
		prep_stmt->setString(3, this->Restrictions);
		prep_stmt->setString(4, this->AnticipatedFunction);
		prep_stmt->setString(5, this->PriceQuote);
		prep_stmt->setString(6, this->OrderID);
		prep_stmt->setInt(7, this->AssignmentInstructionsID);

		if (this->AssignmentInstructionsID != -1) {
			this->_AssignmentInstructions.AssignmentInstructionsID = this->AssignmentInstructionsID;
			this->_AssignmentInstructions.insertIntoDatabase();
		}

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

bool AssignmentInformation::areFieldsValid() {
	return false;
}
