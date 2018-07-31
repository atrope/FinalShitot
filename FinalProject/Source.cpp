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
	string value("teste");
	p.setWidth(80);
	p.setHeight(22);
	p.setTop(4);
	p.setLeft(5);
	p.setBorder(true);
	p.setColor(Color::Cyan, Color::White);
	string test_val("My button");

	/*RadioBox cb(40, 20, 7);

	Label l(value, Color::White, Color::Black);
	l.setTop(1);
	l.setLeft(1);
	p.add(&l);

	p.add(&b2);

	*/
	NumericBox nb(-5, 99, 5, 9);
	nb.setColor(Color::Orange, Color::Black);
	p.add(&nb);
	TextBox tb;
	tb.setColor(Color::Red, Color::White);
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(2);
	tb.setLeft(1 + (short)value.size() + 1);
	TextBox tb2;
	tb2.setColor(Color::Orange, Color::White);
	tb2.setWidth(10);
	tb2.setHeight(1);
	tb2.setTop(5);
	tb2.setLeft(1 + (short)value.size() + 1);
	Button b2(test_val, Color::Green, Color::Blue);
	b2.setTop(13);
	b2.setLeft(5);
	p.add(&b2);

	MessageBoxx mb(" Mesasge cool", Color::Green, Color::Black, 25,6);
	CheckList cl(0, 16, 5);
	cl.setColor(Color::Purple, Color::White);
	RadioBox rb(25, 16, 5);
	rb.setColor(Color::Red, Color::White);

	p.add(&rb);
	p.add(&cl);
	p.add(&mb);
	p.add(&tb2);


	e.run(p);


}
