#pragma once
#include "Control.h"
#include "Item.h"

class RadioBox: public Control
{
private:
	vector<item> list;
	int arrow;
	short itemIndex;
	bool isSelected;
	short selected_index;
public:
	RadioBox(short left, short top, int optNum);
	RadioBox();

	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	void keyDown(int keyCode, char character, Graphics& g);
	void goUp();
	void goDown();
	void goTab();
	void choose();
	~RadioBox();
};