#ifndef SQLBASE_H
#define SQLBASE_H

#include <jdbc/mysql_connection.h> 
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

#define EXAMPLE_HOST "tcp://127.0.0.1:3306"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "progDB"
	
class SqlBase {
   public:
	  SqlBase();
      virtual void getFromDatabase();
      virtual void insertIntoDatabase();
      virtual bool areFieldsValid();  
};

#endif
