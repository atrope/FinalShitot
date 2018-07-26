#include "Label.h"
#include <iostream>

Label::Label(string value) : Control(), value(value) {};

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, size_t z)
{
	if (!z) {
		//g.clearScreen();
		g.write(getLeft(), getTop(), value);
	}
}
