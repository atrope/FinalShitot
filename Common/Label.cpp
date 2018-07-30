#include "Label.h"
#include <iostream>

Label::Label(string value) : Control(), value(value) {}; //constuctor

string Label::getValue()//get value
{
    return this->value;
}

void Label::setValue(string value) //set value
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z) //cheack if the size is good and then write function
{
    if (!z) g.write(value);
}
