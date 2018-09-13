#ifndef MESH_RENDERER_H_INCLUDED
#define MESH_RENDERER_H_INCLUDED

#include "game_component.h"
#include "mesh.h"
#include "resource_loader.h"
#include "material.h"

class mesh_renderer : public game_component{

public:

    mesh3D* Mesh;
    material Material;
    //shader* basic_shader;

    mesh_renderer(){}

    mesh_renderer(mesh3D* MESH, material& MATERIAL, transformation* transform);

    void set(mesh3D* MESH, material& MATERIAL, transformation* transform);

    void render(shader* shader) override ;

};

#endif // MESH_RENDERER_H_INCLUDED
