#include <string>
#include "SqlBase.cpp"
#pragma once
using namespace std;
class Funding: public SqlBase
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



