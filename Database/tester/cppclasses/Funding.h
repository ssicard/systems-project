#pragma once
#include <string>

#include "SqlBase.h"
using namespace std;
class Funding: public SqlBase
{
public:
    Funding(string fundCode);
    Funding();
    ~Funding();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
    string FundCode;
    string FundingInfo;
};



