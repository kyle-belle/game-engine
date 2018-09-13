#ifndef RENDERING_ENGINE_H_INCLUDED
#define RENDERING_ENGINE_H_INCLUDED

#include "vector4f.h"
#include "forward_ambient.h"
#include "forward_directional.h"
#include "forward_point.h"
#include "forward_spot.h"

class game_object;
class transformation;

class rendering_engine{

public:

    forward_ambient ambient_shader;
    forward_directional directional_light_shader;
    forward_point point_light_shader;
    forward_spot spot_light_shader;

    ///vector4f ambient_light;

    transformation* Transformation;

    rendering_engine(){}

    void render(game_object* object);

    void clear_screen();

    void init_graphics();

    void link_transformation(transformation* TRANSFORMATION);

};

#endif // RENDERING_ENGINE_H_INCLUDED
