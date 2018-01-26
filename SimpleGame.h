#ifndef __SIMPLEGAME__
#include <SDL2/SDL.h>
#include <jaggame/JgGame.h>
#include <jaggame/JgGridUnit.h>
#include <jaggame/JgLoadTexture.h>
#include "SimpleEngine.h"

class SimpleGame: public JagGame::Game {
    public:
    SimpleGame(SDL_Renderer*);
    ~SimpleGame();
    int init(); // initialize. SimpleGame has initialization delayed from construction in order to allow better runtime behavior
    void render(); // render the next frame
    void handleEvent(SDL_Event*); // accept one event for inputs
    protected:
    SimpleEngine *engine = nullptr;
    SDL_Texture *textures;
}

#define __SIMPLEGAME__
#endif
