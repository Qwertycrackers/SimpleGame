#include "Stage.h"

Stage::Stage(int i, int j, SDL_Texture *g, SDL_Texture *o) {
    xwidth = i;
    ywidth = j;
    ground = g;
    oub = o; // Bring in variables

    field = new Tile*[xwidth]; // make the array xwidth long on the first dimension
    for(int k = 0; k < xwidth; k++) {
        field[k] = new Tile[ywidth]; // make each array in the second dimension ywidth long. 
    }
}

Stage::~Stage() {
    delete rosterHead; // delete all the Entities in the roster. Entity's destructor is recursive
    for(int k = 0; k < xwidth; k++) {
        delete[] field[k]; // delete every Tile
    }
    delete[] field; // delete the field structure
}

void Stage::add(MobInstance &mob, int i, int j) {
    Entity *temp = new Entity(mob); // create the entity
    temp->next = rosterHead;
    rosterHead = temp; // spool out the list
    

