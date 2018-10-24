#include <string>
#include "SqlBase.h"

#ifndef RADIOELEMENT_H
#define RADIOELEMENT_H

class RadioElement : public SqlBase
{
public:
	RadioElement(int RadioElementID = -1, std::string RadioType = "", std::string RadioChannel = "") :
	 				RadioElementID(RadioElementID), RadioType(RadioType),
					RadioChannel(RadioChannel) {}
	~RadioElement() {}

    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int RadioElementID;
	std::string RadioType;
	std::string RadioChannel;
};
#endif /* RADIOELEMENT_H */
