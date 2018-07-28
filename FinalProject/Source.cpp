#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"

int main(int argc, char** argv)
{
	EventEngine e;
	Panel p;	
	TextBox tb;
	string value("teste");
	Label l(value,Color::White,Color::Black);
	l.setTop(1);
	l.setLeft(1);
	p.add(&l);
	tb.setWidth(10);
	tb.setTop(1);
	tb.setLeft(1 + (short)value.size() + 1);
	p.add(&tb);
	e.run(p);
}