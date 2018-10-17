#include <string>
#include "SqlBase.h"
#pragma once
using namespace std;
class ValueListType: public SqlBase
{
public:
	ValueListType(int valueListID);
	ValueListType();
	~ValueListType();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ValueListID;
	string ValueListURN;
	string ValueType;
};

