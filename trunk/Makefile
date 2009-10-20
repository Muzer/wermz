CXX=g++
CFLAGS=-c -Wall -O3
LDFLAGS=
SOURCES=main.cpp wermz.cpp wermz.h logger.cpp logger.h constants.h win_funcs.h win_funcs.cpp lin_funcs.h lin_funcs.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wermz

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

