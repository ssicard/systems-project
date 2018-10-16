#include <string>
#pragma once
using namespace std;
class AssignmentInformation
{
public:
	AssignmentInformation(int assignmentInstructionsID);
	~AssignmentInformation();
	int AssignmentInformationID;
	string Quantity;
	string Restrctions;
	string AnticipatedFunction;
	string PriceQuote;
	string OrderID;
	string AssignmentInstructionsID;

	AssignmentInstructions AssignmentInstructions;

};

