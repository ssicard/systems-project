#include <string>
#pragma once
using namespace std;
class ResponseTypeLookup
{
public:
	ResponseTypeLookup(int responseTypeID);
	~ResponseTypeLookup();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int ResponseTypeID;
	string Description;
};

