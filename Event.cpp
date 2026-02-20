#include "Event.h"


E0::Event::Event()
{
	type = undefined_event; 
}

E0::Event::~Event()
{

}

E0::Event::Event(std::string new_type)
{
	setType(new_type);
}



void E0::Event::setType(std::string new_type)
{
	type = new_type; 
}


std::string E0::Event::getType()
{
	return type; 
}




