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
<<<<<<< HEAD
//#include "MessageObjectBase.cpp"

 #include "cppclasses/Funding.cpp"
 #include "cppclasses/IncidentInformation.cpp"
 #include "cppclasses/LocationType.cpp"
 #include "cppclasses/MessageRecall.cpp"
 #include "cppclasses/OwnershipInformation.cpp"
 #include "cppclasses/RadioElement.cpp"
 #include "cppclasses/ScheduleInformation.cpp"
 #include "cppclasses/TypeInfoType.cpp"
#include "cppclasses/ValueListType.cpp"
#include "cppclasses/ResponseTypeLookup.cpp"
#include "cppclasses/ResourceInformation.cpp"
=======
#include "cppclasses/Funding.cpp"
#include "cppclasses/ContactRoleLookup.cpp"
// #include "cppclasses/ResourceStatus.cpp"
// #include "cppclasses/AssignmentInstructions.cpp"
#include "cppclasses/AssignmentInformation.cpp"
#include "cppclasses/MessageProperties.cpp"
#include "cppclasses/MessagePropertiesLookup.cpp"

>>>>>>> database2

using namespace std;

int main() {


<<<<<<< HEAD
  //   cout << "Connector/C++ tutorial framework..." << endl;
  //  // cout << endl;
  //    Funding* f;
  //   f = new Funding("this is another test");
  // // f->FundingInfo = "this is a fund info test"; 
  // // f->insertIntoDatabase();

  // f->getFromDatabase();
  // // printf("%s\n", f->FundingInfo);
=======
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

    // AssignmentInstructions* a = new AssignmentInstructions(1);
    // a->ModeOfTransportation = "ambulance";
    // a->NavigationInstructions = "left right left right";
    // a->ReportingInstructions = "report report";

    // a->insertIntoDatabase();

    // a->ModeOfTransportation = "";

    // a->getFromDatabase();
    // std::cout << "Mode of transportation: " << a->ModeOfTransportation << std::endl;

    // AssignmentInformation* a = new AssignmentInformation(1);
    // a->Quantity = "1";
    // a->Restrictions = "restrictions string";
    // a->AnticipatedFunction = "anticipated function string";
    // a->PriceQuote = "price quote string";
    // a->OrderID = "aaaa11111zzzzzz";
    // a->AssignmentInstructionsID = 1;

    // a->insertIntoDatabase();
>>>>>>> database2
   
    // a->OrderID = "";
    // a->Quantity = "";

    // a->getFromDatabase();
    // std::cout << "OrderID: " << a->OrderID << std::endl;
    // std::cout << "Quantity: " << a->Quantity << std::endl;
    // std::cout << "Assignment Instructions ModeOfTransportation: " << a->assignmentInstructions.ModeOfTransportation << std::endl;

    // MessagePropertiesLookup* mpl = new MessagePropertiesLookup(4);
    // mpl->RequirementDesc = "Description test";

    // mpl->insertIntoDatabase();

    // mpl->RequirementDesc = "";

    // mpl->getFromDatabase();

    // std::cout << "RequirementDesc: " << mpl->RequirementDesc << std::endl;

    MessageProperties* mp = new MessageProperties(17, "Request Resource (Test)");
    mp->Location = 2;
    mp->DateTime = 2;
    mp->MessagePropertyLookupID = 4;

    mp->insertIntoDatabase();

    mp->MessageTypeName = "none";
    mp->Location = 3;
    mp->DateTime = 6;
    mp->MessagePropertyLookupID = 0;

    mp->getFromDatabase();

    std::cout << "Message Type Name: " << mp->MessageTypeName << std::endl;
    std::cout << "Location: " << mp->Location << std::endl;
    std::cout << "DateTime: " << mp->DateTime << std::endl;

    std::cout << "RequirementDesc: " << mp->messagePropertiesLookup.RequirementDesc << std::endl;

<<<<<<< HEAD
  //   cout << f->FundingInfo << endl;
  //   return EXIT_SUCCESS;
=======
    return EXIT_SUCCESS;
>>>>>>> database2
}
