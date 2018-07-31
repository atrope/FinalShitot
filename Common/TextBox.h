#pragma once
#include "Control.h"

class TextBox : public Control
{
	string value;
public:
	void addValue(char newValue);
	void delChar(bool type);
	void goBack(int x);
	void goForward(int x);
	void draw(Graphics& g);
	string getValue() { return this->value; };
	void setValue(string value) { this->value = value; };
	virtual void mousePressed(int x, int y, bool isLeft, Graphics& g);
	TextBox() : Control(){setBorder(true);};
	TextBox(short left, short top, short width);
	void keyDown(int keyCode, char character, Graphics& g);
	virtual void drawInside(Graphics& g);

	~TextBox();
};

