#include "drawable.h"
#include <la.h>

Drawable::Drawable(GLWidget277* context)
    : bufIdx(), bufPos(), bufNor(), bufCol(),
      idxBound(false), posBound(false), norBound(false), colBound(false),\
      Influence_ID_Bound(false),Vertex_Weights_Bound(false),\
      context(context)
{}


void Drawable::destroy()
{
    context->glDeleteBuffers(1, &bufIdx);
    context->glDeleteBuffers(1, &bufPos);
    context->glDeleteBuffers(1, &bufNor);
    context->glDeleteBuffers(1, &bufCol);
    context->glDeleteBuffers(1, &bufInfluence_ID);
    context->glDeleteBuffers(1,&bufVertex_Weights);
}

GLenum Drawable::drawMode()
{
    // Since we want every three indices in bufIdx to be
    // read to draw our Drawable, we tell that the draw mode
    // of this Drawable is GL_TRIANGLES

    // If we wanted to draw a wireframe, we would return GL_LINES

    return GL_TRIANGLES;
}

int Drawable::elemCount()
{
    return count;
}

void Drawable::generateIdx()
{
    idxBound = true;
    // Create a VBO on our GPU and store its handle in bufIdx
    context->glGenBuffers(1, &bufIdx);
}

void Drawable::generatePos()
{
    posBound = true;
    // Create a VBO on our GPU and store its handle in bufPos
    context->glGenBuffers(1, &bufPos);
}

void Drawable::generateNor()
{
    norBound = true;
    // Create a VBO on our GPU and store its handle in bufNor
    context->glGenBuffers(1, &bufNor);
}

void Drawable::generateCol()
{
    colBound = true;
    // Create a VBO on our GPU and store its handle in bufCol
    context->glGenBuffers(1, &bufCol);
}
void Drawable::generateInfluence_ID()
{
    Influence_ID_Bound=true;
    context->glGenBuffers(1,&bufInfluence_ID);
}
void Drawable::generateVertex_Weight()
{
    Vertex_Weights_Bound=true;
    context->glGenBuffers(1,&bufVertex_Weights);
}

bool Drawable::bindIdx()
{
    if(idxBound) {
        context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    }
    return idxBound;
}

bool Drawable::bindPos()
{
    if(posBound){
        context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    }
    return posBound;
}

bool Drawable::bindNor()
{
    if(norBound){
        context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    }
    return norBound;
}

bool Drawable::bindCol()
{
    if(colBound){
        context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    }
    return colBound;
}
bool Drawable::bindInfluence_ID()
{
    if(Influence_ID_Bound)
        context->glBindBuffer(GL_ARRAY_BUFFER, bufInfluence_ID);
    return Influence_ID_Bound;
}
bool Drawable::bindVertex_Weight()
{
    if(Vertex_Weights_Bound)
        context->glBindBuffer(GL_ARRAY_BUFFER, bufVertex_Weights);
    return Vertex_Weights_Bound;
}
