#include "TextBox.h"



TextBox::TextBox(short left, short top, short width = 30) : Control(left,top){
	this->width = width;
	setBorder(true);
}

TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g) {
	drawIt(g, this);
}
void TextBox::drawInside(Graphics& g) {
	string tmp = getValue();
	for (int i = tmp.size(); i<getWidth(); i++)
		tmp.push_back(' ');
	g.write(getLeft(), getTop(), tmp);
}


void TextBox::addValue(char newValue, Graphics& g)
{
	if (this->value.size() < this->width) {
		this->value.push_back(newValue);
		g.write(left, top, value); 
	}
}

void TextBox::delChar(Graphics& g)
{
	if (this->value.size()) {
		this->value.replace(this->value.size() - 1, 1, " ");
		g.write(left, top, value); // Draw string without the Char
		this->value.pop_back(); //Remove it
		g.moveTo(this->getLeft() + this->value.size(), this->getTop()); //Refresh Cursor
	}
}

void TextBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{

	case VK_BACK:
		this->delChar(g);
	default:
		if (keyCode >= 32 && keyCode <= 126)
		{
			this->addValue(character, g);
		}
		break;
	}

}