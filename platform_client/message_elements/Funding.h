#include <string>
#include "SqlBase.h"

#ifndef FUNDING_H
#define FUNDING_H

class Funding : public SqlBase 
{
public:
	Funding(std::string FundCode = "", std::string FundingInfo="") : FundCode(FundCode), FundingInfo(FundingInfo) {}
	~Funding() {}
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	std::string FundCode;
	std::string FundingInfo;
};

#endif /* FUNDING_H */
