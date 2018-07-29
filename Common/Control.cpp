#include "Control.h"


Control* Control::focused = NULL;

Control::~Control() {
	for each (Control* control in controls)
	{
		if (control)
			delete control;
	}
}
/////

void Control::draw(Graphics& g) {
	for each (Control* control in controls){
		Color oldBack = g.getBackground();
		Color oldFore = g.getForeground();
		g.setBackground(control->background);
		g.setForeground(control->foreground);
		if (control->hasBorder()) control->drawBorder(g);
		control->draw(g);
		g.setBackground(oldBack);
		g.setForeground(oldFore);
	}
}
void Control::drawBorder(Graphics& g)
{
	g.write(left - 1, top - 1, "\xDA"); // Left top
	g.write(left + width, top - 1, "\xBF"); // Right Top
	g.write(left - 1, top+height, "\xC0"); // Left Bottom
	g.write(left + width, top+height, "\xD9"); // right bottom

	for (short i = 0; i < height; i++) { //Vertical
		g.write(left - 1, top + i, "\xB3");
		g.write(left + width, top + i, "\xB3");
	}
	for (short i = 0; i < width; i++){ // Horizontal
		g.write(left + i, top - 1, "\xC4");
		g.write(left + i, top + height, "\xC4");
	}
	g.moveTo(left, top);// Refresh cursor position
}

void Control::getAllControls(vector<Control*>* controlsCopy) {
	for (int i = 0; i < controls.size(); i++)
		(*controlsCopy).push_back(controls[i]);
};

void Control::add(Control* newControl){
	if (newControl) {
		//newControl->setTop(top + newControl->getTop());
		this->controls.push_back(newControl);
	}
}

void Control::setColor(Color background, Color foreground){
	this->background = background;
	this->foreground = foreground;
}

void Control::setConnectedControl(Control *c)
{
	connected_control = c;
}
