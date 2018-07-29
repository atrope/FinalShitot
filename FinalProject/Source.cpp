#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"

int main(int argc, char** argv)
{
	EventEngine e;
	Panel p;
	CheckList cl(0,20,5);
	TextBox tb;
	string value("teste");
	string test_val("My button");
	p.setWidth(300);
	p.setHeight(300);
	p.setColor(Color::Red,Color::White);
	Button b1(value, Color::White, Color::Black);
	b1.setTop(21);
	b1.setLeft(21);
	Label l(value, Color::White, Color::Black);
	l.setTop(1);
	l.setLeft(1);
	Button b2(test_val, Color::Green, Color::Blue);
	b2.setTop(40);
	b2.setLeft(0);
	p.add(&l); p.add(&b1); p.add(&b2); p.add(&cl);
	tb.setColor(Color::Red, Color::White);
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(1);
	tb.setLeft(1 + (short)value.size() + 1);
	p.add(&tb);
	e.run(p);
}