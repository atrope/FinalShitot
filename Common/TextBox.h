#pragma once
#include "Control.h"

class TextBox : public Control
{
	string value;
public:
	void addValue(char newValue, Graphics& g);
	void delChar(Graphics& g);
	void draw(Graphics& g);
	TextBox() : Control(){setBorder(true);};
	TextBox(short left, short top, short width);
	void keyDown(int keyCode, char character, Graphics& g);
	bool myPureFunction() { return true; };
	~TextBox();
};

