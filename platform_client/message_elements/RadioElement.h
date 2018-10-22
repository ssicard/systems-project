#include <string>

#ifndef RADIOELEMENT_H
#define RADIOELEMENT_H

class RadioElement {
public:
	RadioElement(std::string RadioElementID = "", std::string RadioType = "", std::string RadioChannel = "") :
	 							RadioElementID(RadioElementID), RadioType(RadioType), RadioChannel(RadioChannel) {}
	~RadioElement() {}

	std::string RadioElementID;
	std::string RadioType;
	std::string RadioChannel;
};
#endif /* RADIOELEMENT_H */
