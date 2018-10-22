#include <string>

#ifndef TYPEINFOTYPE_H
#define TYPEINFOTYPE_H

class TypeInfoType {
public:
	TypeInfoType(int TypeInfoID, std::string ChildInfo) : TypeInfoID(TypeInfoID),
					ChildInfo(ChildInfo) {}
	~TypeInfoType() {}

	int TypeInfoID;
	std::string ChildInfo;
};
#endif /* TYPEINFOTYPE_H */
