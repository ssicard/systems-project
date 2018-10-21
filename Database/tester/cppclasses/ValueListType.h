#ifndef VALUE_LIST_TYPE_H
#define VALUE_LIST_TYPE_H

#include <string>
#include "SqlBase.h"

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
	std::string ValueListURN;
	std::string ValueType;
};

#endif
