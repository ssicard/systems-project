#ifndef ASSIGNMENT_INSTRUCTIONS_H
#define ASSIGNMENT_INSTRUCTIONS_H

#include <string>
// #pragma once
using namespace std;
class AssignmentInstructions
{
public:
	AssignmentInstructions(int assignmentInstructionsID);
	~AssignmentInstructions();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int AssignmentInstructionsID;
	string ModeOfTransportation;
	string NavigationInstructions;
	string ReportingInstructions;
};

#endif