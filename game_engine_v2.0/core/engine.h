#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <thread>
#include <stdio.h>
#include "game.h"
#include "TIMER.H"
#include "transform.h"
#include "rendering_engine/rendering_engine.h"


double FRAME_TIME;
int FRAMES = 0;

std::chrono::duration<double, std::milli> TIME::delta;
std::chrono::duration<double, std::milli> TIME::time;

shader game::basic_shader;
shader game::phong_shader;


float transformation::zNEAR = 0.1f;
float transformation::zFAR = 1000.0f;
float transformation::FOV = 35.0f;
int transformation::HEIGHT;
int transformation::WIDTH;

camera transformation::Camera;

std::chrono::duration<float> frame_counter = std::chrono::milliseconds(0);

class gameloop{

public :
//render_util Render_util;
game* Game;
rendering_engine render_engine;


gameloop(display& display){

    FRAME_TIME = display.frame_time;

//    game game1(display);
    Game = display.Game;

    start(display);
}


void start(display& display){
render_engine.init_graphics();
if(p_engine_running)
    stop();
run(display);
}

private :

void run(display& display){

    p_engine_running = true;
    bool renderr = false;

    transformation::HEIGHT = display.get_window_height();
    transformation::WIDTH = display.get_window_width();

    render_engine.link_transformation(&Game->Transformation);

//    float x=0.5f;
//
//    float positions[] = {
//        -x , -x, 0.0f, 0.0f, 0.0f,
//         x , -x, 0.0f, 1.0f, 0.0f,
//         x ,  x, 0.0f, 1.0f, 1.0f,
//        -x ,  x, 0.0f, 0.0f, 1.0f
//    };
//    unsigned int index[] = {
//        0, 1, 2,
//        2, 3, 0
//    };

    //IndexedModel model = OBJModel("C:\\Users\\stuppzzzz\\Desktop\\game\\sphere3.obj").ToIndexedModel();
    //mesh3D mesh3D(model);

    //base_light p_base1;
    //p_base1.colour = glm::vec4(1.0f,0.0f,0.0f,1.0f);
    //p_base1.intensity = 0.8f;

    //attenuation p_atten1;
    //p_atten1.set_attenuation(1.0f,0.0f,0.0f);

    //attenuation p_atten2;
    //p_atten2.set_attenuation(0.0f,0.0f,0.01f);

    //base_light p_base2;
    //p_base2.colour = glm::vec4(0.0f,0.0f,1.0f,1.0f);
    //p_base2.intensity = 0.8f;

    //point_light point_light1;
    //point_light1.set_point_light(p_base1, p_atten1, glm::vec3(2.0f,0.0f,-1.0f),10);

    //point_light point_light2;
    //point_light2.set_point_light(p_base2, p_atten2, glm::vec3(-2.0f,0.0f,1.0f),10);

    //spot_light spot_light1;
    //spot_light spot_light2;

    //spot_light1.set_spot_light(point_light2,glm::vec3(0,0,1),0.7f);

    //spot_light2.set_spot_light

    //point_light1.set_point_light(base_light())

//    vertex_array va;
//    vertex_buffer vb(positions, sizeof(positions));
//
//    vb.calc_normals(positions, index);
//    vertex_buffer vn(&vb.c_normals[0], sizeof(vb.c_normals));
//
    //shader shader(vertex_shader,fragment_shader);
    //shader.binder();
//
//    vertex_buffer_layout layout;
//    layout.push(3,VALUE_TYPE::FLOAT);
//    layout.push(2, VALUE_TYPE::FLOAT);

    //point_light point_light[shader.MAX_POINT_LIGHTS];
    //spot_light spot_light[shader.MAX_SPOT_LIGHTS];

    //spot_light[0] = spot_light1;

    //point_light[0] = point_light1;
    //point_light[1] = point_light2;

    //shader.set_point_lights(point_light);
    //shader.set_uniform_point_light();

    //shader.set_spot_lights(spot_light);
    //shader.set_uniform_spot_light();

    //vertex_buffer_layout ln;
    //ln.push(3,VALUE_TYPE::FLOAT);

    //va.add_vertex_buffer(vb,layout);
    //va.add_vertex_buffer(vn,ln);

    //index_buffer ib(index, 6);

    //directional_light d_light;

    //printf("%f\n", vb.c_normals[0]);

//    d_light.base.colour = glm::vec4(0.5f,0.5f,0.5f,0.5f);
//    d_light.base.intensity = 1.0f;
//    d_light.direction = glm::vec4(0.0f,0.0f,-1.0f,1.0f);

//    shader.set_uniform_4f("Directional_light.base.colour", d_light.base.colour.x, d_light.base.colour.y, d_light.base.colour.z, d_light.base.colour.w);
//    shader.set_uniform_1f("Directional_light.base.intensity", d_light.base.intensity);
//    shader.set_uniform_4f("Directional_light.direction", d_light.direction.x, d_light.direction.y, d_light.direction.z, d_light.direction.w);

    //va.binder();
    //mesh mesh;
    //mesh.load_mesh("\\box1.obj");

    //texture texture("flat_map1.jpg");
    //texture.binder();

//    camera camera(glm::vec3(0,0,-3),70.0f, 4.0f/3.0f, 0.01f, 1000.0f);
    //spot_light1.c_point_lights.c_pos = camera.p_position;
    //spot_light1.c_direction = camera.p_forward;
    //shader.set_uniform_spot_light();

    //transform transform;

    auto prev = std::chrono::high_resolution_clock::now();
    //float tr=0.0f;

    //glm::vec4 colour = glm::vec4(1.0f,1.0f,1.0f,1.0f);

    //material material(colour);
    //Game->Shader.set_uniform_1f("u_specular_intensity",material.c_specular_intensity);
    //Game->Shader.set_uniform_1f("u_specular_exponent",material.c_specular_exponent);


    //glm::vec3 cam = glm::vec3(0,0,-3);

    //Game->Shader.set_uniform_4f("u_colour",material.c_colour.r, material.c_colour.g, material.c_colour.b, material.c_colour.a);
    //Game->Shader.set_uniform_4f("ambient_light", 0.3f, 0.3f, 0.3f, 0.3f);

    //vector3f vec3(1,0,0);
    float t = 0.001f;
    char frames[20];
    std::chrono::duration<double, std::milli> pass_time;
    double unprocessed_time;

    while (p_engine_running){

        ///renderr = false;

        auto start = std::chrono::high_resolution_clock::now();
        pass_time = start - prev;

        TIME::time += pass_time;
        //std::cout<<pass_time.count()<<"\n";

        prev = start;

        unprocessed_time += pass_time/std::chrono::seconds(1);
        frame_counter += pass_time;

        while(unprocessed_time > FRAME_TIME){
            renderr = true;
            unprocessed_time -= FRAME_TIME;

//            //transform.get_position().x = sin(t);
////            transform.get_position().z = 5;
//            transform.get_rotation().y += 0.001f/5;
//            //transform.get_rotation().z += 0.001f;
//            transform.get_scale().x = 0.6;
//            transform.get_scale().y = 0.6;
//            transform.get_scale().z = 0.6;

            if(glfwGetKey(display.get_window(),GLFW_KEY_LEFT)){
                //vec3.set_xyz(1,0,0);
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_left(), sin(t));
                //vec3.set_xyz(0,sin(t),0);
                //Game->Transformation.set_translation(vec3);
                //Game->Transformation.set_rotation(vec3);
                //Game->Shader.set_uniform_mat4f("translate",Game->Transformation.get_projected_transformation());
                //t += 0.001f;
            }
            if(glfwGetKey(display.get_window(),GLFW_KEY_D))
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_right(), sin(t));

            if(glfwGetKey(display.get_window(),GLFW_KEY_W))
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_up(), sin(t));

            if(glfwGetKey(display.get_window(),GLFW_KEY_S))
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_up(), -sin(t));

            if(glfwGetKey(display.get_window(),GLFW_KEY_A))
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_left(), sin(t));

            if(glfwGetKey(display.get_window(),GLFW_KEY_I))
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_forward(), sin(t));

            if(glfwGetKey(display.get_window(),GLFW_KEY_K))
                Game->Transformation.Camera.move(Game->Transformation.Camera.get_forward(), -sin(t));

            if(glfwGetKey(display.get_window(),GLFW_KEY_UP))
                Game->Transformation.Camera.rotate_x(-0.05f);

            if(glfwGetKey(display.get_window(),GLFW_KEY_DOWN))
                Game->Transformation.Camera.rotate_x(0.05f);

            if(glfwGetKey(display.get_window(),GLFW_KEY_LEFT))
                Game->Transformation.Camera.rotate_y(-0.05f);

            if(glfwGetKey(display.get_window(),GLFW_KEY_RIGHT))
                Game->Transformation.Camera.rotate_y(0.05f);

            if(glfwGetKey(display.get_window(),GLFW_KEY_ESCAPE))
                stop();

            //cam = glm::vec3(,0,-1);
            //camera.set_camera(Game->cam);
            //Game->Shader.set_uniform_4f("eyepos",Game->cam.x,Game->cam.y,Game->cam.z,1.0f);
            //tr+=0.0001f;

//            Game->spot_light[0].c_point_lights.c_pos = camera.p_position;
//            Game->spot_light[0].c_direction = camera.p_forward;
//            Game->Shader.set_spot_lights(Game->spot_light);
//            Game->Shader.set_uniform_spot_light();


            //Game->inputs(display);
            //Game->update(transform);

            if(glfwWindowShouldClose(display.get_window()))
                stop();

            if(frame_counter >= std::chrono::seconds(1)){

                sprintf(frames,"  FPS: %d",FRAMES);
                display.append_name(display, frames);
                FRAMES=0;
                frame_counter = std::chrono::milliseconds(0);
            }
        }
        ///renderr = true;
            if(renderr){
                render_engine.render(Game->getroot());
                swap_buffers(display);
                FRAMES++;
                //renderr = false;
            }else{
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
    }
}


void swap_buffers(display& display){
    /* Render here */

    //Game->basic_shader.set_uniform_mat4f("u_mvp", Game->Transformation.get_projected_transformation());
    //Game->Transformation.set_rotation(0,180,0);

    ///Game->render();

    //Game->render(ib, shader);

    /* Swap front and back buffers */
    glfwSwapBuffers(display.get_window());

    /* Poll for and process events */
        glfwPollEvents();
}


void stop(){
    if(!p_engine_running){
        glfwTerminate();
        cleanup();
    }
    p_engine_running = false;
}

    void cleanup(){
        Game->delete_textures();
    }

    //variables
    bool p_engine_running = false;
};

#endif // ENGINE_H_INCLUDED
