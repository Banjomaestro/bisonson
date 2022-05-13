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

#define TILE_SIZE 16

#define WWIDTH 640
#define WHEIGHT 480

/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 600;
static const char WINDOW_TITLE[] = "SDL_GL";

/* Espace fenetre virtuelle */
static const float GL_VIEW_SIZE = 150.;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

#endif /* Define_h */

