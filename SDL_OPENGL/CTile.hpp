//
//  CTile.hpp
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef CTile_hpp
#define CTile_hpp

#include <stdio.h>
#include "Define.h"

enum {
    TILE_TYPE_NONE = 0,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK,
    TILE_TYPE_END
};

class CTile {
    
public:
    int TileID;
    int TypeID;
    
public:
    CTile();
};

#endif /* CTile_hpp */
