//#pragma once
#ifndef FUNDING_H
#define FUNDING_H

#include <string>
#include "SqlBase.h"

class Funding: public SqlBase
{
public:
    Funding(std::string fundCode);
    Funding();
    ~Funding();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
    std::string FundCode;
    std::string FundingInfo;
};

#endif
