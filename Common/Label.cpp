#include "Label.h"
#include <iostream>


Label::Label() : Control(){ this->isFocus = false; }

Label::Label(string value) : Control(), value(value) {//the text that it get and set,defualt size of the label by text we get
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocus = false;
};

Label::Label(string value, Color background, Color foreground) : Control(), value(value) {//adding a background and frame color and set by the size
	setColor(background, foreground);
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocus = false;

};

Label::Label(string value, Color background, Color foreground, short left, short top) : Control(left, top), value(value) {//inheratence from the interface control to now where to put the label
	setColor(background, foreground);
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocus = false;

};


string Label::getValue(){

	return this->value;
}

void Label::setValue(string value){
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->value = value;
}


void Label::draw(Graphics& g) {//for default  draw the label 
	drawIt(g, this);
}
void Label::drawInside(Graphics& g) {//draw with parmeters
	g.write(getLeft(), getTop(), this->value);
}