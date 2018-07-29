#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
<<<<<<< HEAD
#include "../Common/CheckList.h"
=======
#include "../Common/NumericBox.h"
>>>>>>> bf6c344c4c875f2bb7e4f2f522df20dfb8c2822d

int main(int argc, char** argv){
	EventEngine e;
<<<<<<< HEAD
	Panel p;
	CheckList cl(0,20,5);
	TextBox tb;
=======
	Panel p;	
>>>>>>> bf6c344c4c875f2bb7e4f2f522df20dfb8c2822d
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
<<<<<<< HEAD
	b2.setTop(40);
	b2.setLeft(0);
	p.add(&l); p.add(&b1); p.add(&b2); p.add(&cl);
=======
	b2.setTop(20);
	b2.setLeft(20);
	p.add(&b2);
	
	NumericBox nb(0,99);
	nb.setColor(Color::Orange, Color::Black);
	nb.setTop(10);
	nb.setLeft(10);
	p.add(&nb);

	TextBox tb;
>>>>>>> bf6c344c4c875f2bb7e4f2f522df20dfb8c2822d
	tb.setColor(Color::Red, Color::White);
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(1);
	tb.setLeft(1 + (short)value.size() + 1);
	p.add(&tb);


	e.run(p);
}