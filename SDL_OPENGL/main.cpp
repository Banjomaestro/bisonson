#include "CApp.h"

CApp::CApp(char* path) {
    char * temp = nullptr;
    temp = strrchr(path, '/');
    if (!temp) {
        temp = strrchr(path, '\\');
    }
    *++temp = '\0';
    Abs_path = path;
    Surf_Display = NULL;
    Running = true;
    //TTF_Init();
}

int CApp::OnExecute()
{
    if (OnInit()==false)
        return -1;
  
    /* Boucle principale */
    while(Running)
    {
        /* Boucle traitant les evenements */
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            OnEvent(&e);
        }
        
        /* Recuperation du temps au debut de la boucle */
        startTime = SDL_GetTicks();
        
        OnLoop();
        OnRender();
        
    }

    OnCleanup();
    
    return EXIT_SUCCESS;
}

int main(int argc, char * argv[]) {
    CApp theApp((char *) argv[0]);
    return theApp.OnExecute();
}
