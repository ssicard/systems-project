#include <string>
#include "SqlBase.h"

#ifndef INCIDENTINFORMATION_H
#define INCIDENTINFORMATION_H

class IncidentInformation : public SqlBase
{
public:
	IncidentInformation(std::string IncidentID = "" , std::string IncidentDescription="") :
                            IncidentID(IncidentID), IncidentDescription(IncidentDescription) {}
	~IncidentInformation() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	std::string IncidentID;
	std::string IncidentDescription;
};
#endif /* INCIDENTINFORMATION_H */
