#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	Label l("Hello World", Color::Orange, Color::Cyan, 60, 10);
	Label l1("Hello Fabian", Color::Green, Color::White,20,20);
	Control& l2 = l;
	EventEngine e;
	e.run(l2);
	///l2.
	cout << "HERE" << endl;
//	l2 = l1;

}