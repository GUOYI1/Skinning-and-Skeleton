#include"temp_face.h"
#include<iostream>
temp_face_border::temp_face_border(GLWidget277 *context):Drawable(context),id(-1){}

void temp_face_border::push_vertex(glm::vec3 face_v)
{
    face_vertex.push_back(face_v);
}
void temp_face_border::SetID(int n)
{
    id=n;
}
void temp_face_border::SetColor(glm::vec3 face_color)
{
    color=face_color;
}
int temp_face_border::GetID()
{
    return id;
}

glm::vec3 temp_face_border::GetColor()
{
    return color;
}
glm::vec3 temp_face_border::GetVertex(int n)
{
    return face_vertex[n];
}

GLenum temp_face_border::drawMode()
{
    return GL_LINES;
}
void temp_face_border::clear_vert()
{
    face_vertex.clear();
    std::vector<glm::vec3>().swap(face_vertex);
}
void temp_face_border::create()
{
    std::vector<glm::vec3> vert_position;
    //Since we don't need normal vector for highlight part, we don't need to
    //make copies on vertex in vbo
    for(int i=0;i<face_vertex.size();i++)
        vert_position.push_back(face_vertex[i]);
    std::vector<GLuint> index;
    for(int i=0;i<face_vertex.size()-1;i++)
    {
        index.push_back(i);
        index.push_back(i+1);
    }
    index.push_back(face_vertex.size()-1);
    index.push_back(0);
    count=index.size();
    std::vector<glm::vec3> vert_color;
    for(int i=0;i<index.size();i++)
    {
        vert_color.push_back(glm::vec3());
        for(int j=0;j<3;j++)
        {
            vert_color[i][j]=fabs(color[j]-1.0f);
        }


    }

    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(GLuint),index.data(), GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, vert_position.size()*sizeof(glm::vec3), vert_position.data(), GL_STATIC_DRAW);

    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, vert_color.size()*sizeof(glm::vec3), vert_color.data(), GL_STATIC_DRAW);
}


