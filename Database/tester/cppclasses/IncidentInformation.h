#include <string>
#pragma once
#include "SqlBase.h"
using namespace std;
class IncidentInformation: public SqlBase
{
public:
	IncidentInformation(string incidentID);
	~IncidentInformation();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	string IncidentID;
	string IncidentDescription;
};

