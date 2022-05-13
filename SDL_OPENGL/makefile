# makefile

GXX=g++
#if necessary -I/path/to/header SDL/SDL.h
#and -I/path/to/header SDL/SDL_image.h
#You might also need path/to/header SDL.h for SDL_image.h
HEADPATH=-I/opt/homebrew/Cellar/sdl2/2.0.20/include -I/opt/homebrew/Cellar/sdl2/2.0.20/include/SDL2 -I/opt/homebrew/Cellar/sdl2_image/2.0.5/include

CFLAGS=-Wall $(HEADPATH) -c
#if necessary -L/path/to/library libSDL.a
LIBPATH=-L/opt/homebrew/Cellar/sdl2/2.0.20/lib -L/opt/homebrew/Cellar/sdl2_image/2.0.5/lib -framework GLUT -framework OpenGL

LDFLAGS=-Wall $(LIBPATH) -lSDL2 -lm -lSDL2_image -o
DEL=rm -f

SOURCES=main.cpp fakesdlimage.cpp lodepng.cpp CApp_OnInit.cpp CApp_OnEvent.cpp CEvent.cpp CApp_OnRender.cpp CApp_OnCleanup.cpp CApp_OnLoop.cpp CSurface.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=fakesdlimage.hpp lodepng.hpp CApp.h CEvent.hpp Define.h CSurface.hpp

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
