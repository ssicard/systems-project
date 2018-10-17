#ifndef ASSIGNMENT_INFORMATION_H
#define ASSIGNMENT_INFORMATION_H

#include <string>
#include "SqlBase.h"
#include "AssignmentInstructions.cpp"
// #pragma once
using namespace std;
class AssignmentInformation : public SqlBase
{
public:
	AssignmentInformation(int assignmentInformationID);
	~AssignmentInformation();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int AssignmentInformationID;
	string Quantity;
	string Restrictions;
	string AnticipatedFunction;
	string PriceQuote;
	string OrderID;
	int AssignmentInstructionsID;

	// should change this.
	// add default constructor to AssignmentInstructions
	AssignmentInstructions assignmentInstructions{AssignmentInstructionsID};

};

#endif