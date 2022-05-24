#ifndef CLevel_hpp
#define CLevel_hpp
#include <SFML/Audio.hpp>
#include "CPlayer.hpp"
#include "CArea.hpp"
#include "CEntity.hpp"

class CLevel {
    
public:
    sf::Music music;
    CPlayer Players[3];
    int levelNum;
    CArea theArea;

    bool OnLoad(char* levelFile, int levelNum, std::vector<CPlayer*>* PlayerList, std::vector<CEntity*>* EntityList);
    void OnStop();

};
#endif /* CLevel_hpp */
