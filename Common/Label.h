#pragma once
#include "Control.h"
#include <string>
#include <iostream>


using namespace std;

class Label: public Control
{   
    private:
        string value;
		Color background;
		Color foreground;
    public:
        Label(string value);
		Label(string value, Color background, Color foreground);
		Label(string value, Color background, Color foreground,short left,short top);
		string getValue();
        void setValue(string value);
        void draw(Graphics& g, int x, int y, size_t z);
		bool myPureFunction() { return false; };
		Control* getFocus() { cout << "here "<< endl;  return this; };

};