#pragma once
#include "TextBox.h"
#include "Button.h"
#include <string>


class NumericBox : public TextBox{
protected:
	int min, max,actual;
	Button plus,minus;
public:
	NumericBox(int min,int max,short left,short top);
//	bool mousePressed(int x, int y, bool isLeft, Graphics& g);
	virtual ~NumericBox();
	void setActual(int val) { this->actual = val; }
	int getActual() { return this->actual; }
	virtual void setColor(Color background, Color foreground);
	virtual void mousePressed(int x, int y, bool isLeft, Graphics& g);

	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	virtual void setParentDimensions(short left, short top) {
		this->parentTop = top;
		this->parentLeft = left;
		plus.setParentDimensions(left, top);
		minus.setParentDimensions(left, top);
	};
};

