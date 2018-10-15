#include <string>
#pragma once
using namespace std;
class RadioElement
{
public:
	RadioElement(int radioElementID);
	~RadioElement();
	int RadioElementID;
	string RadioType;
	string RadioChannel;
};

