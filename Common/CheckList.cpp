#include "CheckList.h"

/*
Checker List:
Show list of option to choose.
It possible to select more than one.

*/

//Destructor
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
/*

//mark as selected or unselected

void CheckList::updateLine(int line, int line2 = -1) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info); // Get the number of cols so we can clear it
	COORD tmppos = { static_cast<short>(this->position.X), static_cast<short>(this->position.Y + line) };
	SetConsoleCursorPosition(out, tmppos);
	cout << string(info.dwSize.X, ' '); // Clear line
	SetConsoleCursorPosition(out, tmppos); //refresh Cursor position so we can write in  right place
	cout << "\r" << ((list.at(line).selected) ? "[X] " : "[ ] ") << list.at(line).name << ((line == arrow) ? " <=" : "");
	if (line2 >= 0) updateLine(line2); // If we received 2 lines, send it to update also
}

//move cursor up

void CheckList::goUp() { //Move arrow up
	int oldArr = arrow;
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
	updateLine(arrow, oldArr);
}

//move cursor down

void CheckList::goDown() { // move arrow down
	int oldArr = arrow;
	arrow = ++arrow % list.size();
	updateLine(arrow, oldArr);
}

//select

void CheckList::choose() { // choose option
	list.at(arrow).selected = !list.at(arrow).selected;
	updateLine(arrow);
}
*/
