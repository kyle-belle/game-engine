#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class material{

public:
    texture tex;
    glm::vec4 c_colour = glm::vec4(1.0f,1.0f,1.0f,1.0f);
    float c_specular_intensity;
    float c_specular_exponent;

    material(){}
    material(glm::vec4& colour);
    material(texture& Texture);
    material(texture& Texture, glm::vec4& Colour);
    material(texture& Texture, glm::vec4& Colour, float specular_intensity, float specular_exponent);

    void set_colour(glm::vec4& colour);
    void set_material(texture& Texture);
    void set_material(texture& Texture, glm::vec4& Colour);
    void set_material(texture& Texture, glm::vec4& Colour, float specular_intensity, float specular_exponent);

    void bind(int slot = 0){
        tex.bind(0);
    }



};

#endif // MATERIAL_H_INCLUDED
