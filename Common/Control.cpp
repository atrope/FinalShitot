#include "Control.h"

Control::Control() : isFocus(true), left(0), top(0), width(0), height(0), connected_control(NULL) {}

Control* Control::focused = NULL;

Control::~Control() {
	for each (Control* control in controls)
	{
		if (control)
			delete control;
	}
}

void Control::drawGround(Graphics& g) {
	g.setBackground(background);
	g.setForeground(foreground);
}

void Control::draw(Graphics& g) {
	drawGround(g);
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

void Control::setColor(Color background, Color foreground)
{
	this->background = background;
	this->foreground = foreground;
}

void Control::setConnectedControl(Control *c)
{
	connected_control = c;
}
