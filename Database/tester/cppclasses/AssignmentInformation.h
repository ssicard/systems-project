#pragma once
#include <string>
#include "SqlBase.h"
#include "AssignmentInstructions.cpp"
using namespace std;
#include "AssignmentInstructions.cpp"
class AssignmentInformation : public SqlBase
{
public:
	AssignmentInformation(int assignmentInformationID);
	AssignmentInformation();
	~AssignmentInformation();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int AssignmentInformationID;
	string Quantity;
	string Restrctions;
	string Restrictions;
	string AnticipatedFunction;
	string PriceQuote;
	string OrderID;
	int AssignmentInstructionsID;

	AssignmentInstructions _AssignmentInstructions;
	// should change this.
	// add default constructor to AssignmentInstructions
	AssignmentInstructions assignmentInstructions{AssignmentInstructionsID};

};

