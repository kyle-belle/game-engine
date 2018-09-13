#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "input.h"
#include "vector2f.h"
#include "vector3f.h"
#include "matrices.h"
#include "mesh.h"
#include "shader.h"
#include "resource_loader.h"
#include "obj_loader.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "index_buffer.h"
#include "camera.h"
#include "texture.h"
#include "material.h"
#include "GLFW/glfw3.h"
#include "game_object.h"

class display;


class game{
public :

    game_object root;

    GLFWwindow* window;

    IndexedModel model;
    IndexedModel tree_model;

    mesh Mesh;
    //mesh.load_mesh("\\box1.obj");


    mesh3D tree_object;
    mesh3D object;

    mesh3D terrains;

    camera Camera;

    //shader terrainshader;
    static shader basic_shader;
    static shader phong_shader;

    texture Texture;
    texture Texture2;
    texture Texture3;

    base_light p_base1;
    attenuation p_atten1;

    base_light p_base2;
    attenuation p_atten2;

    point_light point_light1;
    point_light point_light2;

    spot_light spot_light1;
    spot_light spot_light2;

///    spot_light Spot_light[shader::MAX_SPOT_LIGHTS];

    directional_light d_light;

    glm::vec3 cam = glm::vec3(0,0,-3);

    glm::vec4 colour = glm::vec4(1.0f,1.0f,1.0f,1.0f);

    material Material;

    transform Transform;

    transformation Transformation;

    float temp;
    float temp2;

unsigned int index[6] = {
        0, 1, 2,
        2, 3, 0
    };
input input;

game(display& display);

virtual void init_game(display& display);

 game(){};

virtual ~game();
int i=0;
float o;


virtual void inputs(display& display);

virtual int get_height(display& display);
virtual int get_width(display& display);

virtual void update(transform& Transform,camera& camera);

//virtual void render();
//virtual void render(transform& transform);
virtual void render(index_buffer& ib,shader& shader);
virtual void delete_textures();

virtual game_object* getroot();

};

#endif // GAME_H_INCLUDED
