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
            char inputBuffer[100]{};
            int width{};
            int height{};
            bool isRunning{};
            bool spawnPointMode{};
            bool towerPointMode{};
            std::vector<E0::Vector> spawnPoints{}; 
            ImGuiIO* io; 

    public:
        Editor() = delete;
        ~Editor(); 
        Editor(int width, int height);
        void draw(); 
        void drawLayout();
        void loadLevel(); 
        void addSpawnPoint(); 
        //void SDLCALL createLevel(void* userdata, const char* const* fileList, int filter); 
        void run(); 
    static void SDLCALL createLevel(void* userdata, const char* const* fileList, int filter); 
    static void SDLCALL loadLevel(void* userdata, const char* const* fileList, int filter); 

    void exportFile(E0::Level& level);
}; 
