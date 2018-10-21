#ifndef RADIO_ELEMENT_H
#define RADIO_ELEMENT_H

#include <string>
#include "SqlBase.h"

class RadioElement: public SqlBase
{
public:
	RadioElement(int radioElementID);
	~RadioElement();
    void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	int RadioElementID;
	std::string RadioType;
	std::string RadioChannel;
};

#endif
