#include "SimpleGame.h"

SimpleGame::SimpleGame(SDL_Renderer *r): JagGame::Game(r) {}

int SimpleGame::init() {
    JagGame::region = // get the whole screen size from renderer
    JagGame::nUnits = 1; // this game has only one unit
    units = new Unit*[nUnits]; // instantiate the array
    units[0] = new SimpleTileFrame();
    eventFlags = new Uint32[nUnits]; // parallel array for event flags
    for(int i = 0; i < nUnits; i++) {
        eventFlags[i] = units[i]->getEventFlags();
    }
    return units || eventFlags || region;
}
