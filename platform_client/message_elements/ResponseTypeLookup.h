#include <string>

#ifndef RESPONSETYPELOOKUP_H
#define RESPONSETYPELOOKUP_H

class ResponseTypeLookup {
public:
	ResponseTypeLookup(int ResponseTypeID, std::string Description) : ResponseTypeID(ResponseTypeID),
						Description(Description) {}
	~ResponseTypeLookup() {}

	int ResponseTypeID;
	std::string Description;
};
#endif /* RESPONSETYPELOOKUP_H */
