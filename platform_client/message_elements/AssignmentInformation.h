#include <string>

#ifndef ASSIGNMENTINFORMATION_H
#define ASSIGNMENTINFORMATION_H

class AssignmentInformation {
public:
	AssignmentInformation(int AssignmentInformationID, std::string Quantity, std::string Restrictions,
							std::string AnticipatedFunction, std::string PriceQuote,
							std::string OrderID, std::string AssignmentInstructionsID) :
							AssignmentInformationID(AssignmentInformationID), Quantity(Quantity),
							Restrictions(Restrictions), AnticipatedFunction(AnticipatedFunction),
							PriceQuote(PriceQuote), OrderID(OrderID), AssignmentInstructionsID(AssignmentInstructionsID) {}
	~AssignmentInformation() {}

	int AssignmentInformationID;
	std::string Quantity;
	std::string Restrictions;
	std::string AnticipatedFunction;
	std::string PriceQuote;
	std::string OrderID;
	std::string AssignmentInstructionsID;
};
#endif /* ASSIGNMENTINFORMATION_H */
