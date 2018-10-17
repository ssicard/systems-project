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
#include "cppclasses/ContactRoleLookup.cpp"
// #include "cppclasses/ResourceStatus.cpp"
#include "cppclasses/AssignmentInstructions.cpp"


using namespace std;

int main() {


    cout << "Connector/C++ tutorial framework..." << endl;
   // cout << endl;
  //    Funding* f;
  //   f = new Funding("this is annother test");
  //  f->FundingInfo = "this is a fund info test"; 
  //  f->insertIntoDatabase();

  // f->getFromDatabase();
  //  std::cout << "Before printf\n";
  //  // printf("%s\n", f->FundingInfo);
  // std::cout << "Funding info " << f->FundingInfo << std::endl;

    // ContactRoleLookup* c;
    // c = new ContactRoleLookup(10);
    // c->Description = "This is a description test";

    // std::cout << c->Description << std::endl;
    // c->insertIntoDatabase();
    // c->Description = "";

    // c->getFromDatabase();
    // std::cout << "int is " << c->ContactRoleID << std::endl;
    // std::cout << "description is " << c->Description << std::endl;

    AssignmentInstructions* a = new AssignmentInstructions(1);
    a->ModeOfTransportation = "ambulance";
    a->NavigationInstructions = "left right left right";
    a->ReportingInstructions = "report report";

    a->insertIntoDatabase();

    a->ModeOfTransportation = "";

    a->getFromDatabase();
    std::cout << "Mode of transportation: " << a->ModeOfTransportation << std::endl;
   

    return EXIT_SUCCESS;
}
