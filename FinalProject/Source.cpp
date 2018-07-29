#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"

#include "../Common/CheckList.h"

#include "../Common/NumericBox.h"


int main(int argc, char** argv){
	EventEngine e;

	Panel p;
	CheckList cl(0,20,5);
	string value("teste");
	string test_val("My button");
	//p.setWidth(300);
	//p.setHeight(300);
	//p.setColor(Color::Red,Color::White);
	
	Label l(value, Color::White, Color::Black);
	l.setTop(1);
	l.setLeft(1);
	p.add(&l);

	Button b2(test_val, Color::Green, Color::Blue);
	p.add(&cl);
	b2.setTop(20);
	b2.setLeft(20);
	p.add(&b2);
	
	NumericBox nb(0,99);
	nb.setColor(Color::Orange, Color::Black);
	nb.setTop(10);
	nb.setLeft(10);
	p.add(&nb);

	TextBox tb;
	tb.setColor(Color::Red, Color::White);
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(1);
	tb.setLeft(1 + (short)value.size() + 1);
	p.add(&tb);


	e.run(p);
}