//
//  Define.h
//  SDL_game
//
//  Created by MissBidule on 01/01/2022.
//

#ifndef Define_h
#define Define_h

#define MAP_WIDTH 40
#define MAP_HEIGHT 40

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define GL_VIEW_SIZE 640.

#define TILE_SIZE 16

#include <stdint.h>

/* Dimensions initiales et titre de la fenetre */
static const char WINDOW_TITLE[] = "SDL_GL";

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const uint32_t FRAMERATE_MILLISECONDS = 1000 / 60;

#endif /* Define_h */

