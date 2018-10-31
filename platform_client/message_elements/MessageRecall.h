#include <string>

#ifndef MESSAGERECALL_H
#define MESSAGERECALL_H

using namespace std;
class MessageRecall
{
public:
	MessageRecall(string RecalledMessageID = "") : RecalledMessageID(RecalledMessageID) {}
	~MessageRecall() {}
	string RecalledMessageID;
	string RecallType;
};
#endif /* MESSAGERECALL_H */
