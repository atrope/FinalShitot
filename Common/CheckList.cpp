#include "CheckList.h"

/*
Checker List:
Show list of option to choose.
It possible to select more than one.

*/

//s
CheckList::CheckList(short left, short top, int optNum) : Control(left, top), arrow(0) { 
	for (int i = 0; i < optNum; i++) 
		this->list.push_back({ "Option #" + to_string(i) , false }); 
};
CheckList::CheckList() : Control(), arrow(0) {
	for (int i = 0; i < 5; i++)
		this->list.push_back({ "Option #" + to_string(i) , false });

}
CheckList::~CheckList()
{
}


//Draw in screen
void CheckList::draw(Graphics& g) {
	drawIt(g, this);
}

void CheckList::drawInside(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selected) ? "[X] " : "[ ] ") + list.at(i).name + ((i == arrow) ? " <=" : "");
		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}
//move cursor up
void CheckList::goUp() { //Move arrow up
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
}
//move cursor down
void CheckList::goDown() { // move arrow down
	arrow = ++arrow % list.size();
}
//Choose Item
void CheckList::choose() { // choose option
	list.at(arrow).selected = !list.at(arrow).selected;
}

void CheckList::keyDown(int keyCode, char character, Graphics& g){
	if (keyCode == VK_DOWN) this->goDown();
	else if (keyCode == VK_UP) this->goUp();
	else if (keyCode == VK_SPACE) this->choose();
}