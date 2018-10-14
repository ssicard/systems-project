#include <string>
#pragma once
using namespace std;
class ValueListType
{
public:
	ValueListType(int valueListID);
	~ValueListType();
	int ValueListID;
	string ValueListURN;
	string ValueType;
};

