#include <string>
#pragma once
using namespace std;
class RadioElement
{
public:
	RadioElement(int radioElementID);
	~RadioElement();
	std::string RadioElementID;
	std::string RadioType;
	std::string RadioChannel;
};

