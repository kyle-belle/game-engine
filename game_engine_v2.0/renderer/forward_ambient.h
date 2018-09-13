#ifndef FORWARD_AMBIENT_H_INCLUDED
#define FORWARD_AMBIENT_H_INCLUDED

#include "shader.h"
#include "shaders.h"
#include "vector4f.h"


class forward_ambient : public shader{

public:

    vector4f ambient_light;

    forward_ambient(){
        //load_shaders(forward_ambient_vertex_shader, forward_ambient_fragment_shader);
    }

    void init_shader(){
        load_shaders(forward_ambient_vertex_shader, forward_ambient_fragment_shader);
        ambient_light.set_xyzw(0,0,0,0);
    }

    void update_uniforms(transformation& transform, material& material) override {
        set_uniform_mat4f("u_mvp", transform.get_projected_transformation());
        //set_uniform_mat4f("translate", transform.get_transformation());

        //set_uniform_4f("u_colour", material.c_colour.x, material.c_colour.y, material.c_colour.z, 1.0);

        set_uniform_4f("ambient_light",ambient_light.x, ambient_light.y, ambient_light.z, ambient_light.w);
    }

    void set_ambient_light(vector4f& Ambient_light){
        ambient_light = Ambient_light;
    }

//    shader* get_shader(){
//        return &Shader;
//    }
};

#endif // FORWARD_AMBIENT_H_INCLUDED
