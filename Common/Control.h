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
	short width, height, maxWidth;
	bool isFocus;
	bool isClick;
	Color background, foreground;
	Control* connected_control;

public:
	Control() : left(0), top(0), isFocus(true) {};
	static Control* getFocus() { return focused; };
	static void setFocus(Control& control) { focused = &control; };


	virtual void add(Control* newControl);
	void drawGround(Graphics& g);
	virtual void draw(Graphics& g);
	virtual void draWrapper(Graphics& g) {};
	virtual void drawControls(Graphics& g);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter, Graphics& g) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual short getHeight() { return height; };
	virtual short getWidth() { return width; };
	virtual short setHeight(short height) { this->height = height; };
	virtual short setWidth(short width) { this->width = width; };
	virtual void setTop(short top) { this->top = top; };
	virtual void setLeft(short left) { this->left = left; };
	virtual void getAllControls(vector<Control*>* controls) { controls = &(this->controls); };
	virtual short getCrusorLoc() { return left + width; };
	virtual bool canGetFocus() { return isFocus; };
	void setColor(Color background, Color foreground);
	void setConnectedControl(Control* c);
	virtual bool myPureFunction() = 0;
	~Control();
};

