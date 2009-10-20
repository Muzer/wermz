CXX=g++
CFLAGS=-c -Wall -O3
LDFLAGS=
SOURCES=main.cpp wermz.cpp logger.cpp win_funcs.cpp lin_funcs.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wermz

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -fv $(OBJECTS) $(EXECUTABLE)
