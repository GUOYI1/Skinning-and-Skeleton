#ifndef MESH_H
#define MESH_H

#endif // MESH_H

#include"half_edge.h"
#include "drawable.h"

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class Mesh:public Drawable
{
private:
    std::vector<Face> mesh_face;
    std::vector<HalfEdge> mesh_halfedge;
    std::vector<Vertex> mesh_vertex;
    std::vector<bool> mesh_face_sharp;
    std::vector<bool>mesh_halfedge_sharp;
    std::vector<bool>mesh_vertex_sharp;
    bool subdivision_flag;
public:
    Mesh(GLWidget277* context);
    void Mesh_Initialize(const std::vector<glm::vec3>&v,\
                         const std::vector<int>& v_indice,\
                         const std::vector<glm::vec3> face_color,\
                         const std::vector<int>& face_sides);
    void Mesh_sharp_Initialize();
    void Face_push(Face f);
    void HalfEdge_push(HalfEdge l);
    void Vertex_push(Vertex v);
    void SetVertexPosition(int n,glm::vec3 v);
    void SetVertexJoint(int n,int id);
    void SetVertexJointWeight(int n,float w);
    void SetFaceColor(int n,glm::vec3 c);    
    bool Empty();
    int Get_Face_num();
    int Get_Vertex_num();
    int Get_HalfEdge_num();
    Face Get_Mesh_Face(int n);
    HalfEdge Get_Mesh_HalfEdge(int n);
    Vertex Get_Mesh_Vertex(int n);


    void create_cube_mesh();

    //Operation on mesh,including adding vertex,triangulating faces,and subdivison
    void Add_Mesh_Vertex(int l_selected_ID,glm::vec3 insert_pos);
    void Triangluate_Mesh_Face(int f_selected_ID);
    void Mesh_Subdivison();
    void Mesh_Face_Extrude(int f_selected_ID,float trans_distance);
    glm::vec3 Centroid(Face f);
    void Subdivision_Insert_MidPoint(std::vector<glm::vec3>centroid_points);
    void Quadrangulate(Face f,glm::vec3 centroid);

    bool Planarity_test(int f_selected_ID);
    void Bevel_Face(int f_selected_ID);
    void Set_Sharp(int id);


    virtual void create();
    void create_joint_influence();   
    void clear_joint_influence();
    void clearmesh();
};
//This is not a halfedge.It is only used for construct halfedge data structure temporarily
struct edge_memory
{
    int id;
    int startpoint_index;
    int endpoint_index;
};

