#include "Button.h"

/*
	Button, has behaviour
*/


Button::Button() : Label(){ //Button ihnerit from Label so, is create also a Label when the Consturctor is Called
	isFocus = false;
	isClick = true;
	setWidth(getValue().size());
	setHeight(1);
	setBorder(true);
}


Button::Button(string value) : Label(value){ //Constructor as Default but Recieving String
	setWidth(getValue().size());
	setHeight(1);
	setBorder(true);

}
//Constructor as Default but Recieving Value, Backgroung, Foregroud Colors
Button::Button(string value, Color background, Color foreground) : Label(value,background,foreground){
	setWidth(getValue().size());
	setHeight(1);
	setBorder(true);

}

/*
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
}*/


bool Button::myPureFunction()
{
	return false;
}

//Destructor
Button::~Button(){
}