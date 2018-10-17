#include <string>
#include "SqlBase.h"
#pragma once
using namespace std;
class RadioElement: public SqlBase
{
public:
	RadioElement(int radioElementID);
	~RadioElement();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int RadioElementID;
	string RadioType;
	string RadioChannel;
};

