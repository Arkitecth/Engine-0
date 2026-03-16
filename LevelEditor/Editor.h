#include "Level.h"
#include "imgui.h"

static const SDL_DialogFileFilter filters[] = 
{
		{"PNG Images ", "png"},  
		{"JPEG Images ", "jpg;jpeg"},  
}; 

class Editor 
{
    private:
            E0::Level currentLevel{};
            int width{};
            int height{};
            bool isRunning{};
            ImGuiIO* io; 

    public:
        Editor() = delete;
        ~Editor(); 
        Editor(int width, int height);
        void draw(); 
        void drawLayout();
        void loadLevel(); 
        //void SDLCALL createLevel(void* userdata, const char* const* fileList, int filter); 
        void run(); 
    static void SDLCALL createLevel(void* userdata, const char* const* fileList, int filter); 
}; 
