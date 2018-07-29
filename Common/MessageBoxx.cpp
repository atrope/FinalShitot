#include "MessageBoxx.h"

MessageBoxx::MessageBoxx(string value, Color background, Color foreground, short left, short top) : Label(value, background, foreground, left, top) {
	string btnok = " OK ";
	string btncancel = " CANCEL ";
	ok.setValue(btnok);
	ok.setLeft(getLeft());
	ok.setTop(getTop()+2);
	ok.setWidth(btnok.size());
	cancel.setValue(btncancel);
	cancel.setLeft(ok.getLeft() + ok.getWidth() + 2);
	cancel.setTop(ok.getTop());
	cancel.setWidth(btncancel.size());

}

void MessageBoxx::setColor(Color background, Color foreground) {
	Control::setColor(background, foreground);
	ok.setColor(background, foreground);
	cancel.setColor(background, foreground);
}

void MessageBoxx::draw(Graphics& g) {
	Label::draw(g);

	ok.drawBorder(g);
	ok.draw(g);
	cancel.drawBorder(g);
	cancel.draw(g);

}

bool MessageBoxx::myPureFunction() { return false; }

MessageBoxx::~MessageBoxx() {
}
