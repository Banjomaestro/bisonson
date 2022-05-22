# makefile

GXX=g++
#if necessary -I/path/to/header SDL/SDL.h
#and -I/path/to/header SDL/SDL_image.h
#You might also need path/to/header SDL.h for SDL_image.h


#bidule
#HEADPATH=-I/opt/homebrew/Cellar/sdl2/2.0.20/include -I/opt/homebrew/Cellar/sdl2/2.0.20/include/SDL2 -I/opt/homebrew/Cellar/sdl2_image/2.0.5/include	-I/opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/include	-I/opt/homebrew/Cellar/freetype/2.12.0/include/freetype2

#banjo
HEADPATH=-I/usr/local/Cellar/sdl2/2.0.20/include/SDL2/ -I/usr/local/Cellar/sdl2/2.0.20/include/ -I/usr/local/Cellar/sdl2_image/2.0.5/include/ -I/usr/local/Cellar/sdl2_ttf/2.0.18_1/include -I/usr/local/Cellar/freetype/2.12.0/include/freetype2 -I/usr/local/Cellar/sfml/2.5.1_1/include


CFLAGS=-Wall $(HEADPATH) -c
#if necessary -L/path/to/library libSDL.a

#bidule
#LIBPATH=-L/opt/homebrew/Cellar/sdl2/2.0.20/lib -L/opt/homebrew/Cellar/sdl2_image/2.0.5/lib -L/opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/lib -L/opt/homebrew/Cellar/freetype/2.12.0/lib -framework GLUT -framework OpenGL -lfreetype

#banjo
LIBPATH=-L/usr/local/Cellar/sdl2/2.0.20/lib -L/usr/local/Cellar/sdl2_image/2.0.5/lib -L/usr/local/Cellar/sdl2_ttf/2.0.18_1/lib -L/usr/local/Cellar/freetype/2.12.0/lib -L/usr/local/Cellar/sfml/2.5.1_1/lib  -framework GLUT -framework OpenGL -lfreetype -lsfml-audio -lsfml-system

LDFLAGS=-Wall $(LIBPATH) -lSDL2 -lm -lSDL2_image -lSDL2_ttf -o
DEL=rm -f

SOURCES=main.cpp CApp_OnInit.cpp CApp_OnEvent.cpp CEvent.cpp CApp_OnRender.cpp CApp_OnCleanup.cpp CApp_OnLoop.cpp CSurface.cpp TextRenderer.cpp CAnimation.cpp CEntity.cpp CArea.cpp CMap.cpp CTile.cpp CCamera.cpp CEntityCol.cpp CFPS.cpp CPlayer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=CApp.h CEvent.hpp Define.h CSurface.hpp TextRenderer.hpp CAnimation.hpp CEntity.hpp Define.h CArea.hpp CMap.hpp CTile.hpp CCamera.hpp CFPS.hpp CPlayer.hpp

EXECUTABLE=SDL_GL

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE):	$(OBJECTS)
	$(GXX) $(LDFLAGS) $@ $^

main.o: main.cpp $(HEADERS)
	$(GXX) $(CFLAGS) $<

%.o: %.cpp $(HEADERS)
	$(GXX) $(CFLAGS) $<

clean:
	$(DEL) *.o $(EXECUTABLE)
