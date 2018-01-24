#ifndef __SIMPLEGAME__
#include <SDL2/SDL.h>
#include <jaggame/JgGame.h>
#include "SimpleEngine.h"

class SimpleGame: public JagGame::Game {
    public:
    SimpleGame(SDL_Renderer*);
    ~SimpleGame();
    int init(); // initialize
    void render(); // render the next frame
    void handleEvent(SDL_Event*); // accept one event for inputs
}

#define __SIMPLEGAME__
#endif
