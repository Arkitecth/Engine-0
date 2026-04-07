#include "Texture.h"
#include "Vector.h"
#pragma once
namespace E0
{
	 class Cursor
	{
		private:
			E0::Vector position{};
			E0::Texture texture;
			bool cursorVisible{};

		public:
			Cursor(); 
			void toggleCursor(bool cursorVisible=false); 
			void draw(); 
			void setCursorTexture(E0::Texture new_texture); 
			void setVectorPosition(E0::Vector position); 
			E0::Vector getCursorPosition(); 
			bool getCursorVisibility(); 
			E0::Texture getCursorTexture(); 
			

	}; 
}
