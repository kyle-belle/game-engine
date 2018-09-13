#include "game_object.h"


void game_object::add_child(game_object& child){
    children.push_back(child);
}

void game_object::add_component(game_component* component){
    components.push_back(component);
}

void game_object::input(){

    for(game_component* component : components)
        component->input(Transformation);

    for(game_object& child : children)
        child.input();

}

void game_object::update(){

    for(game_component* component : components)
        component->update(Transformation);

    for(game_object& child : children)
        child.update();

}

void game_object::render(shader& shader){

    for(game_component* component : components){
        ///game_component* a = &component;
        component->render(&shader);
    }

    for(game_object& child : children)
        child.render(shader);

}
