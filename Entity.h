#ifndef __ENTITY__
#include "Mob.h"

class Entity { // Linked list manager for Stage. Hold a MobInstance for logic, and four pointers for parts of the list
    public: // upon consideration, these lists may not need to be doubly-linked after all. I'll change it later if so.
    Entity(MobInstance&); // lvalue constructor
    Entity(MobInstance&&); // rvalue constructor
    ~Entity() // explicit destructor to destroy linked list
    inline void appendToTile(const Entity&); // append this entity to another, add to the Tile list
    inline void appendToRoster(const Entity&); // append this entity to another, add to roster list
    inline void removeFromTile(); // remove this entity from its tile list, shrinking it
    inline void removeFromRoster(); // remove this entity from its roster list, shrinking it
    Entity *rosterNext; // next element in the roster list
    Entity *rosterLast; // last element in the roster list
    Entity *tileNext; // next element in the tile list
    Entity *tileLast; // last element in the tile list
}

#define __ENTITY__
#endif
