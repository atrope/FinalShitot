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


void TextBox::addValue(char newValue)
{
	short tmploca = getCursorLoc();
	if ((short)(this->value.size()) < this->width) {
		this->value.insert(this->value.begin()+ (tmploca++ - getLeft()), newValue); //Remove it
		setCursorLoc(tmploca);
	}
}

void TextBox::delChar(bool type) // false=>backspace true=>del
{
	short tmploca = getCursorLoc();
	if (this->value.size() && ((tmploca - getLeft() > 0 && !type) || (type && (tmploca - getLeft())<= (short)(this->value.size())))) {
		if (!type) this->value.erase(--tmploca - getLeft(), 1); //Remove it
		else this->value.erase(tmploca - getLeft(), 1); //Remove it
		setCursorLoc(tmploca);
	}
}

//arrow left
void TextBox::goBack(int x)
{
	if (getLeft() <= --x) setCursorLoc(x);	
}

//Arrow Right
void TextBox::goForward(int x){
	if((short)(this->value.size()) > (x - getLeft())) setCursorLoc(x + 1);
}

//Arrows
void TextBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{
	case VK_DELETE: //Case: Click on backspace and delete
	case VK_BACK:
		this->delChar(VK_DELETE == keyCode);
		return;
	case VK_LEFT:
		this->goBack(g.GetCursorPosition().X);
		return;

	case VK_RIGHT:			//Case: Click on right arrow
		this->goForward(g.GetCursorPosition().X);
		return;

	default:
		if (keyCode >= 48 && keyCode <= 126 || keyCode==32) //Key in ASCII Table Must be between Space to ~
		this->addValue(character); //add value to control
		
		break;
	}

}