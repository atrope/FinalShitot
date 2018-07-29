#pragma once
#include "Control.h"
#include "Item.h"

class RadioBox: public Control
{
private:
	vector<item> list;
	int arrow;
public:
	RadioBox(short left, short top, int optNum) :Control(left, top), arrow(0) {
		for (int i = 0; i < optNum; i++) this->list.push_back({ "Option #" + to_string(i) , false });
	};
	void draw(Graphics& g);
	bool myPureFunction() { return false; };
	~RadioBox();
};