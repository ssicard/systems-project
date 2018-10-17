#include <string>
#include "SqlBase.h"
#pragma once
using namespace std;
class MessageRecall: public SqlBase
{
public:
	MessageRecall(string recalledMessageID);
	~MessageRecall();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	string RecalledMessageID;
	string RecallType;
};

