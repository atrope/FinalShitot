#include "Button.h"


Button::Button() : Label(){
	isFocus = false;
	isClick = true;
	setWidth(getValue().size() + 1 + 1); //1 for each side
}

Button::Button(string value) : Label(value)
{
	setWidth(getValue().size() + 1 + 1); //1 for each side
	setHeight(2); //Text height, should create constants File
}

Button::Button(string value,Color back, Color fore) : Label(value, background, foreground){
	setWidth(getValue().size() + 1 + 1); //1 for each side
	setHeight(2); //Text height, should create constants File
}

bool Button::mousePressed(int x, int y, bool isLeft, Graphics& g)
{
	if (isLeft) {
		if (!connected_control) connected_control->mousePressed(x, y, true);
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