#include <string>

#ifndef ASSIGNMENTINSTRUCTIONS_H
#define ASSIGNMENTINSTRUCTIONS_H

class AssignmentInstructions {
public:
	AssignmentInstructions(int AssignmentInstructionsID, std::string ModeOfTransportation,
							std::string NavigationInstructions, std::string ReportingInstructions) :
							AssignmentInstructionsID(AssignmentInstructionsID), ModeOfTransportation(ModeOfTransportation),
							NavigationInstructions(NavigationInstructions), ReportingInstructions(ReportingInstructions) {}
	~AssignmentInstructions() {}

	int AssignmentInstructionsID;
	std::string ModeOfTransportation;
	std::string NavigationInstructions;
	std::string ReportingInstructions;
};
#endif /* ASSIGNMENTINSTRUCTIONS_H */
