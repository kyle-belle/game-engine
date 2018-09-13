#ifndef VERTEX_BUFFER_H_INCLUDED
#define VERTEX_BUFFER_H_INCLUDED

#include "obj_loader.h"
#include "vector4f.h"
#include <GL/glew.h>

struct base_light{
    vector4f colour;
    float intensity;
};

struct directional_light{
    base_light base;
    vector4f direction;
};

class vertex_buffer{

    private :
        unsigned int p_renderer_id;
        unsigned int p_num_indices;
        GLuint p_vertex_ArrayObject;
        GLuint p_vertex_ArrayBuffers[4];

    public :

        std::vector<float> c_normals;

        vertex_buffer(const void* data , unsigned int size);
        vertex_buffer();

        ~vertex_buffer();
        void calc_normals(float* positions, unsigned int* indices);
        void binder()const;
        void unbinder()const;
        void draw();


};


#endif // VERTEX_BUFFER_H_INCLUDED
