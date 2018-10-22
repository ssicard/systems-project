#include <string>

#ifndef RESPONSETYPELOOKUP_H
#define RESPONSETYPELOOKUP_H

class ResponseTypeLookup {
public:
	ResponseTypeLookup(std::string ResponseTypeID = "", std::string Description = "") :
											ResponseTypeID(ResponseTypeID), Description(Description) {}
	~ResponseTypeLookup() {}

	std::string ResponseTypeID;
	std::string Description;
};
#endif /* RESPONSETYPELOOKUP_H */
