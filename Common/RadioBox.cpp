#include "RadioBox.h"

RadioBox::~RadioBox()
{
}

RadioBox::RadioBox(short left, short top, int optNum) : Control(left, top), arrow(0) {
	for (int i = 0; i < optNum; i++)
		this->list.push_back({ "Option #" + to_string(i) , false });
};
RadioBox::RadioBox() : Control(), arrow(0) {
	for (int i = 0; i < 5; i++)
		this->list.push_back({ "Option #" + to_string(i) , false });
}
void RadioBox::draw(Graphics& g) {
	drawIt(g, this);
}
void RadioBox::drawInside(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selected) ? "(o) " : "( ) ") + list.at(i).name + ((i == arrow) ? " <=" : "");

		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}

//move cursor up
void RadioBox::goUp() { //Move arrow up
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
}
//move cursor down
void RadioBox::goDown() { // move arrow down
	arrow = ++arrow % list.size();
}
//Choose Item
void RadioBox::choose() { // choose option
	for (size_t i = 0; i < this->list.size(); i++)
		list.at(i).selected = false;
	list.at(arrow).selected = true;
}

void RadioBox::keyDown(int keyCode, char character, Graphics& g) {
	if (keyCode == VK_DOWN) this->goDown();
	else if (keyCode == VK_UP) this->goUp();
	else if (keyCode == VK_SPACE) this->choose();
}
