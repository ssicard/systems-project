#include <string>
#pragma once
using namespace std;
#include "AssignmentInstructions.cpp"
class AssignmentInformation: public SqlBase
{
public:
	AssignmentInformation(int assignmentInformationID);
	AssignmentInformation();
	~AssignmentInformation();
	int AssignmentInformationID;
	string Quantity;
	string Restrctions;
	string AnticipatedFunction;
	string PriceQuote;
	string OrderID;
	string AssignmentInstructionsID;

	AssignmentInstructions _AssignmentInstructions;

};

