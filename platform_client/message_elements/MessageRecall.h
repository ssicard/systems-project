#include <string>
#include "SqlBase.h"

#ifndef MESSAGERECALL_H
#define MESSAGERECALL_H


class MessageRecall : public SqlBase
{
public:
	MessageRecall(std::string RecalledMessageID = "") : RecalledMessageID(RecalledMessageID) {}
	~MessageRecall() {}
	void getFromDatabase();
    void insertIntoDatabase();
    bool areFieldsValid();
	std::string RecalledMessageID;
	std::string RecallType;
};
#endif /* MESSAGERECALL_H */
