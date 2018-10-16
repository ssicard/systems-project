#include <string>

#ifndef FUNDING_H
#define FUNDING_H

class Funding {
public:
	Funding(std::string FundCode, std::string FundingInfo="") : FundCode(FundCode), FundingInfo(FundingInfo) {}
	~Funding() {}
	string FundCode;
	string FundingInfo;
};

#endif /* FUNDING_H */
