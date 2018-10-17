#ifndef FUNDING_H
#define FUNDING_H

#include <string>
#include "SqlBase.h"
using namespace std;
class Funding : public SqlBase
{
public:
	Funding(string fundCode);
	~Funding();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	string FundCode;
	string FundingInfo;
};


#endif