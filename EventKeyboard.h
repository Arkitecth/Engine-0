#include "Event.h"

namespace E0
{
	const std::string keyboard_event = "keyboard_event";

	enum class KeyboardKey
	{
		UNDEFINED_KEY = -1, 
		SPACE, 
		RETURN,
		ESCAPE, 
		TAB, 
		LEFTARROW, 
		RIGHTARROW, 
		UPARROW, 
		DOWNARROW,
		PAUSE , 
		MINUS , 
		PLUS , 
		TILDE , 
		PERIOD , 
		COMMA , 
		SLASH , 
		LEFTCONTROL ,
		RIGHTCONTROL , 
		LEFTSHIFT , 
		RIGHTSHIFT , 
		F1 , 
		F2 ,
		F3 , 
		F4 ,
		F5 , 
		F6 , 
		F7 , 
		F8 ,
		F9 ,
		F10 , 
		F11 , 
		F12 , 
		A , 
		B , 
		C ,
		D , 
		E , 
		F , 
		G , 
		H , 
		I , 
		J , 
		K , 
		L , 
		M , 
		N , 
		O , 
		P , 
		Q , 
		R , 
		S , 
		T , 
		U , 
		V , 
		W , 
		X , 
		Y , 
		Z , 
		NUM1 , 
		NUM2 , 
		NUM3 , 
		NUM4 , 
		NUM5 , 
		NUM6 , 
		NUM7 , 
		NUM8 , 
		NUM9 , 
		NUM0 
	
	};

	enum class KeyboardAction
	{
		KEY_PRESSED, 
		KEY_RELEASED, 
		UNDEFINED_ACTION
	}; 

	class EventKeyboard: public Event
	{
		private:
			KeyboardKey key; 
			KeyboardAction action; 
		
		public:
			EventKeyboard(); 
			EventKeyboard(KeyboardKey new_key, KeyboardAction new_action); 
			KeyboardKey getKey(); 
			void setKey(KeyboardKey new_key); 
			void setKey(std::string new_key); 
			KeyboardAction getAction(); 
			void setKeyboardAction(KeyboardAction new_key_action); 
	}; 
}
