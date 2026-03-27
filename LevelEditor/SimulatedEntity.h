#include "Entity.h"
#include "Vector.h"
#include <vector>

class SimulatedEntity 
{
    public:
            SimulatedEntity() = default;
            SimulatedEntity(E0::Vector position);
            E0::Vector position{};
            E0::Velocity velocity{};
            std::vector<E0::Vector> waypoints{};
            void draw(); 
            void moveTowardsWaypoint();
}; 
