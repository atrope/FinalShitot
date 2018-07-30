#pragma once
#include "Control.h"

class TextBox : public Control
{
	string value;
public:
	void addValue(char newValue, Graphics& g);
	void delChar(Graphics& g,bool type);
	void goBack(Graphics& g);
	void goForward(Graphics& g);
	void draw(Graphics& g);
	string getValue() { return this->value; };
	void setValue(string value) { this->value = value; };
	//bool mousePressed(int x, int y, bool isLeft, Graphics& g);
	TextBox() : Control(){setBorder(true);};
	TextBox(short left, short top, short width);
	void keyDown(int keyCode, char character, Graphics& g);
	bool myPureFunction() { return true; };
	virtual void drawInside(Graphics& g);

	~TextBox();
};

