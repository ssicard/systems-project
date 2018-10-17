#include <string>
#pragma once
using namespace std;
class MessageRecall
{
public:
	MessageRecall(string recalledMessageID);
	~MessageRecall();
	string RecalledMessageID;
	string RecallType;
};

