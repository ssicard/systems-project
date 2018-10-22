#include <string>

#ifndef MESSAGERECALL_H
#define MESSAGERECALL_H

class MessageRecall {
public:
	MessageRecall(std::string RecalledMessageID, std::string RecallType) :
	 				RecalledMessageID(RecalledMessageID), RecallType(RecallType) {}
	~MessageRecall() {}

	std::string RecalledMessageID;
	std::string RecallType;
};
#endif /* MESSAGERECALL_H */
