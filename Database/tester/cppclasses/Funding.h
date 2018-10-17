#include <string>
#include "SqlBase.cpp"
#pragma once
using namespace std;
class Funding: public SqlBase
{
public:
	Funding(string fundCode);
	~Funding();
	void getFromDatabase(string fundCode);
    void updateToDatabase();
    bool areFieldsValid();
	string FundCode;
	string FundingInfo;
};



