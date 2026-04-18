#include "Texture.h"
#include "TowerState.h"
#include "Vector.h"

class IdleTowerState: TowerState
{
	private:
		E0::Vector position{};
		E0::Texture roofTexture{};	
		E0::Texture bodyTexture{};
		E0::Texture headTexture{};
	public:
		IdleTowerState(E0::Vector position, E0::Texture roofTexture, E0::Texture bodyTexture, E0::Texture headTexture); 
		virtual void draw(); 
};
