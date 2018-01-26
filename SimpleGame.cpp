#include "SimpleGame.h"

SimpleGame::SimpleGame(SDL_Renderer *r): JagGame::Game(r) {}

int SimpleGame::init() {
    JagGame::region = // get the whole screen size from renderer
    JagGame::nUnits = 1; // this game has only one unit
    textures = new SDL_Texture[4];
    textures[0] = JagGame::loadTexture("res/blue-orb.png", JagGame::Unit::renderer); // not sure if Unit is directly accessible here.
    textures[1] = JagGame::loadTexture("res/red-orb.png", JagGame::Unit:renderer);
    textures[2] = 
    engine = new SimpleEngine(textures);
    units = new JagGame::Unit*[nUnits]; // instantiate the array
    units[0] = new JagGame::GridUnit(renderer, region, engine) // actually connect this to the rest of the code in this project. 
    eventFlags = new Uint32[nUnits]; // parallel array for event flags
    for(int i = 0; i < nUnits; i++) {
        eventFlags[i] = units[i]->getEventFlags();
    }
    return !(units || eventFlags || region);
}

SimpleGame::~SimpleGame() {} // JagGame::Game owns all the stuff we initialized, so it will clean up.

void SimpleGame::render() {
    units[0].render(); // just render the one unit
}

void SimpleGame::handleEvent(SDL_Event *e) {
    if(e.type == SDL_QUIT || e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESC) {
        JagGame::quit = true;
    }
}
