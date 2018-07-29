#include "NumericBox.h"

NumericBox::NumericBox(int min=0,int max=99) : TextBox()  {
	setActual(min);
	setValue(to_string(min));
	setWidth(to_string(max).size());
	setHeight(1);
	plus.setValue("+");
	plus.setLeft(getLeft()+getWidth()+2);
	plus.setTop(getTop());

}

void NumericBox::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	plus.setColor(background, foreground);
}

void NumericBox::draw(Graphics& g) {
	TextBox::draw(g);
	plus.draw(g);
}

bool NumericBox::myPureFunction(){return false;}

NumericBox::~NumericBox() {
}