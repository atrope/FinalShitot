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
	
	//Panel
	Panel p;
	p.setWidth(80);
	p.setHeight(22);
	p.setTop(4);
	p.setLeft(5);
	p.setBorder(true);				
	p.setColor(Color::Cyan, Color::White);		

	//Label
	string value("Textbox:");						//text in labe
	Label l(value, Color::White, Color::Black);
	l.setTop(1);
	l.setLeft(1);
	p.add(&l);

	
	//NumericBox
	NumericBox nb(-5, 99, 5, 9);
	nb.setColor(Color::Orange, Color::Black);
	p.add(&nb);

	//TextBox 1
	TextBox tb;
	tb.setColor(Color::Red, Color::White);
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(2);
	tb.setLeft(1 + (short)value.size() + 1);
	p.add(&tb);

	//Button
	string test_val("My button");				//text in button
	Button b2(test_val, Color::Green, Color::Blue);
	b2.setTop(13);
	b2.setLeft(5);
	p.add(&b2);


	//MessageBox
	MessageBoxx mb(" Mesasge cool", Color::Green, Color::Black, 25,6);
	p.add(&mb);


	CheckList cl(0, 16, 5);
	cl.setColor(Color::Purple, Color::White);
	p.add(&cl);

	//Radio Box
	RadioBox rb(25, 16, 5);
	rb.setColor(Color::Red, Color::White);
	p.add(&rb);



	//Show Panel with controls on screen
	e.run(p);


}
