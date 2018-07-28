#include "Label.h"
#include <iostream>



Label::Label(string value) : Control(), value(value), background(Color::Black), foreground(Color::White) {};

Label::Label(string value, Color background, Color foreground) : Control(), value(value), background(background), foreground(foreground) {};

Label::Label(string value, Color background, Color foreground,short left,short top) : Control(left,top), value(value), background(background), foreground(foreground) {};


string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
	//cout << "HERE " << value << endl;
 	if (!z) {
		g.setBackground(this->background);
		g.setForeground(this->foreground);
		g.write(x,y,this->value);
		}
	}
