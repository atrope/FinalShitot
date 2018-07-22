#pragma once
#include "Control.h"
#include <string>


using namespace std;

class Label: public Control
{   
    private:
        string value;
    public:
        Label(string value);
        string getValue();
        void setValue(string value);
        void draw(Graphics& g, int x, int y, size_t z);
		bool myPureFunction() { return false; };
};