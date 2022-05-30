//
//  Define.h
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef Define_h
#define Define_h

#define MAP_WIDTH 30
#define MAP_HEIGHT 10

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

#define GL_VIEW_SIZE 1000

#define TILE_SIZE 64

#include <stdint.h>

/* Dimensions initiales et titre de la fenetre */
static const char WINDOW_TITLE[] = "SDL_GL";

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const uint32_t FRAMERATE_MILLISECONDS = 1000 / 60;

#endif /* Define_h */

