#ifndef __SIMPLEENGINE__
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "JgTileDataEngine.h"
#include "Stage.h"
#include "Mob.h"
#include "Mind.h"
#include "PlayerMind.h"
#include "OrbMind.h"

class SimpleEngine: public JagGame::TileDataEngine {
	public:
	SimpleEngine();
    ~SimpleEngine();
	const std::vector<SDL_Texture*> *getTextures(int,int);
	void setCurrentCell(Cell);
	void selectCell(Cell,SDL_Event*);
	void handleKeyInput(SDL_Event*);
	protected:
	int mapwx;
	int mapwy;
    SDL_Texture *resources;
    Mob player;
    Mob orb;
    Stage stage;

    SDL_Texture* textureInit(); // initialize the textures for this game
    Cell getUserAction(); // get the user's movement this turn
}

#define __SIMPLEENGINE__
#endif

