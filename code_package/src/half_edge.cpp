#include"half_edge.h"


HalfEdge::HalfEdge(int n):id(n),face(NULL),vert(NULL),next(NULL),sym(NULL)
{}
void HalfEdge::SetFace(Face* f)
{
    face=f;
}
void HalfEdge::SetVertex(Vertex *v)
{
    vert=v;
}
void HalfEdge::SetNext(HalfEdge *l)
{
    next=l;
}
void HalfEdge::SetSym(HalfEdge *l)
{
    sym=l;
}
int HalfEdge::GetID()
{
    return id;
}
Face* HalfEdge::GetFace()
{
    return face;
}
Vertex* HalfEdge::GetVertex()
{
    return vert;
}
HalfEdge* HalfEdge::GetNext()
{
    return next;
}
HalfEdge* HalfEdge::GetSym()
{
    return sym;
}


Vertex::Vertex(int n):id(n),pos(0,0,0),edge(NULL)
{
}

void Vertex::SetPosition(glm::vec3 v)
{
    pos=v;
}
void Vertex::SetHalfEdge(HalfEdge *l)
{
    edge=l;
}
void Vertex::AddJoints(int j)
{
    Joint_Influence.push_back(j);
}

void Vertex::AddJointsWeights(float weight)
{
    Joint_Weights.push_back(weight);
}


int Vertex::GetJoint(int n)
{
    return Joint_Influence[n];
}
int Vertex::GetJointNum()
{
    return Joint_Influence.size();
}

float Vertex::GetJointWeight(int n)
{
    return Joint_Weights[n];
}

void Vertex::Joint_Influence_clear()
{
    Joint_Influence.clear();
}
void Vertex::Joint_Weights_clear()
{
    Joint_Weights.clear();
}

int Vertex::GetID()
{
    return id;
}
glm::vec3 Vertex::GetPosition()
{
    return pos;
}

HalfEdge* Vertex::GetHalfEdge()
{
    return edge;
}


Face::Face(int n):id(n),start_edge(NULL),color(0,0,0)
{
}
void Face::SetColor(glm::vec3 c)
{
    color=c;
}

void Face::SetStartEdge(HalfEdge *l)
{
    start_edge=l;
}
int Face::GetID()
{
    return id;
}

glm::vec3 Face::GetColor()
{
    return color;
}
HalfEdge* Face::GetStartEdge()
{
    return start_edge;
}

