#include "Label.h"
#include <iostream>


Label::Label() : Control(){}

Label::Label(string value) : Control(), value(value), background(Color::Black), foreground(Color::White) {};

Label::Label(string value, Color background, Color foreground) : Control(), value(value), background(background), foreground(foreground) {};

Label::Label(string value, Color background, Color foreground, short left, short top) : Control(left, top), value(value), background(background), foreground(foreground) {};


string Label::getValue(){
	return this->value;
}

void Label::setValue(string value){
	this->value = value;
}


void Label::draw(Graphics& g){
		Color oldBack = g.getBackground();
		Color oldFore = g.getForeground();
		g.setBackground(this->background);
		g.setForeground(this->foreground);
		g.write(getTop(), getLeft(), this->value);
		g.setBackground(oldBack);
		g.setForeground(oldFore);
}