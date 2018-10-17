#include "Funding.h"


Funding::Funding(string fundCode)
{
	this->FundCode = fundCode;
}


Funding::~Funding()
{
}

void Funding::getFromDatabase(string fundCode){


	try {


		sql::mysql::MySQL_Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", EXAMPLE_USER, EXAMPLE_PASS);

		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);
		res = stmt->executeQuery("SELECT `FundCode`, `FundingInfo` FROM `Funding`");
		while (res->next()) {
			cout << "\t... MySQL replies: ";
        /* Access column data by alias or column name */
			cout << res->getString("FundCode") << endl;
			cout << res->getString("FundingInfo") << endl;

			cout << "\t... MySQL says it again: ";
        /* Access column data by numeric offset, 1 is the first column */
			cout << res->getString(1) << endl;
		}
		delete res;
		delete stmt;
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

void Funding::updateToDatabase(){


	try {
		
		// ...
		sql::Connection *con;
		sql::PreparedStatement  *prep_stmt
		// ...

		prep_stmt = con->prepareStatement("INSERT INTO test(id, label) VALUES (?, ?)");

		prep_stmt->setInt(1, 1);
		prep_stmt->setString(2, "a");
		prep_stmt->execute();

		prep_stmt->setInt(1, 2);
		prep_stmt->setString(2, "b");
		prep_stmt->execute();

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
bool Funding::areFieldsValid(){
	return false;
}

//SELECT `FundCode`, `FundingInfo` FROM `Funding` WHERE 1 