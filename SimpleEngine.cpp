#include "SimpleEngine.h"
/*  Instantiate the textures 
    Create the stage and mob prototypes
    Configure the initial setup */
SimpleEngine::SimpleEngine(): JagGame::TileDataEngine(Cell(0,0,0),10) {
    mapwx = 15;
    mapwy = 15; // hardcode these because it's a demo
    resources = textureInit(); // simply assume the resources are correct and hardcode those too
    player = Mob(PlayerMind(&getUserAction), resources);
    orb = Mob(OrbMind(), resources + 1);
    stage = Stage(mapwx, mapwy, resources + 2, resources + 3);

    stage.add(player.instance(), 0, 0); // put things on the stage
    stage.add(orb.instance(), 5, 5);
    stage.add(orb.instance(), 0, 2);
    stage.add(orb.instance(), 7, 13);
}

void SimpleEngine::setCurrentCell(Cell c) {} // Don't need for this game
void SimpleEngine::selectCell(Cell c, SDL_Event* e) {} // Also don't need

void SimpleEngine::handleKeyInput(SDL_Event* e) { // Extract the correct movement from an input
    // NOT IMPLEMENTED
}

SDL_Texture *SimpleGame::textureInit() { // Load up our textures.

}

Cell SimpleEngine::getUserAction() { // get the user's movement on the current turn

}
