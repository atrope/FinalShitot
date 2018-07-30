#include "Control.h"


Control* Control::focused = NULL;

Control::~Control() {
	for each (Control* control in controls)
		if (control)
			delete control;
}

void Control::draw(Graphics& g) {
	for each (Control* control in controls) {
		control->draw(g);
	}
}

void Control::drawIt(Graphics& g, Control* control) {
	Color oldBack = g.getBackground();
	Color oldFore = g.getForeground();
	g.setBackground(control->getBackground());
	g.setForeground(control->getForeground());
	string tmp = " ";
	tmp.resize(control->getWidth());
	for (size_t i = 0; i < control->getHeight(); i++)
		g.write(control->getLeft(), control->getTop() + i, tmp);
	if (control->hasBorder()) control->drawBorder(g,control);
	control->drawInside(g);
	g.setBackground(oldBack);
	g.setForeground(oldFore);
}

void Control::drawBorder(Graphics& g, Control* control){
	g.write(control->getLeft() - 1, control->getTop() - 1, "\xDA"); // Left top
	g.write(control->getLeft() + control->getWidth(), control->getTop() - 1, "\xBF"); // Right Top
	g.write(control->getLeft() - 1, control->getTop()+control->getHeight(), "\xC0"); // Left Bottom
	g.write(control->getLeft() + control->getWidth(), control->getTop()+control->getHeight(), "\xD9"); // right bottom

	for (short i = 0; i < control->getHeight(); i++) { //Vertical
		g.write(control->getLeft() - 1, control->getTop() + i, "\xB3");
		g.write(control->getLeft() + control->getWidth(), control->getTop() + i, "\xB3");
	}
	for (short i = 0; i < width; i++){ // Horizontal
		g.write(control->getLeft() + i, control->getTop() - 1, "\xC4");
		g.write(control->getLeft() + i, control->getTop() + control->getHeight(), "\xC4");
	}
	g.moveTo(control->getLeft(), control->getTop());// Refresh cursor position
}

void Control::getAllControls(vector<Control*>* controlsCopy) {
	for (int i = 0; i < controls.size(); i++)
		(*controlsCopy).push_back(controls[i]);
};

void Control::add(Control* newControl){
	if (newControl) {

		newControl->setParentDimensions(this->getLeft(),this->getTop());
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
