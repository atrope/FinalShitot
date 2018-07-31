#pragma once
#include "Control.h"
#include "Item.h"

class CheckList: public Control
{

private:
	vector<item> list;
	int arrow;
	//void updateLine(int line, int line2);
public:
	CheckList(short left, short top, int optNum):Control(left,top), arrow(0) {
		for (int i = 0; i < optNum; i++) this->list.push_back({ "Option #" + to_string(i) , false }); };
	~CheckList();
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);

	//void goUp();
	//void goDown();
	//void choose();
};

