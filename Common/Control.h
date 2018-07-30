#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{
	static Control* focused;

protected:
	vector<Control*> controls;
	short left;
	short top;
	short width, height;
	short parentLeft, parentTop;
	bool isFocus;
	bool isClick;
	bool isBorder;
	Color background, foreground;
	Control* connected_control;

public:
	Control() : left(1), top(1), isFocus(true), width(0), height(0), isBorder(false),parentTop(0),parentLeft(0), connected_control(NULL),background(Color::Black),foreground(Color::White){};

	Control::Control(short left, short top) : isFocus(true), width(0), height(0), parentTop(0), parentLeft(0),isBorder(false), connected_control(NULL), background(Color::Black), foreground(Color::White) { this->left = left; this->top = top; }
	static Control* getFocus() { return focused; };
	static void setFocus(Control& control) { focused = &control; };

	void drawIt(Graphics& g, Control* control);
	virtual void add(Control* newControl);
	virtual void draw(Graphics& g);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter, Graphics& g) {};
	virtual short getLeft() { return left+parentLeft; };
	virtual short getTop() { return top+parentTop; };
	virtual short getHeight() { return height; };
	virtual Color getBackground() { return background; };
	virtual Color getForeground() { return foreground; };
	virtual short getWidth() { return width; };
	virtual void setParentDimensions(short left, short top) { this->parentTop = top; this->parentLeft = left; };
	virtual void setHeight(short height) { this->height = height; };
	virtual void setWidth(short width) { this->width = width; };
	virtual void setTop(short top) { this->top = top; };
	virtual void setLeft(short left) { this->left = left; };
	virtual void setBorder(bool border) { this->isBorder = border; };
	virtual void getAllControls(vector<Control*>* controls);
	virtual int getCrusorLoc() { return left + width; };
	virtual bool canGetFocus() { return isFocus; };
	virtual bool hasBorder() { return isBorder; };
	virtual void drawBorder(Graphics& g, Control* control);

	virtual void setColor(Color background, Color foreground);
	void setConnectedControl(Control* c);
	virtual void drawInside(Graphics& g) = 0;
	virtual bool myPureFunction() = 0;
	~Control();
};
