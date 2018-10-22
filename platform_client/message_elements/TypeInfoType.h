#include <string>

#ifndef TYPEINFOTYPE_H
#define TYPEINFOTYPE_H

class TypeInfoType {
public:
	TypeInfoType(std::string TypeInfoID = "", std::string ChildInfo = "") : TypeInfoID(TypeInfoID),
					ChildInfo(ChildInfo) {}
	~TypeInfoType() {}

	std::string TypeInfoID;
	std::string ChildInfo;
};
#endif /* TYPEINFOTYPE_H */
