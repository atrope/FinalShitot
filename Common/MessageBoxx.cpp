#include "MessageBoxx.h"

MessageBoxx::MessageBoxx(string value, Color background, Color foreground, short left, short top) : Label(value, background, foreground, left, top) {
	string btnok = " OK ";
	string btncancel = " CANCEL ";
	setBorder(true);
	this->isFocus = false;
	this->isClick = true;
	ok.setValue(btnok);
	ok.setLeft(getLeft()+1);
	ok.setTop(getTop()+2);
	ok.setWidth((short)(btnok.size()));
	ok.setColor(background, foreground);
	cancel.setColor(background, foreground);
	cancel.setValue(btncancel);
	cancel.setLeft(ok.getLeft() + ok.getWidth() + 2);
	cancel.setTop(ok.getTop());
	cancel.setWidth((short)(btncancel.size()));
	if (((short)(value.size()) > ok.getWidth() + cancel.getWidth())) setWidth((short)(value.size()) + 3);
	else setWidth(ok.getWidth() + cancel.getWidth() + 3);
	setHeight(4);
}

void MessageBoxx::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	ok.setColor(background, foreground);
	cancel.setColor(background, foreground);
}

void MessageBoxx::draw(Graphics& g) {
	drawIt(g, this);
}
void MessageBoxx::drawInside(Graphics& g) {
	Label::drawInside(g);
	ok.draw(g);
	cancel.draw(g);
}
void MessageBoxx::mousePressed(int x, int y, bool isLeft){
	ok.setColor(getBackground(), getForeground()); //Reset Colors
	cancel.setColor(getBackground(), getForeground()); 
	if (isInside(x, y, &ok)) ok.setColor(Color::Blue,Color::Purple);
	else if (isInside(x, y, &cancel)) cancel.setColor(Color::Blue, Color::Purple);
}


MessageBoxx::~MessageBoxx() {
}
