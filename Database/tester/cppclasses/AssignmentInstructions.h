#include <string>
#pragma once
using namespace std;
class AssignmentInstructions
{
public:
	AssignmentInstructions(int assignmentInstructionsID);
	AssignmentInstructions();
	~AssignmentInstructions();
	int AssignmentInstructionsID;
	string ModeOfTransportation;
	string NavigationInstructions;
	string ReportingInstructions;
};

