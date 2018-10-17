#include <string>
#ifndef INCIDENTINFORMATION_H
#define INCIDENTINFORMATION_H

class IncidentInformation
{
public:
	IncidentInformation(std::string IncidentID, std::string IncidentDescription="") :
                            IncidentID(IncidentID), IncidentDescription(IncidentDescription) {}
	~IncidentInformation() {}
	std::string IncidentID;
	std::string IncidentDescription;
};
#endif /* INCIDENTINFORMATION_H */
