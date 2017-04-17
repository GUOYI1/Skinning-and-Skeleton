#ifndef TEMP_LINE_H
#define TEMP_LINE_H

#endif // TEMP_LINE_H
#include "drawable.h"
#include <la.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

//This is not used to construct halfedge data structure.
class temp_line:public Drawable
{
private:
    glm::vec3 startpoint;
    glm::vec3 endpoint;
    glm::vec3 startpoint_color;
    glm::vec3 endpoint_color;
    int id;
public:
    temp_line(GLWidget277 *context);
    virtual void create();
    virtual GLenum drawMode();
    void SetID(int n);
    void SetStart(glm::vec3 v_start);
    void SetEnd(glm::vec3 v_end);
    void SetStartColor(glm::vec3 c);
    void SetEndColor(glm::vec3 c);
    int GetID();
    glm::vec3 GetStartVerts();
    glm::vec3 GetEndVerts();
};


