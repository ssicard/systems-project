#include <string>

#ifndef ASSIGNMENTINFORMATION_H
#define ASSIGNMENTINFORMATION_H

class AssignmentInformation {
public:
	AssignmentInformation(std::string AssignmentInformationID = "", std::string Quantity = "",
                        std::string Restrictions = "", std::string AnticipatedFunction = "",
                        std::string PriceQuote = "", std::string OrderID = "", std::string AssignmentInstructionID = "") :
                        AssignmentInformationID(AssignmentInformationID), Quantity(Quantity),
                        Restrictions(Restrictions), AnticipatedFunction(AnticipatedFunction),
                        PriceQuote(PriceQuote), OrderID(OrderID), AssignmentInstructionID(AssignmentInstructionID) {}
	~AssignmentInformation() {}

	std::string AssignmentInformationID;
	std::string Quantity;
	std::string Restrictions;
	std::string AnticipatedFunction;
	std::string PriceQuote;
	std::string OrderID;
	std::string AssignmentInstructionID;
};
#endif /* ASSIGNMENTINFORMATION_H */
