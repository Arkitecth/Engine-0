#include "Event.h"
#include "Entity.h"
namespace E0 
{
	const std::string EVENT_COLISSION = "E0::event_colission"; 

	class EventColission: public Event
	{
		private:
			Vector position{}; 
			Entity* entity_01; 
			Entity* entity_02; 

		public:
			void setEntity01(Entity* new_entity); 
			void setEntity02(Entity* new_entity); 
			Entity* getEntity01(); 
			Entity* getEntity02(); 
			Vector getPosition(); 
			void setPosition(Vector position); 
			EventColission(); 
			~EventColission(); 
	}; 

}

