#include <string>
#include "SqlBase.h"

#ifndef TYPEINFOTYPE_H
#define TYPEINFOTYPE_H

class TypeInfoType : public SqlBase {
public:
	TypeInfoType(int TypeInfoID = -1, std::string ChildInfo = "") : TypeInfoID(TypeInfoID),
					ChildInfo(ChildInfo) {}
	~TypeInfoType() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int TypeInfoID;
	std::string ChildInfo;
};
#endif /* TYPEINFOTYPE_H */
