#include <string>
#include "SqlBase.h"
#include "ValueListType.h"
#include "ResponseTypeLookup.h"

#ifndef RESPONSE_INFORMATION_H
#define RESPONSE_INFORMATION_H

namespace platform {

class ResponseInformation : public SqlBase
{
public:
	ResponseInformation(std::string PrecedingResourceInfoElementID = "", std::string ResponseType = "",
                            std::string ReasonCode = "", std::string ResponseReason = "") :
                            PrecedingResourceInfoElementID(PrecedingResourceInfoElementID), ResponseType(ResponseType),
                            ReasonCode(ReasonCode), ResponseReason(ResponseReason) {}
	~ResponseInformation() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ResponseTypeID;
	int ReasonCodeID;

	// they are stored as ints in the db. Is it string for the data?	
	std::string PrecedingResourceInfoElementID;
	std::string ResponseType;
	std::string ReasonCode;
	std::string ResponseReason;
	
	ValueListType _ReasonCode;
	ResponseTypeLookup _ResponseType;
};

}
#endif /* REPONSEINFORMATION_H */
