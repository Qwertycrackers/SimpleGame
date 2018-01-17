#ifndef __STAGE__
#include <vector>
#include <SDL2/SDL.h>
#include <Mob.h>
#include <Tile.h>
#include <Entity.h>

class Stage {
    public:
    Stage(int,int,SDL_Texture*,SDL_Texture*);
    void add(MobInstance&,int,int); // add a mob instance to the field
    void add(MobInstance&&,int,int); // add a mob instance to the field with move semantics
    void advance(); // advance the simulation one step
    const std::vector<SDL_Texture*> *getTextures(int,int); // get the stack of textures to render for a particular tile
    protected:
    SDL_Texture *ground; // the ground texture
    SDL_Texture *oub; // out-of-bounds texture. Stage does not own either of these
    Tile **field; // the tiles which make up the stage. One size.
    Entity *entityListHead; // head of the linked list of entities
    
} // Stage 

#define __STAGE__
#endif
