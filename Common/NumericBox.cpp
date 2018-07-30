#include "NumericBox.h"

NumericBox::NumericBox(int min=0,int max=99,short left=0,short top=0) : TextBox(left,top, to_string(max).size()+1){
	this->min = min;
	this->max = max;
	setActual(min);
	isFocus = false;
	setValue(" " + to_string(min));
	setHeight(1);

	plus.setValue(" + ");
	plus.setLeft(getLeft() + getWidth() + 2);
	plus.setTop(getTop());
	plus.setWidth(3);


	minus.setValue(" - ");
	minus.setLeft(plus.getLeft() + plus.getWidth() + 2 );
	minus.setTop(getTop());
	minus.setWidth(3);
}

void NumericBox::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	plus.setColor(background, foreground);
	minus.setColor(background, foreground);
}


void NumericBox::draw(Graphics& g) {
	drawIt(g, this);
}
void NumericBox::drawInside(Graphics& g) {
	TextBox::drawInside(g);
	plus.draw(g);
	minus.draw(g);
}


bool NumericBox::myPureFunction(){return false;}

NumericBox::~NumericBox() {
}