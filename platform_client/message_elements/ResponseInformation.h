#include <string>

#ifndef RESPONSEINFORMATION_H
#define RESPONSEINFORMATION_H

class ResponseInformation {
public:
	ResponseInformation(std::string PrecedingResourceInfoElementID, int ResponseTypeID,
						int ReasonCodeID, std::string ResponseReason) :
						PrecedingResourceInfoElementID(PrecedingResourceInfoElementID),
						ResponseTypeID(ResponseTypeID), ReasonCodeID(ReasonCodeID),
						ResponseReason(ResponseReason) {}
	~ResponseInformation() {}

	std::string PrecedingResourceInfoElementID;
	int ResponseTypeID;
	int ReasonCodeID;
	std::string ResponseReason;
};
#endif /* RESPONSEINFORMATION_H */
