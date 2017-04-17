#include"temp_line.h"
temp_line::temp_line(GLWidget277 *context):Drawable(context),id(-1){}

void temp_line::SetID(int n)
{
    id=n;
}

void temp_line::SetStart(glm::vec3 v_start)
{
    startpoint=v_start;
}


void temp_line::SetEnd(glm::vec3 v_end)
{
    endpoint=v_end;
}

int temp_line::GetID()
{
    return id;
}
void temp_line::SetStartColor(glm::vec3 c)
{
    startpoint_color=c;
}

void temp_line::SetEndColor(glm::vec3 c)
{
    endpoint_color=c;
}

glm::vec3 temp_line::GetStartVerts()
{
    return startpoint;
}
glm::vec3 temp_line::GetEndVerts()
{
    return endpoint;
}
GLenum temp_line::drawMode()
{
    return GL_LINES;
}

void temp_line::create()
{
    count = 2;
    glm::vec3 vert_position[2];
    vert_position[0]=startpoint;
    vert_position[1]=endpoint;
//    glm::vec3 vert_normal[2];
//    //light position is (5,5,3).Set the highlight position pure white.
//    vert_normal[0]=glm::vec3(5,5,3)-startpoint;
//    vert_normal[1]=glm::vec3(5,5,3)-endpoint;
    glm::vec3 vert_color[2];
    vert_color[0]=startpoint_color;
    vert_color[1]=endpoint_color;
    GLuint index[2];
    index[0]=0;
    index[1]=1;

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // CYL_IDX_COUNT multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2*sizeof(GLuint),index, GL_STATIC_DRAW);

    // The next few sets of function calls are basically the same as above, except bufPos and bufNor are
    // array buffers rather than element array buffers, as they store vertex attributes like position.
    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, 2*sizeof(glm::vec3), vert_position, GL_STATIC_DRAW);

//    generateNor();
//    context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
//    context->glBufferData(GL_ARRAY_BUFFER, 2*sizeof(glm::vec3), vert_normal, GL_STATIC_DRAW);

    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, 2*sizeof(glm::vec3), vert_color, GL_STATIC_DRAW);
}
