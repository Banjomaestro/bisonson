#include "CLevel.hpp"

bool CLevel::OnLoad(char* levelFile, int levelNum, std::vector<CPlayer*>* PlayerList, std::vector<CEntity*>* EntityList) {

    FILE* FileHandle = fopen(levelFile, "r");
    
    if (FileHandle == NULL) {
        return false;
    }
    
    char c;
    int lines = 0;

    while (lines < levelNum){
        
        c = fgetc(FileHandle);

        if(c=='\n')
         lines++;
    } 

    char mapFile[255];
    char musicFile[255];
    int MaxFrames = 0;

    fscanf(FileHandle, "%s %s ", mapFile, musicFile);

     if (!music.openFromFile(musicFile))
        return -1;
    
    music.play();
    music.setLoop(true);

    CPlayer* tempPlayer = new CPlayer();

    if ((tempPlayer->OnLoad((char *)"players/list.txt",1)) == false) {
        return false;
    }

    PlayerList->push_back(tempPlayer);
    
    tempPlayer = new CPlayer();
    if ((tempPlayer->OnLoad((char *)"players/list.txt",0)) == false) {
        return false;
    }

    PlayerList->push_back(tempPlayer);
    
    char file_name[] = "map/1.area";
    if (CArea::AreaControl.OnLoad(file_name, "") == false) {
        return false;
    }
    
    
    PlayerList->at(0)->X = 100;
    PlayerList->at(0)->Y = -150;
    PlayerList->at(0)->selected = true;
    PlayerList->at(1)->X = 300;
    PlayerList->at(1)->Y = -150;

    EntityList->push_back(PlayerList->at(0));
    EntityList->push_back(PlayerList->at(1));
   
    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetPos(WINDOW_WIDTH/2-TILE_SIZE/2, -WINDOW_HEIGHT/2+TILE_SIZE/2);

    CCamera::CameraControl.SetTarget(&PlayerList->at(0)->X, &PlayerList->at(0)->Y);   
    
    return true;

}

void CLevel :: OnStop(){

}