#include "Entity.cpp"

Entity::Entity(MobInstance &m) {
    mob = m; // copy
}

Entity::Entity(MobInstance &&m) {
    mob = m; // move
}

Entity::~Entity() {
    delete rosterNext; // Entity only owns the roster pointer, not the tile pointers.
}

void Entity::appendToTile(Entity *that) { 
    tileNext = that->tileNext;
    tileLast = that;
    tileLast->tileNext = this;
    tileNext->tileLast = this;
}

void Entity::appendToRoster(Entity *that) { // honestly might never use this, but it's here for consistency
    that->rosterNext = rosterNext;
    rosterLast = that;
    rosterLast->rosterNext = this;
    rosterNext->rosterLast = this;
}

void Entity::removeFromTile() {
    tileNext->tileLast = tileLast;
    tileLast->tileNext = tileNext;
    tileNext = nullptr;
    tileLast = nullptr;
}

void Entity::removeFromRoster() {
    rosterNext->rosterLast = rosterLast; 
    rosterLast->rosterNext = rosterNext;
    rosterLast = nullptr;
    rosterNext = nullptr;
}

const MobInstance &Entity::getMob() {
    return mob;
}
