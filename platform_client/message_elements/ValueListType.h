#include <string>

#ifndef VALUELISTTYPE_H
#define VALUELISTTYPE_H

class ValueListType {
public:
	ValueListType(std::string ValueListID = "", std::string ValueListURN = "", std::string ValueType = "") :
	 				ValueListID(ValueListID), ValueListURN(ValueListURN), ValueType(ValueType) {}
	~ValueListType() {}

	std::string ValueListID;
	std::string ValueListURN;
	std::string ValueType;
};
#endif /* VALUELISTTYPE_H */
