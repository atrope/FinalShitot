#include "Control.h"

Control::~Control() {
	for each (Control* control in controls)
	{
		if (control)
			delete control;
	}
}

void Control::draw(Graphics& g) {
	draWrapper(g);
	drawControls(g);
}

void Control::drawControls(Graphics& g) {
	for each (Control* control in controls) {
		control->draw(g);
	}
}

void Control::add(Control* newControl)
{
	if (newControl) {
		newControl->setTop(top + newControl->getTop());

		this->controls.push_back(newControl);
	}
}