#include "EventStep.h"

E0::EventStep::EventStep()
{
	E0::Event::setType(EVENT_STEP); 
}

E0::EventStep::~EventStep()
{

}

int E0::EventStep::getNumOfTicks() const
{
	return num_of_ticks;
}

void E0::EventStep::setNumOfTicks(int new_num_of_ticks)
{
	num_of_ticks = new_num_of_ticks;
}

void E0::EventStep::increment()
{
	num_of_ticks += 1;
}
