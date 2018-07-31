#pragma once
#include "Control.h"
#include <string>
#include <iostream>


using namespace std;

class Label : public Control
{
private:
	string value;
public:
	Label();
	Label(string value);
	Label(string value, Color background, Color foreground);
	Label(string value, Color background, Color foreground, short left, short top);
	string getValue();
	void setValue(string value);
	void draw(Graphics& g);
	void setForeground(Color color) { this->foreground = color; }
	void setBackground(Color color) { this->background= color; }
	virtual void drawInside(Graphics& g);

};