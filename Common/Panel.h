#pragma once
#include "Control.h"

class Panel : public Control {
public:
	Panel();
	~Panel();
	bool myPureFunction() { return false; };
	virtual void drawInside(Graphics& g) {};
};

