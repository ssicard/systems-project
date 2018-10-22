#include <string>

#ifndef RESPONSEINFORMATION_H
#define RESPONSEINFORMATION_H
class ResponseInformation
{
public:
	ResponseInformation(std::string PrecedingResourceInfoElementID = "", std::string ResponseType = "",
                            std::string ReasonCode = "", std::string ResponseReason = "") :
                            PrecedingResourceInfoElementID(PrecedingResourceInfoElementID), ResponseType(ResponseType),
                            ReasonCode(ReasonCode), ResponseReason(ResponseReason) {}
	~ResponseInformation() {}
	std::string PrecedingResourceInfoElementID;
	std::string ResponseType;
	std::string ReasonCode;
	std::string ResponseReason;
};
#endif /* REPONSEINFORMATION_H */
