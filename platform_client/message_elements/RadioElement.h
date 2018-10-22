#include <string>

#ifndef RADIOELEMENT_H
#define RADIOELEMENT_H

class RadioElement {
public:
	RadioElement(int RadioElementID, std::string RadioType, std::string RadioChannel) :
	 				RadioElementID(RadioElementID), RadioType(RadioType),
					RadioChannel(RadioChannel) {}
	~RadioElement() {}

	int RadioElementID;
	std::string RadioType;
	std::string RadioChannel;
};
#endif /* RADIOELEMENT_H */
