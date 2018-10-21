#ifndef INCIDENT_INFORMATION_H
#define INCIDENT_INFORMATION_H

#include <string>
#include "SqlBase.h"

class IncidentInformation: public SqlBase
{
public:
	IncidentInformation(std::string incidentID);
	IncidentInformation();
	~IncidentInformation();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	std::string IncidentID;
	std::string IncidentDescription;
};

#endif
