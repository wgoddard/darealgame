#pragma once
#include "input.h"

#include "hge.h"

extern HGE *hge;

class Keyboard :
	public Input
{
public:
	Keyboard(void);
	virtual ~Keyboard(void);

	void update();
	void rumble();
};
