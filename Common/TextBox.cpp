#include "TextBox.h"

//Show input in textbox

//Constructor default width = 30
TextBox::TextBox(short left, short top, short width = 30) : Control(left,top){
	this->width = width;
	setBorder(true);
	crusorLoc = left; 			//set on left
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
	if (this->value.size() > this->width) {
		if (this->value.size() > this->crusorLoc) {
			this->value.replace(this->crusorLoc -1, 1, &newValue);
		}
		else {
			this->value.push_back(newValue);
			
		}
		g.write(left, top, value); 
		crusorLoc++;					//move cursor right
	}
}

//Deleting Char 
void TextBox::delChar(Graphics& g)
{
	if (this->value.size()) {
		this->value.replace(this->value.size() - 1, 1, " ");
		g.write(left, top, value); // Draw string without the Char
		this->value.pop_back(); //Remove it
		g.moveTo(this->getLeft() + this->value.size(), this->getTop()); //Refresh Cursor
		--crusorLoc;
	}
}

//BackSpace
void TextBox::goBack(Graphics& g)
{
	COORD loc = g.GetCursorPosition();
	if (left < loc.X - 1) {
		crusorLoc = loc.X - 1;
		g.moveTo(loc.X - 1, top); //Refresh Cursor	
	}
		
}

//Space
void TextBox::goForward(Graphics& g)
{
	COORD loc = g.GetCursorPosition();
	if(left + width > loc.X + 1) {
		crusorLoc = loc.X + 1;
		g.moveTo(loc.X + 1, top); //Refresh Cursor	
	}
}

//Arrows
void TextBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{

	case VK_BACK:			//Case: Click on backspace
		this->delChar(g);

	case VK_LEFT:			//Case: Click on left arrow
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