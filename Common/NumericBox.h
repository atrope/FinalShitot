#pragma once
#include "TextBox.h"
#include "Button.h"
#include <string>


class NumericBox : public TextBox{
protected:
	int min, max,actual;
	Button plus;
public:
	NumericBox(int min,int max);
//	bool mousePressed(int x, int y, bool isLeft, Graphics& g);
	virtual bool myPureFunction();
	virtual ~NumericBox();
	void setActual(int val) { this->actual = val; }
	virtual void setColor(Color background, Color foreground);
	void draw(Graphics& g);
};

