#include <string>
#include "SqlBase.h"

#ifndef ASSIGNMENTINSTRUCTIONS_H
#define ASSIGNMENTINSTRUCTIONS_H

class AssignmentInstructions : public SqlBase 
{
public:
	AssignmentInstructions(int AssignmentInstructionsID = -1, std::string ModeOfTransportation = "",
							std::string NavigationInstructions = "", std::string ReportingInstructions = "") :
							AssignmentInstructionsID(AssignmentInstructionsID), ModeOfTransportation(ModeOfTransportation),
							NavigationInstructions(NavigationInstructions), ReportingInstructions(ReportingInstructions) {}
	~AssignmentInstructions() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int AssignmentInstructionsID;
	std::string ModeOfTransportation;
	std::string NavigationInstructions;
	std::string ReportingInstructions;
};
#endif /* ASSIGNMENTINSTRUCTIONS_H */
