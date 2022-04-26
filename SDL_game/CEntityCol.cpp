//
//  CEntityCol.cpp
//  SDL_game
//
//  Created by MissBidule on 02/01/2022.
//

#include <stdio.h>
#include "CEntity.hpp"

std::vector<CEntityCol> CEntityCol::EntityColList;

CEntityCol::CEntityCol() {
    EntityA = NULL;
    EntityB = NULL;
}
