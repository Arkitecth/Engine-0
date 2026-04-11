#include "SimulatedEntity.h"
#include "Level.h"
#include "SDL3/SDL_dialog.h"
#include "imgui.h"
const SDL_DialogFileFilter filters[] = 
{
		{"PNG Images ", "png"},  
		{"JPEG Images ", "jpg;jpeg"},  
}; 

const SDL_DialogFileFilter levelFilter[] = {
    {"Engine 0 Level Files", "lvl"}
};

class Editor 
{
    private:
            E0::Level currentLevel{};
            SimulatedEntity entity{};
            char inputBuffer[100]{};
            int width{};
            int height{};
            bool isRunning{};
            bool wayPointMode{};
            bool towerPointMode{};
            bool simulationMode{};
            bool editMode{};
            std::vector<E0::Vector> wayPoints{}; 
            ImGuiIO* io; 

    public:
        Editor() = delete;
        ~Editor(); 
        Editor(int width, int height);
        void render(); 
        void edit(); 
        void pushLayout();
        void fileManagement();
        void addTowerPoint();
        void loadLevel(); 
        void addWayPoint(); 
        void simulateWaypoint(); 
        void clear(); 
        void save();
        void run(); 
    static void SDLCALL createLevel(void* userdata, const char* const* fileList, int filter); 
    static void SDLCALL loadLevel(void* userdata, const char* const* fileList, int filter); 

    void exportFile(E0::Level& level);
}; 
