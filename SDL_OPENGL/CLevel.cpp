#include "CLevel.hpp"

bool CLevel::OnLoad(char* levelFile, int levelNum, std::vector<CPlayer*>* PlayerList, std::vector<CEntity*>* EntityList) {

    PlayerList->clear();
    EntityList->clear();

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

    fscanf(FileHandle, "%s %s ", mapFile, musicFile);

     if (!music.openFromFile(musicFile))
        return -1;
    
   music.play();
   music.setLoop(true);

    c = ' ';
    int PosX;
    int PosY;
    int playerNum;

    while((c=fgetc(FileHandle))=='/'){
       fscanf(FileHandle, "%d %d %d", &playerNum, &PosX, &PosY);
       CPlayer* temp = new CPlayer();
       temp->OnLoad((char *)"players/list.txt",playerNum, PosX, PosY, false);
       PlayerList->push_back(temp);
       EntityList->push_back(temp);
       printf("done");
    }

    PlayerList->at(0)->selected = true;

    
    if (CArea::AreaControl.OnLoad(mapFile, "") == false) {
        return false;
    }
    
    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetPos(WINDOW_WIDTH/2-TILE_SIZE/2, -WINDOW_HEIGHT/2+TILE_SIZE/2);
    CCamera::CameraControl.SetTarget(&PlayerList->at(0)->X, &PlayerList->at(0)->Y);   

    return true;

}

void CLevel :: OnStop(){

    music.stop();

}