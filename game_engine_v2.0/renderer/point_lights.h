#ifndef POINT_LIGHTS_H_INCLUDED
#define POINT_LIGHTS_H_INCLUDED

#include "vertex_buffer.h"
#include "vector3f.h"

struct attenuation{

    float constant;
    float linear;
    float exponent;

    attenuation(){}

    void set_attenuation(float constant, float linear, float exponent){

        this->constant = constant;
        this->linear = linear;
        this->exponent = exponent;
    }
};

struct point_light{

    base_light base;
    attenuation atten;
    vector3f pos;
    float range;

    point_light(){}

    void set_point_light(base_light& base_light, attenuation& attenuation, vector3f& pos, float range){

        this->base = base_light;
        this->atten = attenuation;
        this->pos = pos;
        this->range = range;
    }

};

struct spot_light{

   point_light point_lights;
   vector3f direction;
   float cutoff;

   spot_light(){}

   void set_direction_and_pos(vector3f& direction, vector3f pos){
    direction.x = direction.x;
    direction.y = direction.y;
    direction.z = direction.z;

    point_lights.pos.x = pos.x;
    point_lights.pos.y = pos.y;
    point_lights.pos.z = pos.z;
   }

   void set_spot_light(point_light& point_light, vector3f& direction, float cutoff){
        this->point_lights = point_light;
        this->direction = direction;
        this->cutoff = cutoff;
   }

};












#endif // POINT_LIGHTS_H_INCLUDED
