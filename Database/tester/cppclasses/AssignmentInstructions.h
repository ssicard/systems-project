#ifndef ASSIGNMENT_INSTRUCTIONS_H
#define ASSIGNMENT_INSTRUCTIONS_H

#include "SqlBase.h"
#include <string>

class AssignmentInstructions : public SqlBase
{
public:
	AssignmentInstructions(int assignmentInstructionsID);
	AssignmentInstructions();
	~AssignmentInstructions();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int AssignmentInstructionsID;
	std::string ModeOfTransportation;
	std::string NavigationInstructions;
	std::string ReportingInstructions;
};

#endif
