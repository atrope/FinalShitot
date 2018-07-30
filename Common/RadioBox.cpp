#include "RadioBox.h"

RadioBox::~RadioBox()
{
}

void RadioBox::draw(Graphics& g) {
	drawIt(g, this);
}
void RadioBox::drawInside(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selected) ? "(O) " : "( ) ") + list.at(i).name + ((i == arrow) ? " <=" : "");

		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}

/*
void RadioBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{
	case VK_DOWN:
		if (itemIndex == controls.size() - 1)
			setFocusedItem(0);
		else
			setFocusedItem(itemIndex + 1);
		return;

	case VK_UP:
		if (itemIndex == 0)
			setFocusedItem(controls.size() - 1);
		else
			setFocusedItem(itemIndex - 1);
		return;

	case VK_RETURN:
	case VK_SPACE:
		setSelectedItem(itemIndex, select_sym);
		return;

	default:
		break;
	}
}

void RadioBox::setSelectedItem(const int pos, char symbol)
{
		if (isSelected == FALSE)
		{
			clearSelection();
		}

		string selected = list.at(pos).name;
		if (selected[SYM_MARKER_POS] == symbol) {
			selected[SYM_MARKER_POS] = ' ';
			selected_items.at(pos) = false;
		}
		else {
			selected[SYM_MARKER_POS] = symbol;
			selected_items.at(pos) = true;
		}
		getChildAt(pos)->setValue(selected);
	
}
void RadioBox::clearSelection()
{
	for each (Button* child in _children)
	{
		string selected = child->getValue();
		selected[SYM_MARKER_POS] = ' ';
		child->setValue(selected);
	}
	return;
}
*/

