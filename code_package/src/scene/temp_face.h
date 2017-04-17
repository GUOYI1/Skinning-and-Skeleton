#ifndef FACE_H
#define FACE_H

#endif // FACE_H
#include "drawable.h"
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
//This is not used to construct halfedge data structure.
class temp_face_border:public Drawable
{
private:
    std::vector<glm::vec3> face_vertex;
    glm::vec3 color;
    int id;
public:
    temp_face_border(GLWidget277 *context);
    void push_vertex(glm::vec3 face_v);
    void SetColor(glm::vec3 face_color);
    void SetID(int n);
    int GetID();
    glm::vec3 GetColor();
    glm::vec3 GetVertex(int n);
    virtual void create();
    virtual GLenum drawMode();
    void clear_vert();

};
