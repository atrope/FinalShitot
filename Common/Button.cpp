#include "Button.h"

/*
	Button, has behaviour
*/


Button::Button() : Label(){ //Button ihnerit from Label so, is create also a Label when the Consturctor is Called
	this->isFocus = false;
	this->isClick = true;
	setWidth(getValue().size());
	setHeight(1);
	setBorder(true);
}


Button::Button(string value) : Label(value){ //Constructor as Default but Recieving String
	setWidth(getValue().size());
	this->isClick = true;

	setHeight(1);
	setBorder(true);

}
//Constructor as Default but Recieving Value, Backgroung, Foregroud Colors
Button::Button(string value, Color background, Color foreground) : Label(value,background,foreground){
	setWidth(getValue().size());
	this->isClick = true;

	setHeight(1);
	setBorder(true);

}
void Button::mousePressed(int x, int y, bool isLeft, Graphics& g) {
	setColor(Color::Blue, Color::Purple);
}

//Destructor
Button::~Button(){
}