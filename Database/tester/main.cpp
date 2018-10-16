#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>


#include "mysql_connection.h"
#include "mysql_driver.h"

#include "driver.h"
#include "exception.h"
#include "resultset.h"
#include "statement.h"
#include "prepared_statement.h"


#define EXAMPLE_HOST "localhost"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "progDB"
using namespace std;

int main() {


    cout << "Connector/C++ tutorial framework..." << endl;
    cout << endl;

    try {

        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", EXAMPLE_USER, EXAMPLE_PASS);

        stmt = con->createStatement();
        stmt->execute("USE " EXAMPLE_DB);
        stmt->execute("SELECT * FROM Funding");

        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        /*
          MySQL Connector/C++ throws three different exceptions:

          - sql::MethodNotImplementedException (derived from sql::SQLException)
          - sql::InvalidArgumentException (derived from sql::SQLException)
          - sql::SQLException (derived from std::runtime_error)
        */
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        /* what() (derived from std::runtime_error) fetches error message */
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        return EXIT_FAILURE;
    }

    cout << "Done." << endl;
    return EXIT_SUCCESS;
}
