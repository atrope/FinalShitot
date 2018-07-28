#include "TextBox.h"



TextBox::TextBox(short left, short top, short width = 30) : Control(left,top)
{
	this->width = width;
}

TextBox::~TextBox()
{
}

void TextBox::draw(Graphics& g) {
	TextBox::draWrapper(g);
}

void TextBox::draWrapper(Graphics& g)
{
	g.write(left-1, top, "\xB3");
	g.write(left + width, top, "\xB3");
	g.write(left - 1, top - 1, "\xDA");
	g.write(left - 1, top + 1, "\xC0");
	g.write(left + width, top - 1, "\xBF");
	g.write(left + width, top + 1, "\xD9");
	for (short i = 0; i < width; i++)
	{
		g.write(left + i, top - 1, "\xC4");
		g.write(left + i, top + 1, "\xC4");
	}
	g.moveTo(left, top);// Refresh cursor position
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