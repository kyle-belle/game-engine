#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include <vector>
#include "game_component.h"
#include "transform.h"

class game_object{

public:

    std::vector<game_object> children;
    std::vector<game_component*> components;
    transformation Transformation;

    game_object(){}

    void set_transformation(transformation& transform){
        Transformation = transform;
    }

    void add_child(game_object& child);
    void add_component(game_component* component);
    virtual void input();
    virtual void update();
    virtual void render(shader& shader);

};

#endif // GAME_OBJECT_H_INCLUDED
