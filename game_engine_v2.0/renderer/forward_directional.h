#ifndef FORWARD_DIRECTIONAL_H_INCLUDED
#define FORWARD_DIRECTIONAL_H_INCLUDED

#include "shader.h"
#include "vertex_buffer.h"
#include "material.h"

class forward_directional : public shader{

public:

    directional_light d_light;

    forward_directional(){
        ///load_shaders(forward_directional_vertex_shader, forward_directional_fragment_shader);
//        d_light.base.colour = glm::vec4(0.5f,0.5f,0.5f,1.0f);
//        d_light.base.intensity = 0.8f;
//        d_light.direction = glm::vec4(1.0f,1.0f,-1.0f,1.0f);
    }

    void init_shader(){
        load_shaders(forward_directional_vertex_shader, forward_directional_fragment_shader);
        d_light.base.colour = vector4f(1.0f,1.0f,1.0f,1.0f);
        d_light.base.intensity = 0.4f;
        d_light.direction = vector4f(1.0f,1.0f,-1.0f,1.0f);

    }

    void update_uniforms(transformation& transform, material& material) override {

        set_uniform_mat4f("u_mvp", transform.get_projected_transformation());
        set_uniform_mat4f("translate", transform.get_transformation());
        set_uniform_4f("eyepos", transformation::Camera.get_position().x, transformation::Camera.get_position().y, transformation::Camera.get_position().z, 1.0f);

        set_uniform_1f("u_specular_intensity", material.c_specular_intensity);
        set_uniform_1f("u_specular_exponent", material.c_specular_exponent);

        set_uniform_4f("Directional_light.base.colour", d_light.base.colour.x, d_light.base.colour.y, d_light.base.colour.z, d_light.base.colour.w);
        set_uniform_1f("Directional_light.base.intensity", d_light.base.intensity);
        set_uniform_4f("Directional_light.direction", d_light.direction.x, d_light.direction.y, d_light.direction.z, d_light.direction.w);

    }


//    shader* get_shader(){
//        return &Shader;
//    }

};

#endif // FORWARD_DIRECTIONAL_H_INCLUDED
