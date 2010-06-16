#pragma once

#include <ostream>

class Object
{
protected:
	//None here... abstracted
public:
	Object(void);
	~Object(void);

	void toString(std::ostream stream);
};
