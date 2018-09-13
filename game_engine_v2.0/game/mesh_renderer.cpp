#include "mesh_renderer.h"


///static texture Texture;

mesh_renderer::mesh_renderer(mesh3D* MESH, material& MATERIAL, transformation* transform){

    Mesh = MESH;
    Material = MATERIAL;
    Transformation = transform;
    ///basic_shader = SHADER;
    ///Texture.load_texture("white_army.jpg");

}

void mesh_renderer::set(mesh3D* MESH, material& MATERIAL, transformation* transform){

    Mesh = MESH;
    Material = MATERIAL;
    Transformation = transform;
    ///basic_shader = SHADER;
    ///Texture.load_texture("white_army.jpg");


}

void mesh_renderer::render(shader* shader){


    //printf("rendered");
    //Shader.binder();
    //Shader.set_uniform_mat4f("u_mvp", Transformation.get_projected_transformation());
    //Texture.bind(0);
    shader->bind();
    shader->update_uniforms(*Transformation, Material);
    Material.bind(0);

    ///shader.bind();
    Mesh->draw(*shader);

}
