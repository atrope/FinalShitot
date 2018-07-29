#include "RadioBox.h"

RadioBox::~RadioBox()
{
}

void RadioBox::draw(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selected) ? "(O) " : "( ) ") + list.at(i).name + ((i == arrow) ? " <=" : "");

		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}
