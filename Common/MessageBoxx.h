#pragma once
#include "Label.h"
#include "Button.h"
#include <string>


class MessageBoxx : public Label {
protected:
	Button ok, cancel;
public:
	MessageBoxx(string value, Color background, Color foreground, short left, short top);
	virtual ~MessageBoxx();
	virtual void setColor(Color background, Color foreground);
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	virtual void setParentDimensions(short left, short top) { 
		this->parentTop = top; 
		this->parentLeft = left; 
		ok.setParentDimensions(left, top);
		cancel.setParentDimensions(left, top);
	};
	virtual void mousePressed(int x, int y, bool isLeft, Graphics& g);

};
