#include <string>
#pragma once
using namespace std;
class ResponseTypeLookup
{
public:
	ResponseTypeLookup(int responseTypeID);
	~ResponseTypeLookup();
	int ResponseTypeID;
	string Description;
};

