# makefile

GXX=g++
#if necessary -I/path/to/header SDL2/SDL.h
#and -I/path/to/header SDL2/SDL_image.h
#You might also need path/to/header SDL.h for SDL_image.h


#Banjo
#HEADPATH=-I/usr/local/Cellar/sdl2/2.0.20/include/SDL2/ -I/usr/local/Cellar/sdl2/2.0.20/include/ -I/usr/local/Cellar/sdl2_image/2.0.5/include/ -I/usr/local/Cellar/sdl2_ttf/2.0.18_1/include


#Bidule
HEADPATH=-I/opt/homebrew/Cellar/sdl2/2.0.20/include/SDL2/ -I/opt/homebrew/Cellar/sdl2/2.0.20/include/ -I/opt/homebrew/Cellar/sdl2_image/2.0.5/include/ -I/opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/include

CFLAGS=-Wall $(HEADPATH) -c
#if necessary -L/path/to/library libSDL.a

#Banjo
#LIBPATH=-L/usr/local/Cellar/sdl2/2.0.20/lib -L/usr/local/Cellar/sdl2_image/2.0.5/lib -L/usr/local/Cellar/sdl2_ttf/2.0.18_1/lib -framework Foundation -framework Cocoa

#Bidule
LIBPATH=-L/opt/homebrew/Cellar/sdl2/2.0.20/lib -L/opt/homebrew/Cellar/sdl2_image/2.0.5/lib -L/opt/homebrew/Cellar/sdl2_ttf/2.0.18_1/lib -framework Foundation -framework Cocoa

LDFLAGS=-Wall $(LIBPATH) -lSDL2 -lSDL2_image -lSDL2_ttf -o
DEL=rm -f
SOURCES=main.cpp CApp_OnCleanup.cpp CApp_OnEvent.cpp CApp_OnInit.cpp CApp_OnLoop.cpp CApp_OnRender.cpp CSurface.cpp CEvent.cpp CAnimation.cpp CEntity.cpp CArea.cpp CMap.cpp CTile.cpp CCamera.cpp CEntityCol.cpp CFPS.cpp CPlayer.cpp CApp_Text.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=CApp.h CSurface.hpp Cevent.hpp CAnimation.hpp CEntity.hpp Define.h CArea.hpp CMap.hpp CTile.hpp CCamera.hpp CFPS.hpp CPlayer.hpp
EXECUTABLE=OPENGL_game

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
