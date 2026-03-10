#pragma once
#include "Event.h"
namespace E0
{
	const std::string EVENT_STEP = "E0::event_step";
	class EventStep: public Event
	{
		private:
			int num_of_ticks{};

		public:
			EventStep(); 
			~EventStep(); 
			int getNumOfTicks() const;
			void increment(); 
			void setNumOfTicks(int new_num_of_ticks); 
	};

}
