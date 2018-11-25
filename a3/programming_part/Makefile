# Originally written by Joey Adams
HEADERS = $(wildcard *.h)
SOURCE_P1 = $(wildcard p1*.cpp)
SOURCE_P2 = $(wildcard p2*.cpp)
OBJECTS_P1 = $(patsubst p1%.cpp, p1%.o, $(wildcard p1*.cpp))
OBJECTS_P2 = $(patsubst p2%.cpp, p2%.o, $(wildcard p2*.cpp))

.PHONY: default all clean
.PRECIOUS: p1_attack p2_attack $(OBJECTS_P1) $(OBJECTS_P2)

default: all

%.o: %.cpp $(HEADERS)
	g++ -std=c++11 -c $< -o $@

all: $(OBJECTS_P1) $(OBJECTS_P2)
	g++ $(OBJECTS_P1) -o p1_attack
	g++ $(OBJECTS_P2) -o p2_attack

clean:
	-rm -f *.o
	-rm -f p1_attack
	-rm -f p2_attack

