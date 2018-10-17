#ifndef FUNDING_H
#define FUNDING_H

#include <string>
<<<<<<< HEAD

=======
>>>>>>> database2
#include "SqlBase.h"
using namespace std;
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
<<<<<<< HEAD
=======


#endif
>>>>>>> database2
