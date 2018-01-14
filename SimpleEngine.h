#ifndef __SIMPLEENGINE__
#include <SDL2/SDL.h>
#include <vector>
#include "JgTileDataEngine.h"

class SimpleEngine: public JagGame::TileDataEngine {
	public:
	SimpleEngine();
	const std::vector<SDL_Texture*> *getTextures(int,int);
	void setCurrentCell(Cell);
	void selectCell(Cell,SDL_Event*);
	void handleKeyInput(SDL_Event*);
	protected:
	int mapwx;
	int mapwy;
    std::vector<SDL_Texture*> stage;
    SDL_Texture *resources;
}

#define __SIMPLEENGINE__
#endif

