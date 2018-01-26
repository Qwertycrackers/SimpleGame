
all: *.cpp *.h
	g++ -o simplegame -lSDL2 -lSDL_image -ljaggame $(wildcard *.cpp)
