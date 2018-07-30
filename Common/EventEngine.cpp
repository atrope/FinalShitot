#include "EventEngine.h"
#include "TextBox.h"
#include "Panel.h"
#include <vector>
#include <algorithm>
using namespace std;

/*
Event Engine
*/

EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

//if user can interract with the control
static void setFocusable(Control& main)
{
	vector<Control*> controls;
	//,controlstmp;
	main.getAllControls(&controls);

	if (!controls.empty()){
		//if every control can't be focused by definition, defaultly set the 1st one as focused to avoid empty references:
		Control::setFocus(*(controls.at(0)));
		
		for (size_t i = 0; i < controls.size(); i++)
		{
			if (controls.at(i)->canGetFocus()){
				Control::setFocus(*(controls.at(i)));
				//controls.at(i)->getAllControls(&controlstmp);
				//if (controlstmp.empty()) return;
				//else return setFocusable(*(controls.at(i)));
				return;
			}
		}
	}
	else {
		Control::setFocus(main);
	}
	return;
}
void EventEngine::run(Control &main)
{
	bool redraw = true;
	setFocusable(main);
	while (1)
	{
		if (redraw){
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			main.draw(_graphics);
			redraw = false;
		}
		auto focused = Control::getFocus();

		if (focused != NULL && typeid(TextBox)==typeid((*focused))){
			_graphics.setCursorVisibility(true);
				_graphics.moveTo(focused->getCursorLoc(), focused->getTop());
		}

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			if (focused != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
					moveFocus(main, focused);
				else
					focused->keyDown(code, chr, _graphics);
				redraw = true;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - main.getLeft();
			auto y = coord.Y - main.getTop();
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				main.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}


//Destructor
EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}


void EventEngine::moveFocus(Control &main, Control *focused)
{
	vector<Control*> controls;
	main.getAllControls(&controls);
	if (!controls.empty()) {
		auto iterator = find(controls.begin(), controls.end(), focused);
		do
			if (++iterator == controls.end())
				iterator = controls.begin();
		while (!(*iterator)->canGetFocus());
		Control::setFocus(**iterator);
	}
}
