#ifndef TYPE_INFO_TYPE_H
#define TYPE_INFO_TYPE_H

#include <string>
#include "SqlBase.h"

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
	std::string ChildInfo;
};

#endif
