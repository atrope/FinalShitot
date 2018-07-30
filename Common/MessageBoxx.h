#pragma once
#include "Label.h"
#include "Button.h"
#include <string>


class MessageBoxx : public Label {
protected:
	Button ok, cancel;
public:
	MessageBoxx(string value, Color background, Color foreground, short left, short top);
	//	bool mousePressed(int x, int y, bool isLeft, Graphics& g);
	virtual bool myPureFunction();
	virtual ~MessageBoxx();
	virtual void setColor(Color background, Color foreground);
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
};
