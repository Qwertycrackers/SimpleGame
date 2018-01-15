#include "SimpleEngine.h"
/*  Instantiate the textures 
    Create the stage and mob prototypes
    Configure the initial setup */
SimpleEngine::SimpleEngine(SDL_Texture *r): JagGame::TileDataEngine(Cell(0,0,0),10) {
    resources = r; // simply assume the resources are correct and hardcode those too
    player = Mob(PlayerMind(&getUserAction), resources);
    orb = Mob(OrbMind(), resources + 1);
    stage = Stage(15, 15, resources + 2, resources + 3); // hardcode things because it's a demo

    stage.add(player.instance(), 0, 0); // put things on the stage
    stage.add(orb.instance(), 5, 5);
    stage.add(orb.instance(), 0, 2);
    stage.add(orb.instance(), 7, 13);
}

void SimpleEngine::setCurrentCell(Cell c) {} // Don't need for this game
void SimpleEngine::selectCell(Cell c, SDL_Event* e) {} // Also don't need

void SimpleEngine::handleKeyInput(SDL_Event* e) { // Extract the correct movement from an input
    switch(e->key.keysym) {
        case SDLK_LEFT:
            action = Cell(-1,0,0);
            break;
        case SDLK_RIGHT:
            action = Cell(1,0,0);
            break;
        case SDLK_UP:
            action = Cell(0,1,0);
            break;
        case SDLK_DOWN:
            action = Cell(0,-1,0);
            break;
        case default:
            action = Cell(0,0,0);
    }
    stage.advance();
}
}

Cell &&SimpleEngine::getUserAction() { // get the user's movement on the current turn
    return std::move(action);
}
