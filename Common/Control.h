#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{

protected:
	short left;
	short top;
	
public:
	Control();
	Control(short left,short top);
	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return this->left; };
	virtual short getTop() { return this->top; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	virtual bool myPureFunction() = 0;
	~Control();
};

