#ifndef CLevel_hpp
#define CLevel_hpp
#include <SFML/Audio.hpp>
#include "CPlayer.hpp"

class CLevel {
    
public:
    CLevel Next;
    CLevel Previous;
    sf::Music music;
    CPlayer Players[3];




};
#endif /* CLevel_hpp */
