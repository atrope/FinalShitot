#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include "../Common/MessageBoxx.h"
#include "../Common/RadioBox.h"

int main(int argc, char** argv){
	EventEngine e;

	Panel p;
	CheckList cl(0,20,5);
	RadioBox cb(40, 20, 7);
	string value("teste");
	string test_val("My button");
	p.setWidth(80);
	p.setHeight(28);
	p.setTop(4);
	p.setLeft(3);
	p.setBorder(true);
	p.setColor(Color::Cyan,Color::White);

	Label l(value, Color::White, Color::Black);
	l.setTop(1);
	l.setLeft(1);
	p.add(&l);

	Button b2(test_val, Color::Green, Color::Blue);
	p.add(&cb);
	p.add(&cl);
	b2.setTop(20);
	b2.setLeft(20);
	p.add(&b2);

	NumericBox nb(0,99,10,10);
	nb.setColor(Color::Orange, Color::Black);
	p.add(&nb);

	TextBox tb;
	tb.setColor(Color::Red, Color::White);
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(2);
	tb.setLeft(1 + (short)value.size() + 1);
	p.add(&tb);

	MessageBoxx mb(" Mesasge cool", Color::Green, Color::Black, 5,5);
	p.add(&mb);

	e.run(p);
}
