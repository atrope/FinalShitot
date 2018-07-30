#include "NumericBox.h"

/*
Show number box with special numerical limitation
Max = 99
Min = 0
*/


NumericBox::NumericBox(int min=0,int max=99,short left=0,short top=0) : TextBox(left,top, to_string(max).size()+1){
	this->min = min;
	this->max = max;
	setActual(min);
	setValue(" " + to_string(min));			//enter space for a 2 digit number
	setHeight(1);

	plus.setValue(" + ");					//adding "+" symbol
	plus.setLeft(getLeft() + getWidth() + 2);
	plus.setTop(getTop());		
	plus.setWidth(3);


	minus.setValue(" - ");					//adding "-" symbol
	minus.setLeft(plus.getLeft() + plus.getWidth() + 2 );
	minus.setTop(getTop());
	minus.setWidth(3);

}

//Set Background and ForeGround Color
void NumericBox::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	plus.setColor(background, foreground);
	minus.setColor(background, foreground);
}

//Draw in Screen
void NumericBox::draw(Graphics& g) {
	drawIt(g, this);
}

//Draw number with + - symbo;s
void NumericBox::drawInside(Graphics& g) {
	TextBox::drawInside(g);
	plus.draw(g);
	minus.draw(g);
}


bool NumericBox::myPureFunction(){return false;}


//Destructor
NumericBox::~NumericBox() {
}