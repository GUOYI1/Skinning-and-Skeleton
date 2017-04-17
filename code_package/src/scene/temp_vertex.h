#ifndef VERTEX_H
#define VERTEX_H

#endif // VERTEX_H
#include "drawable.h"
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

//This is not used to construct halfedge data structure.
class temp_vertex:public Drawable
{
private:
    glm::vec3 vert_coords;
    glm::vec3 v_color;
    int id;
public:
    temp_vertex(GLWidget277 *context);
    virtual void create();
    virtual GLenum drawMode();
    void SetVerts(glm::vec3 v);
    void SetColor(glm::vec3 c);
    void SetID(int n);
    glm::vec3 GetVerts();
    int GetID();
};
