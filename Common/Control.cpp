#include "Control.h"


Control* Control::focused = NULL;

Control::~Control() {
	for each (Control* control in controls)
	{
		if (control)
			delete control;
	}
}

void Control::draw(Graphics& g) {
	for each (Control* control in controls){
		Color oldBack = g.getBackground();
		Color oldFore = g.getForeground();
		g.setBackground(control->background);
		g.setForeground(control->foreground);
		control->draw(g);
		g.setBackground(oldBack);
		g.setForeground(oldFore);
	}
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
