#ifndef GAME_COMPONENT_H_INCLUDED
#define GAME_COMPONENT_H_INCLUDED

#include "transform.h"

class shader;

class game_component{

public:

    transformation* Transformation;
    game_component(){}

    virtual void input(transformation& Transform);
    virtual void update(transformation& Transform);
    virtual void render(shader* shader);

};

#endif // GAME_COMPONENT_H_INCLUDED
