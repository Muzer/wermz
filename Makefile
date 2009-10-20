CXX=g++
CFLAGS=-c -Wall -O3
LDFLAGS=
SOURCES=main.cpp wermz.cpp wermz.h logger.cpp logger.h constants.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wermz

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

