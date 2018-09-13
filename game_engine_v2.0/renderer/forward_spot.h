#ifndef FORWARD_SPOT_H_INCLUDED
#define FORWARD_SPOT_H_INCLUDED

#include "shader.h"
#include "point_lights.h"

class forward_spot : public shader{

public:

     spot_light Spot_light;

     forward_spot(){

     }

void init_shader(){
    load_shaders(forward_spot_vertex_shader, forward_spot_fragment_shader);

    point_light Point_light;

    attenuation p_atten1;
    p_atten1.set_attenuation(0.0f,0.0f,0.1f);

    base_light p_base2;

    p_base2.colour = vector4f(1.0f,0.5f,0.0f,1.0f);
    p_base2.intensity = 0.8f;

    vector3f pos(0.0f, 0.0f, -1.0f);

    Point_light.set_point_light(p_base2, p_atten1, pos, 10);

    Spot_light.set_spot_light(Point_light, transformation::Camera.forward, 0.7f);
}

    void update_uniforms(transformation& transform, material& material) override {

        set_uniform_mat4f("u_mvp", transform.get_projected_transformation());
        set_uniform_mat4f("translate", transform.get_transformation());
        set_uniform_4f("eyepos", transformation::Camera.get_position().x, transformation::Camera.get_position().y, transformation::Camera.get_position().z, 1.0f);

        set_uniform_1f("u_specular_intensity", material.c_specular_intensity);
        set_uniform_1f("u_specular_exponent", material.c_specular_exponent);

//        set_uniform_4f("Point_light.base.colour", Point_light.c_base.colour.x, Point_light.c_base.colour.y, Point_light.c_base.colour.z, Point_light.c_base.colour.w);
//        set_uniform_1f("Point_light.base.intensity", Point_light.c_base.intensity);
//        set_uniform_1f("Point_light.atten.constant", Point_light.c_atten.c_constant);
//        set_uniform_1f("Point_light.atten.linear", Point_light.c_atten.c_linear);
//        set_uniform_1f("Point_light.atten.exponent", Point_light.c_atten.c_exponent);
//        set_uniform_4f("Point_light.position",Point_light.c_pos.x, Point_light.c_pos.y, Point_light.c_pos.z, 1.0f);
//        set_uniform_1f("Point_light.range", Point_light.c_range);

        set_uniform_4f("Spot_light.Point_light.base.colour", Spot_light.point_lights.base.colour.r, Spot_light.point_lights.base.colour.g, Spot_light.point_lights.base.colour.b, Spot_light.point_lights.base.colour.a);
        set_uniform_1f("Spot_light.Point_light.base.intensity", Spot_light.point_lights.base.intensity);
        set_uniform_1f("Spot_light.Point_light.atten.constant", Spot_light.point_lights.atten.constant);
        set_uniform_1f("Spot_light.Point_light.atten.linear", Spot_light.point_lights.atten.linear);
        set_uniform_1f("Spot_light.Point_light.atten.exponent", Spot_light.point_lights.atten.exponent);
        set_uniform_4f("Spot_light.Point_light.position", Spot_light.point_lights.pos.x, Spot_light.point_lights.pos.y, Spot_light.point_lights.pos.z, 1.0f);
        set_uniform_1f("Spot_light.Point_light.range", Spot_light.point_lights.range);
        set_uniform_4f("Spot_light.direction", Spot_light.direction.x, Spot_light.direction.y, Spot_light.direction.z, 1.0f);
        set_uniform_1f("Spot_light.cutoff", Spot_light.cutoff);

    }

    inline void set_spot_light(point_light& point_light, vector3f direction, float cutoff){
        Spot_light.set_spot_light(point_light, direction, cutoff);
    }

};


#endif // FORWARD_SPOT_H_INCLUDED
