#include <string>
#include "SqlBase.h"
#include "AssignmentInstructions.h"

#ifndef ASSIGNMENTINFORMATION_H
#define ASSIGNMENTINFORMATION_H
class AssignmentInformation : public SqlBase
{
public:
//	AssignmentInformation();
//	AssignmentInformation(int assignmentInformationID);
	AssignmentInformation(int AssignmentInformationID = -1, std::string Quantity = "",
                              std::string Restrictions = "", std::string AnticipatedFunction = "",
                              std::string PriceQuote = "", std::string OrderID = "",
                              std::string AssignmentInstructionID = "", int _AssignmentInstructionID = -1 ) :
                              AssignmentInformationID{AssignmentInformationID}, Quantity{Quantity},
                              Restrictions{Restrictions}, AnticipatedFunction{AnticipatedFunction},
                              PriceQuote{PriceQuote}, OrderID{OrderID},
                              AssignmentInstructionID{AssignmentInstructionID},
							  _AssignmentInstructionID{_AssignmentInstructionID} {}
	~AssignmentInformation() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int AssignmentInformationID;
	std::string Quantity;
	std::string Restrictions;
	std::string AnticipatedFunction;
	std::string PriceQuote;
	std::string OrderID;
	std::string AssignmentInstructionID;
	// TODO: Change this
	int _AssignmentInstructionID;
	
	AssignmentInstructions _AssignmentInstructions{};
};
#endif /* ASSIGNMENTINFORMATION_H */
