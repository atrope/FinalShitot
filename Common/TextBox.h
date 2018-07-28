#pragma once
#include "Control.h"

class TextBox : public Control
{
	string value;
	void draWrapper(Graphics& g);
public:
	void addValue(char newValue, Graphics& g);
	void delChar(Graphics& g);
	void setWidth(short width) { this->maxWidth = width; }
	void draw(Graphics& g);

	TextBox() : Control(){};
	TextBox(short left, short top, short maxWidth);
	void keyDown(int keyCode, char character, Graphics& g);
	bool myPureFunction() { return true; };
	~TextBox();
};

