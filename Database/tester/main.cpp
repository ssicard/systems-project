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
#include "cppclasses/Funding.cpp"



using namespace std;

int main() {


    cout << "Connector/C++ tutorial framework..." << endl;
   // cout << endl;
     Funding* f;
    f = new Funding("this is another test");
  // f->FundingInfo = "this is a fund info test"; 
  // f->insertIntoDatabase();

  f->getFromDatabase();
  // printf("%s\n", f->FundingInfo);
   

    cout << f->FundingInfo << endl;
    return EXIT_SUCCESS;
}