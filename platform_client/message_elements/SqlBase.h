#ifndef SQLBASE_H
#define SQLBASE_H

#include <mysql_connection.h> 
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

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
