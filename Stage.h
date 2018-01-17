#ifndef __STAGE__           // NOTE: This class, in retrospect, is really not a proper "C++" implementation of this idea
#include <vector>           //       It has far too many C constructs and fails to make good use of the power C++ tools bring.
#include <SDL2/SDL.h>       //       In the long run, these facts would make the class hard to maintain, but since this is merely a demo I'll just remember these lessons.
#include <Mob.h>
#include <Tile.h>
#include <Entity.h>

class Stage {
    public:
    Stage(int,int,SDL_Texture*,SDL_Texture*);
    ~Stage(); // explicit destructor because we allocate memory
    void add(MobInstance&,int,int); // add a mob instance to the field
    void add(MobInstance&&,int,int); // add a mob instance to the field with move semantics
    void advance(); // advance the simulation one step
    const std::vector<SDL_Texture*> *getTextures(int,int); // get the stack of textures to render for a particular tile
    protected:
    int xwidth; // width of the stage in the x
    int ywidth; // width of the stage in the y
    SDL_Texture *ground; // the ground texture
    SDL_Texture *oub; // out-of-bounds texture. Stage does not own either of these
    Tile **field; // the tiles which make up the stage. One size.
    Entity *rosterHead; // head of the linked list of all entities on the stage
    
} // Stage 

#define __STAGE__
#endif
