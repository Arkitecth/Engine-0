#pragma once
#include "Texture.h"
#include "Vector.h"
#include "Velocity.h"
#include <string>
#include "Event.h"
#include <string_view>
namespace E0
{
	static int current_entity_id = 0; 
	const std::string_view UNDEFINED_TYPE = "undefined_entity_type";
	class Entity
	{
		private:
			int entityID; 
			Vector position{}; 
			std::string entity_type{}; 
			Velocity velocity{};
			float width{}; 
			float height{};

		public:
			Entity(); 
			virtual ~Entity(); 
			virtual void eventHandler(const Event* e);  
			virtual void draw(); 
			virtual Entity* duplicate(); 

			Vector getPosition() const; 
			void setPosition(Vector new_position); 


			Velocity getVelocity() const; 
			void setVelocity(Velocity new_velocity); 

			float getWidth() const; 
			float getHeight() const;


			void setWidth(float new_width); 
			void setHeight(float new_height); 

			std::string getEntityType() const; 
			void setEntityType(std::string new_entity_type); 

			Vector predictPosition(); 

			int getEntityID() const; 

			bool operator==(const Entity& rhs); 
	
	}; 
}
