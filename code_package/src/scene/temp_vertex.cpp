#include "temp_vertex.h"
temp_vertex::temp_vertex(GLWidget277 *context):Drawable(context),id(-1){}
void temp_vertex::SetID(int n)
{
    id=n;
}
void temp_vertex::SetVerts(glm::vec3 v)
{
    vert_coords=v;
}
void temp_vertex::SetColor(glm::vec3 c)
{
    v_color=c;
}

int temp_vertex::GetID()
{
    return id;
}

glm::vec3 temp_vertex::GetVerts()
{
    return vert_coords;
}
GLenum temp_vertex::drawMode()
{
    return GL_POINTS;
}

void temp_vertex::create()
{
    count = 1;
    glm::vec3 vert_position[1];
    vert_position[0]=vert_coords;
//    glm::vec3 vert_normal[1];
//    //light position is (5,5,3).Set the highlight position pure white.
//    vert_normal[0]=glm::vec3(5,5,3)-vert_coords;
    glm::vec3 vert_color[1];
    vert_color[0]=v_color;
    GLuint index[1];
    index[0]=0;

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint),index, GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3), vert_position, GL_STATIC_DRAW);

//    generateNor();
//    context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
//    context->glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3), vert_normal, GL_STATIC_DRAW);

    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER,  sizeof(glm::vec3), vert_color, GL_STATIC_DRAW);

}

