#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "vertex_array.h"
#include <stdio.h>
#include <string.h>
#include "game.h"

#define print(format, args...) printf(format, args)

class display{

public :

    char c_name[20] = "3D GAME";
    double frame_time;
    game* Game;

display(char* name, int width, int height, double frame_cap, game* GAME){

    this->Game = GAME;

    frame_time = 1.0/frame_cap;


    GLFWwindow* window;

     glewExperimental = true;

    /* Initialize the library */
    if (!glfwInit())
        printf("failed to init GLFW!\n");


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, c_name, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    p_window = window;

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if(glewInit()!=GLEW_OK)
        printf("error");

    glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

    Game->init_game((*this));

//    gameloop gameloop((*this));

    print("%s\n",glGetString(GL_VERSION));

    glfwSwapInterval(0);
    }

    ~display(){}

void append_name(display& display, char* name){
    char aname[20];
    strcpy(aname,c_name);
    strcat(aname, name);

    glfwSetWindowTitle(display.get_window(), aname);

}

void render(){
  glClear(GL_COLOR_BUFFER_BIT);
}

 int get_window_height()const{
     int a, b;
     glfwGetWindowSize(get_window(),&a,&b);
     return b;
 }

 int get_window_width()const{
    int a, b;
     glfwGetWindowSize(get_window(),&a,&b);
     return a;
 }

    inline bool should_window_close()const{ return p_window_should_closed; }
    inline GLFWwindow* get_window()const { return p_window; }

private :
    GLFWwindow* p_window;
    bool p_window_should_closed = false;
};

typedef display window;

#endif // DISPLAY_H_INCLUDED
