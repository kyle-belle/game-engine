#ifndef TEST_GAME_H_INCLUDED
#define TEST_GAME_H_INCLUDED

#include "game.h"
#include "mesh_renderer.h"

class test_game : public game{

public:

    mesh_renderer Mesh_renderer;

test_game(display& display);

test_game(){}

void init_game(display& display) override ;

~test_game() override ;

void inputs(display& display) override ;

int get_height(display& display) override ;
int get_width(display& display) override ;

void update(transform& Transform,camera& camera) override ;

///void render() override ;
//void render(transform& transform);
void render(index_buffer& ib,shader& shader) override ;
void delete_textures() override ;

game_object* getroot() override ;

};


#endif // TEST_GAME_H_INCLUDED
