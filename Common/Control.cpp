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
	for each (Control* control in controls) 
		control->draw(g);
}

void Control::getAllControls(vector<Control*>* controlsCopy) { 
	for (int i = 0; i<controls.size(); i++)
		(*controlsCopy).push_back(controls[i]);
};

void Control::add(Control* newControl)
{
	if (newControl) {
		//newControl->setTop(top + newControl->getTop());
		this->controls.push_back(newControl);
	}
}