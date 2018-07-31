#pragma once
#include "Control.h"
#include "Item.h"

class CheckList: public Control{
private:
	vector<item> list;
	int arrow;
public:
	CheckList(short left, short top, int optNum);
	CheckList();
	~CheckList();
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	void keyDown(int keyCode, char character, Graphics& g);
	void goUp();
	void goDown();
	void goTab();
	void choose();
};

