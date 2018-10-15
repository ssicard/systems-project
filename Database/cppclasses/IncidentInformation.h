#include <string>
#pragma once
using namespace std;
class IncidentInformation
{
public:
	IncidentInformation(string incidentID);
	~IncidentInformation();
	string IncidentID;
	string IncidentDescription;
};

