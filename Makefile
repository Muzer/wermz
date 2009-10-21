CXX=g++
CFLAGS=-c -Wall -O3
LDFLAGS=
ENDFLAGS=`sdl-config --cflags --libs` -lSDL_image -lGL -lSDL_svg
SOURCES=wermz.cpp dictionary.cpp logger.cpp win_funcs.cpp lin_funcs.cpp sprite.cpp texture.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wermz

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@ $(ENDFLAGS)

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@ $(ENDFLAGS)

clean:
	rm -fv $(OBJECTS) $(EXECUTABLE)
