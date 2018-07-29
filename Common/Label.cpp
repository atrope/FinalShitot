#include "Label.h"
#include <iostream>


Label::Label() : Control(){}

Label::Label(string value) : Control(), value(value) {};

Label::Label(string value, Color background, Color foreground) : Control(), value(value) {
	setColor(background, foreground);
};

Label::Label(string value, Color background, Color foreground, short left, short top) : Control(left, top), value(value) {
	setColor(background, foreground);
};


string Label::getValue(){
	return this->value;
}

void Label::setValue(string value){
	this->value = value;
}


void Label::draw(Graphics& g){
		g.write(getLeft(), getTop(), this->value);
}