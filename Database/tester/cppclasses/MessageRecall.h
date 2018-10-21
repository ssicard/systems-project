#ifndef MESSAGE_RECALL_H
#define MESSAGE_RECALL_H

#include <string>
#include "SqlBase.h"

class MessageRecall: public SqlBase
{
public:
	MessageRecall(std::string recalledMessageID);
	MessageRecall();
	~MessageRecall();
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	std::string RecalledMessageID;
	std::string RecallType;
};

#endif
