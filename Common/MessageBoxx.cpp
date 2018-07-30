#include "MessageBoxx.h"

MessageBoxx::MessageBoxx(string value, Color background, Color foreground, short left, short top) : Label(value, background, foreground, left, top) {
	string btnok = " OK ";
	string btncancel = " CANCEL ";
	setBorder(true);
	ok.setValue(btnok);
	ok.setLeft(getLeft()+1);
	ok.setTop(getTop()+2);
	ok.setWidth(btnok.size());
	ok.setColor(background, foreground);
	cancel.setColor(background, foreground);
	cancel.setValue(btncancel);
	cancel.setLeft(ok.getLeft() + ok.getWidth() + 2);
	cancel.setTop(ok.getTop());
	cancel.setWidth(btncancel.size());
	if ((value.size() > ok.getWidth() + cancel.getWidth())) {
		setWidth(value.size() + 3);
	}
	else {
		setWidth(ok.getWidth() + cancel.getWidth() + 3);
	}
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
bool MessageBoxx::myPureFunction() { return false; }

MessageBoxx::~MessageBoxx() {
}
