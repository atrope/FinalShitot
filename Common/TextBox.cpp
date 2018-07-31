#include "TextBox.h"

//Show input in textbox

//Constructor default width = 30
TextBox::TextBox(short left, short top, short width = 30) : Control(left,top){
	this->width = width;
	setBorder(true);
	this->isClick = true;
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

void TextBox::mousePressed(int x, int y, bool isLeft, Graphics& g) {
	setCursorLoc(getCursorLoc());
	g.setCursorVisibility(true);
}