#ifndef HALF_EDGE
#define HALF_EDGE

#endif // HALF_EDGE

#include <la.h>
#include "joint.h"


class Face;
class Vertex;
class HalfEdge;


class HalfEdge
{
private:
    Face* face;
    Vertex* vert;
    HalfEdge* next;
    HalfEdge* sym;
    int id;
public:
    HalfEdge(int n);
    void SetFace(Face* f);
    void SetVertex(Vertex* v);
    void SetNext(HalfEdge* l);
    void SetSym(HalfEdge* l);
    Face* GetFace();
    Vertex* GetVertex();
    HalfEdge* GetNext();
    HalfEdge* GetSym();
    int GetID();

};

class Vertex
{
private:
    glm::vec3 pos;
    HalfEdge* edge;
    int id;
    std::vector<int> Joint_Influence;
    std::vector<float>Joint_Weights;
public:
    Vertex(int n);
    void SetPosition(glm::vec3 v);
    void SetHalfEdge(HalfEdge* l);
    void AddJoints(int id);
    void AddJointsWeights(float weight);
    int GetJoint(int n);
    float GetJointWeight(int n);
    int GetJointNum();
    void Joint_Influence_clear();
    void Joint_Weights_clear();
    glm::vec3 GetPosition();
    HalfEdge* GetHalfEdge();

    int GetID();
};

class Face
{
private:

    HalfEdge* start_edge;
    glm::vec3 color;
    int id;
public:
    Face(int n);
    void SetStartEdge(HalfEdge* l);
    void SetColor(glm::vec3 c);
    HalfEdge* GetStartEdge();
    glm::vec3 GetColor();
    int GetID();
};


