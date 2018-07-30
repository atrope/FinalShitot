#include "TextBox.h"

//Show input in textbox

//Constructor default width = 30
TextBox::TextBox(short left, short top, short width = 30) : Control(left,top){
	this->width = width;
	setBorder(true);
}

//Destructor 
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
	short tmploca = getCursorLoc();
	if (this->value.size() < this->width) {
		this->value.insert(this->value.begin()+ (tmploca++ - getLeft()), newValue); //Remove it
		setCursorLoc(tmploca);
		g.write(getLeft(), getTop(), value);
	}
}

void TextBox::delChar(Graphics& g,bool type) // false=>backspace true=>del
{
	short tmploca = getCursorLoc();
	if (this->value.size() && ((tmploca - getLeft() > 0 && !type) || (type && (tmploca - left)<=this->value.size()))) {
		if (!type) this->value.erase(--tmploca - getLeft(), 1); //Remove it
		else this->value.erase(tmploca - getLeft(), 1); //Remove it
		setCursorLoc(tmploca);
		g.write(getLeft(), getTop(), value); // Draw string without the Char
	}
}

//arrow left
void TextBox::goBack(Graphics& g)
{
	COORD loc = g.GetCursorPosition();
	if (getLeft() <= loc.X - 1) {
		setCursorLoc(loc.X - 1);	
	}
		
}

//Space
void TextBox::goForward(Graphics& g)
{
	COORD loc = g.GetCursorPosition();
	if(value.size() > (loc.X - getLeft())) {
		setCursorLoc(loc.X + 1);
	}
}

//Arrows
void TextBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{
	case VK_DELETE: //Case: Click on backspace and delete
	case VK_BACK:
		this->delChar(g, VK_DELETE == keyCode);
		return;
	case VK_LEFT:
		this->goBack(g);
		return;

	case VK_RIGHT:			//Case: Click on right arrow
		this->goForward(g);
		return;

	default:
		if (keyCode >= 32 && keyCode <= 126) //Key in ASCII Table Must be between Space to ~
		{					
			this->addValue(character, g); //add value to control
		}
		break;
	}

}
/*
bool TextBox::mousePressed(int x, int y, bool isLeft, Graphics& g)
{

	g.setCursorVisibility(true);

	//there could be 2 cases now:
	//1. pressing at an empty (at the end) non written space
	//2. pressing in between letters

	if (value.empty()) {
		g.moveTo(getLeft() , getTop());
	}
	else
	{
		COORD end_str_pos = valueEndPos();

		//case 1:
		//todo: replace this first 'if' with isInTextBoundaries() call:
		if (y >= end_str_pos.Y && x >= end_str_pos.X ||
			y > end_str_pos.Y)
		{
			debug(PG_DBG_INFO, "%s clicked outside text.", fn);
			if (end_str_pos.X == getLeft() + getWidth() - BORDER_OFFSET * 2)
			{
				setLastPos({ getLeft() + 1, end_str_pos.Y });
			}
			else
			{
				setLastPos({ end_str_pos.X + 1, end_str_pos.Y });
			}
		}
		else
		{
			//case 2:
			debug(PG_DBG_INFO, "%s clicked between text.", fn);
			setLastPos({ (short)x, (short)y });
		}
	}
	return true;
}*/