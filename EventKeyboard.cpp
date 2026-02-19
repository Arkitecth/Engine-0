#include "EventKeyboard.h"

E0::EventKeyboard::EventKeyboard()
{
	Event::setType(keyboard_event); 

	key = KeyboardKey::UNDEFINED_KEY;
	action = KeyboardAction::UNDEFINED_ACTION;
}

E0::EventKeyboard::EventKeyboard(KeyboardKey new_key, KeyboardAction new_action)
{
	key = new_key;
	action = new_action;
}


E0::KeyboardKey E0::EventKeyboard::getKey()
{
	return key;
}

void E0::EventKeyboard::setKey(KeyboardKey new_key)
{
	key = new_key;
}

E0::KeyboardAction E0::EventKeyboard::getAction()
{
	return action;
}

void E0::EventKeyboard::setKeyboardAction(E0::KeyboardAction new_action)
{
	action = new_action;
}

void E0::EventKeyboard::setKey(std::string new_key)
{
	if(new_key == "SPACE") key = KeyboardKey::SPACE;
	else if (new_key == "RETURN") key = KeyboardKey::RETURN;
	else if (new_key == "ESCAPE") key = KeyboardKey::ESCAPE;
	else if (new_key == "TAB") key = KeyboardKey::TAB;
	else if (new_key == "LEFTARROW") key = KeyboardKey::LEFTARROW;
	else if (new_key == "RIGHTARROW") key = KeyboardKey::RIGHTARROW;
	else if (new_key == "UPARROW") key = KeyboardKey::UPARROW;
	else if (new_key == "DOWNARROW") key = KeyboardKey::DOWNARROW;
	else if (new_key == "PAUSE") key = KeyboardKey::PAUSE;
	else if (new_key == "MINUS") key = KeyboardKey::MINUS;
	else if (new_key == "PLUS") key = KeyboardKey::PLUS;
	else if (new_key == "TILDE") key = KeyboardKey::TILDE;
	else if (new_key == "PERIOD") key = KeyboardKey::PERIOD;
	else if (new_key == "COMMA") key = KeyboardKey::COMMA;
	else if (new_key == "SLASH") key = KeyboardKey::SLASH;
	else if (new_key == "LEFTCONTROL") key = KeyboardKey::LEFTCONTROL;
	else if (new_key == "RIGHTCONTROL") key = KeyboardKey::RIGHTCONTROL;
	else if (new_key == "LEFTSHIFT") key = KeyboardKey::LEFTSHIFT;
	else if (new_key == "RIGHTSHIFT") key = KeyboardKey::RIGHTSHIFT;
	else if (new_key == "F1") key = KeyboardKey::F1;
	else if (new_key == "F2") key = KeyboardKey::F2;
	else if (new_key == "F3") key = KeyboardKey::F3;
	else if (new_key == "F4") key = KeyboardKey::F4;
	else if (new_key == "F5") key = KeyboardKey::F5;
	else if (new_key == "F6") key = KeyboardKey::F6;
	else if (new_key == "F7") key = KeyboardKey::F7;
	else if (new_key == "F8") key = KeyboardKey::F8;
	else if (new_key == "F9") key = KeyboardKey::F9;
	else if (new_key == "F10") key = KeyboardKey::F10;
	else if (new_key == "F11") key = KeyboardKey::F11;
	else if (new_key == "F12") key = KeyboardKey::F12;
	else if (new_key == "A") key = KeyboardKey::A;
	else if (new_key == "B") key = KeyboardKey::B;
	else if (new_key == "C") key = KeyboardKey::C;
	else if (new_key == "D") key = KeyboardKey::D;
	else if (new_key == "E") key = KeyboardKey::E;
	else if (new_key == "F") key = KeyboardKey::F;
	else if (new_key == "G") key = KeyboardKey::G;
	else if (new_key == "H") key = KeyboardKey::H;
	else if (new_key == "I") key = KeyboardKey::I;
	else if (new_key == "J") key = KeyboardKey::J;
	else if (new_key == "K") key = KeyboardKey::K;
	else if (new_key == "L") key = KeyboardKey::L;
	else if (new_key == "M") key = KeyboardKey::M;
	else if (new_key == "N") key = KeyboardKey::N;
	else if (new_key == "O") key = KeyboardKey::O;
	else if (new_key == "P") key = KeyboardKey::P;
	else if (new_key == "Q") key = KeyboardKey::Q;
	else if (new_key == "R") key = KeyboardKey::R;
	else if (new_key == "S") key = KeyboardKey::S;
	else if (new_key == "T") key = KeyboardKey::T;
	else if (new_key == "U") key = KeyboardKey::U;
	else if (new_key == "V") key = KeyboardKey::V;
	else if (new_key == "W") key = KeyboardKey::W;
	else if (new_key == "X") key = KeyboardKey::X;
	else if (new_key == "Y") key = KeyboardKey::Y;
	else if (new_key == "Z") key = KeyboardKey::Z;
	else if (new_key == "1") key = KeyboardKey::NUM1;
	else if (new_key == "2") key = KeyboardKey::NUM2;
	else if (new_key == "3") key = KeyboardKey::NUM3;
	else if (new_key == "4") key = KeyboardKey::NUM4;
	else if (new_key == "5") key = KeyboardKey::NUM5;
	else if (new_key == "6") key = KeyboardKey::NUM6;
	else if (new_key == "7") key = KeyboardKey::NUM7;
	else if (new_key == "8") key = KeyboardKey::NUM8;
	else if (new_key == "9") key = KeyboardKey::NUM9;
	else if (new_key == "0") key = KeyboardKey::NUM0;
	else key = KeyboardKey::UNDEFINED_KEY;   
}


