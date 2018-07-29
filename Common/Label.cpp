#include "Label.h"
#include <iostream>


Label::Label() : Control(){}

Label::Label(string value) : Control(), value(value) {
	this->setWidth(value.size());
	this->setHeight(1);
};

Label::Label(string value, Color background, Color foreground) : Control(), value(value) {
	setColor(background, foreground);
	this->setWidth(value.size());
	this->setHeight(1);

};

Label::Label(string value, Color background, Color foreground, short left, short top) : Control(left, top), value(value) {
	setColor(background, foreground);
	this->setWidth(value.size());
	this->setHeight(1);

};


string Label::getValue(){

	return this->value;
}

void Label::setValue(string value){
	this->setWidth(value.size());
	this->setHeight(1);

	this->value = value;
}


void Label::draw(Graphics& g) {
	drawIt(g, this);
}
void Label::drawInside(Graphics& g) {
	g.write(getLeft(), getTop(), this->value);
}

