#ifndef FORWARD_POINT_H_INCLUDED
#define FORWARD_POINT_H_INCLUDED

#include "shader.h"
#include "point_lights.h"
#include "vector4f.h"

class forward_point : public shader{

public:

     point_light Point_light;

     forward_point(){

     }

void init_shader(){
    load_shaders(forward_point_vertex_shader, forward_point_fragment_shader);

    attenuation p_atten1;
    p_atten1.set_attenuation(0.0f,0.0f,0.1f);

    base_light p_base2;

    p_base2.colour = vector4f(1.0f,0.5f,1.0f,1.0f);
    p_base2.intensity = 0.8f;

    vector3f pos(0.0f,0.0f,2.0f);

    Point_light.set_point_light(p_base2, p_atten1, pos,10);
}

    void update_uniforms(transformation& transform, material& material) override {

        set_uniform_mat4f("u_mvp", transform.get_projected_transformation());
        set_uniform_mat4f("translate", transform.get_transformation());
        set_uniform_4f("eyepos", transformation::Camera.get_position().x, transformation::Camera.get_position().y, transformation::Camera.get_position().z, 1.0f);

        set_uniform_1f("u_specular_intensity", material.c_specular_intensity);
        set_uniform_1f("u_specular_exponent", material.c_specular_exponent);

        set_uniform_4f("Point_light.base.colour", Point_light.base.colour.x, Point_light.base.colour.y, Point_light.base.colour.z, Point_light.base.colour.w);
        set_uniform_1f("Point_light.base.intensity", Point_light.base.intensity);
        set_uniform_1f("Point_light.atten.constant", Point_light.atten.constant);
        set_uniform_1f("Point_light.atten.linear", Point_light.atten.linear);
        set_uniform_1f("Point_light.atten.exponent", Point_light.atten.exponent);
        set_uniform_4f("Point_light.position",Point_light.pos.x, Point_light.pos.y, Point_light.pos.z, 1.0f);
        set_uniform_1f("Point_light.range", Point_light.range);

    }

    inline void set_point_light(base_light& base_light, attenuation& attenuation, vector3f& pos, float range){
        Point_light.set_point_light(base_light, attenuation, pos, range);
    }

};

#endif // FORWARD_POINT_H_INCLUDED
