#include "Entity.cpp"

Entity::Entity(MobInstance &m) {
    mob = m; // copy
}

Entity::Entity(MobInstance &&m) {
    mob = m; // move
}

Entity::~Entity() {
    delete rosterNext;
}

void Entity::appendToTile(Entity *that) { 
    tileNext = that->tileNext;
    tileLast = that;
    tileLast->tileNext = this;
    tileNext->tileLast = this;
}

void Entity::appendToRoster(Entity *that) { // honestly might never use this, but it's here for consistency
    rosterNext = that->rosterNext;
    that->rosterNext = this;
}

void Entity::removeFromTile() {
    
