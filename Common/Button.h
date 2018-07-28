#pragma once
#include "Label.h"

class Button : public Label{
public:
	Button();
	Button(string s);
	Button(string value, Color background, Color foreground);

	bool mousePressed(int x, int y, bool isLeft, Graphics& g);
	virtual bool myPureFunction();
	virtual ~Button();
};

