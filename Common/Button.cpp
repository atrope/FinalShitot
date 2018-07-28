#include "Button.h"


Button::Button() : Label()
{
	isFocus = false;
	isClick = true;
	setParams(getValue().size(), 1);
}

Button::Button(string s) : Button()
{
	setValue(s);
	setParams(getValue().size(), 1);
}

Button::Button(string value, Color background, Color foreground) : Button()
{
	setValue(value);
	setParams(getValue().size(), 1);
	setColor(background, foreground);
}

void Button::setParams(short width, short height)
{
	setWidth(width);
	setHeight(height);
}

bool Button::mousePressed(int x, int y, bool isLeft, Graphics& g)
{
	if (isLeft) {
		if (!connected_control)
			connected_control->mousePressed(x, y, true);
		else {
			setColor(background, foreground);
		}
		return true;
	}
	return false;
}

bool Button::myPureFunction()
{
	return false;
}

Button::~Button()
{
}