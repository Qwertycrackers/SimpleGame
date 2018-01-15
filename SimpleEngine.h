#ifndef __SIMPLEENGINE__
#include <vector>
#include <memory>
#include <utility>
#include <SDL2/SDL.h>
#include "JgTileDataEngine.h"
#include "Stage.h"
#include "Mob.h"
#include "Mind.h"
#include "PlayerMind.h"
#include "OrbMind.h"

class SimpleEngine: public JagGame::TileDataEngine {
	public:
	SimpleEngine(SDL_Texture*);
    ~SimpleEngine();
	const std::vector<SDL_Texture*> *getTextures(int,int);
	void setCurrentCell(Cell);
	void selectCell(Cell,SDL_Event*);
	void handleKeyInput(SDL_Event*);
	protected:
    SDL_Texture *resources;
    Mob player;
    Mob orb;
    Stage stage;
    Cell action;

    Cell &&getUserAction(); // get the user's movement this turn
}

#define __SIMPLEENGINE__
#endif

