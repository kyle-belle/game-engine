#include "rendering_engine/rendering_engine.h"
#include "game_object.h"
#include "forward_ambient.h"
#include "forward_directional.h"
#include "game.h"


void rendering_engine::render(game_object* object){
    clear_screen();

    object->render(ambient_shader);

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glDepthMask(false);
    glDepthFunc(GL_EQUAL);

    object->render(directional_light_shader);

    object->render(point_light_shader);

    object->render(spot_light_shader);

    glDepthFunc(GL_LESS);
    glDepthMask(true);
    glDisable(GL_BLEND);
}


void rendering_engine::clear_screen(){
    //TODO: STENCIL BUFFER
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void rendering_engine::init_graphics(){


    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
//
    //glEnable(GL_DEPTH_CLAMP);
//
    //glEnable(GL_FRAMEBUFFER_SRGB);

    ///ambient_light.set_xyzw(0.2f,0.2f,0.2f,1);

    ambient_shader.init_shader();
    directional_light_shader.init_shader();
    point_light_shader.init_shader();
    spot_light_shader.init_shader();
    //ambient_shader.set_ambient_light(ambient_light,1.0f);

}

void rendering_engine::link_transformation(transformation* TRANSFORMATION){
        Transformation = TRANSFORMATION;
}
