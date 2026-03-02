#define IM E0::InputManager::getInstance()
namespace E0
{
	class InputManager 
	{
		private:
			InputManager(); 
		
		public:	
			~InputManager(); 
			void startUp(); 
			void shutDown(); 
			static InputManager& getInstance();
			void pollInput(); 
			
	};  
}
