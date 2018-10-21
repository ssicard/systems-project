#ifndef ASSIGNMENT_INFORMATION_H
#define ASSIGNMENT_INFORMATION_H

#include <string>
#include "SqlBase.h"
#include "AssignmentInstructions.h"

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
	std::string Quantity;
	std::string Restrctions;
	std::string Restrictions;
	std::string AnticipatedFunction;
	std::string PriceQuote;
	std::string OrderID;
	int AssignmentInstructionsID;

	AssignmentInstructions _AssignmentInstructions;
	// should change this.
	// add default constructor to AssignmentInstructions
	AssignmentInstructions assignmentInstructions{AssignmentInstructionsID};

};

#endif
