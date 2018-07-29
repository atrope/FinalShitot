#include "CheckList.h"


CheckList::~CheckList()
{
}

void CheckList::draw(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selected) ? "[X] " : "[ ] ") + list.at(i).name + ((i == arrow) ? " <=" : "");
		
		g.write(this->getLeft(), this->getTop()+i, temp);
	}
}
/*
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

void CheckList::goUp() { //Move arrow up
	int oldArr = arrow;
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
	updateLine(arrow, oldArr);
}
void CheckList::goDown() { // move arrow down
	int oldArr = arrow;
	arrow = ++arrow % list.size();
	updateLine(arrow, oldArr);
}
void CheckList::choose() { // choose option
	list.at(arrow).selected = !list.at(arrow).selected;
	updateLine(arrow);
}
*/
