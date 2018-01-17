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
    oubStack = std::vector<SDL_Texture*>(1); // create the vector for the oub stack
    oubStack.push_back(oub); // put the oub texture in
}

Stage::~Stage() {
    delete rosterHead; // delete all the Entities in the roster. Entity's destructor is recursive
    for(int k = 0; k < xwidth; k++) {
        delete[] field[k]; // delete every Tile
    }
    delete[] field; // delete the field structure
}

void Stage::add(MobInstance &mob, int i, int j) {
    Entity *temp = new Entity(mob); // Create the entity
    temp->next = rosterHead;
    rosterHead = temp; // Spool out the list.
    field[i][j].add(rosterHead); // put the new Entity in its Tile.
}

void Stage::add(MobInstance &&mob, int i, int j) { // move semantics for the assignment. Will probably we called more often.
    Entity *temp = new Entity(mob); // Create the entity
    temp->rosterNext = rosterHead;
    rosterHead = temp; // Spool out the list.
    field[i][j].add(rosterHead); // put the new Entity in its Tile.
}

void Stage::advance() { // advance the simulation one turn
    Entity *temp = rosterNext;
    while(temp) { 
        temp->act();
        temp = temp->rosterNext;
    } // iterate through roster and perform actions
}

const std::vector<SDL_Texture*> *getTextures(int i, int j) { // get the stack of textures to paint on a particular tile
    if(i + 1 < xwidth && j + 1 < ywidth) {
        texStack = field[i][j].getTextures(); // get whatever needs to be rendered on the tile right now
        texStack->push_back(ground); // put the ground texture on the end. JagGame should be changed to read the texture stack backwards.
    } else { 
        return &oubStack; // if the request is out-of-bounds, send them the out-of-bounds texture
    }
}
