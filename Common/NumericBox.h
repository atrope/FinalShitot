#pragma once
#include "TextBox.h"
#include <string>


class NumericBox : public TextBox{
protected:
	int min, max,actual;
public:
	NumericBox(int min,int max);
//	bool mousePressed(int x, int y, bool isLeft, Graphics& g);
	virtual bool myPureFunction();
	virtual ~NumericBox();
	void setActual(int val) { this->actual = val; }
	
};

