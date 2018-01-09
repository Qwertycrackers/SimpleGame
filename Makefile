
all: *.cpp *.h
	g++ -o simplegame -I../jaggame/include -L../jaggame/linux -lSDL2 -lSDL_image -ljaggame $(wildcard *.cpp)
