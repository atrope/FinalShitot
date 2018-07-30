#pragma once
#include "Control.h"

class TextBox : public Control
{
	int crusorLoc;
	string value;
public:
	void addValue(char newValue, Graphics& g);
	void delChar(Graphics& g);
	void goBack(Graphics& g);
	void goForward(Graphics& g);
	void draw(Graphics& g);
	int getCrusorLoc() { return crusorLoc; };
	string getValue() { return this->value; };
	void setValue(string value) { this->value = value; };
	TextBox() : Control(){setBorder(true);};
	TextBox(short left, short top, short width);
	void keyDown(int keyCode, char character, Graphics& g);
	bool myPureFunction() { return true; };
	virtual void drawInside(Graphics& g);

	~TextBox();
};

