#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"

int main(int argc, char** argv)
{
	Label l("Hello World");
	Control& l2 = l;
	EventEngine e;
	e.run(l);
}