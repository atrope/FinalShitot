#include "NumericBox.h"

NumericBox::NumericBox(int min=0,int max=99) : TextBox() {
	setActual(min);
	setValue(to_string(min));
	setWidth(to_string(max).size());
	setHeight(1);
}
bool NumericBox::myPureFunction(){return false;}

NumericBox::~NumericBox() {
}