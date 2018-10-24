#include <string>
#include "SqlBase.h"

#ifndef VALUELISTTYPE_H
#define VALUELISTTYPE_H

class ValueListType : public SqlBase {
public:
	ValueListType(int ValueListID = -1, std::string ValueListURN = "", std::string ValueType = "") :
	 				ValueListID(ValueListID), ValueListURN(ValueListURN), ValueType(ValueType) {}
	~ValueListType() {}
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int ValueListID;
	std::string ValueListURN;
	std::string ValueType;
};
#endif /* VALUELISTTYPE_H */
