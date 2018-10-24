#include <string>
#include "SqlBase.h"

#ifndef RESPONSETYPELOOKUP_H
#define RESPONSETYPELOOKUP_H

class ResponseTypeLookup : public SqlBase {
public:
	ResponseTypeLookup(int ResponseTypeID = -1, std::string Description = "") : ResponseTypeID(ResponseTypeID),
						Description(Description) {}
	~ResponseTypeLookup() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();

	int ResponseTypeID;
	std::string Description;
};
#endif /* RESPONSETYPELOOKUP_H */
