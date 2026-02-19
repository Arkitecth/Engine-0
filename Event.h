#include <string>
namespace E0
{
const std::string undefined_event = "UNDEFINED_EVENT";
	class Event 
	{
		private:
			std::string type; 

		public:
			Event(); 
			Event(std::string new_type); 
			void setType(std::string new_type); 
			std::string getType(); 
	};
}
