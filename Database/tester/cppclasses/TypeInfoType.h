#include <string>
#include "SqlBase.h"
#pragma once
using namespace std;
class TypeInfoType: public SqlBase
{
public:
	TypeInfoType(int typeInfoID);
	TypeInfoType();
	~TypeInfoType();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int TypeInfoID;
	string ChildInfo;
};

