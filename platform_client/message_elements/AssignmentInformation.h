#include <string>

#ifndef ASSIGNMENTINFORMATION_H
#define ASSIGNMENTINFORMATION_H
class AssignmentInformation
{
public:
	AssignmentInformation(int AssignmentInstructionsID = 0, std::string Quantity = "",
                              std::string Restrictions = "", std::string AnticipatedFunction = "",
                              std::string PriceQuote = "", std::string OrderID = "",
                              std::string AssignmentInstructionID = "") :
                              AssignmentInformationID(AssignmentInformationID), Quantity(Quantity),
                              Restrictions(Restrictions), AnticipatedFunction(AnticipatedFunction),
                              PriceQuote(PriceQuote), OrderID(OrderID),
                              AssignmentInstructionID(AssignmentInstructionID) {}
	~AssignmentInformation() {}
	int AssignmentInformationID;
	std::string Quantity;
	std::string Restrictions;
	std::string AnticipatedFunction;
	std::string PriceQuote;
	std::string OrderID;
	std::string AssignmentInstructionID;
};
#endif /* ASSIGNMENTINFORMATION_H */
