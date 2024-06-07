CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lSDL2 -lGLEW -lGL

all: main

main: main.cpp
    $(CXX) $(CXXFLAGS) -o main main.cpp $(LDFLAGS)

clean:
    rm -f main
