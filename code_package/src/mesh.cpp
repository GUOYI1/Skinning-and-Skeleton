#include"mesh.h"
#include<la.h>
#include <iostream>

Mesh::Mesh(GLWidget277* context) : Drawable(context),subdivision_flag(false)
{}



void Mesh::Face_push(Face f)
{
    mesh_face.push_back(f);
}
void Mesh::HalfEdge_push(HalfEdge l)
{
    mesh_halfedge.push_back(l);
}
void Mesh::Vertex_push(Vertex v)
{
    mesh_vertex.push_back(v);
}
void Mesh::SetVertexPosition(int n,glm::vec3 v)
{
    mesh_vertex[n].SetPosition(v);
}
void Mesh::SetVertexJoint(int n,int id)
{
    mesh_vertex[n].AddJoints(id);
}
void Mesh::SetVertexJointWeight(int n, float w)
{
    mesh_vertex[n].AddJointsWeights(w);
}

void Mesh::SetFaceColor(int n,glm::vec3 c)
{
    mesh_face[n].SetColor(c);
}

Face Mesh::Get_Mesh_Face(int n)
{
    return mesh_face[n];
}
HalfEdge Mesh::Get_Mesh_HalfEdge(int n)
{
    return mesh_halfedge[n];
}
Vertex Mesh::Get_Mesh_Vertex(int n)
{
    return mesh_vertex[n];
}
int Mesh::Get_Face_num()
{
    return mesh_face.size();
}
int Mesh::Get_Vertex_num()
{
    return mesh_vertex.size();
}
int Mesh::Get_HalfEdge_num()
{
    return mesh_halfedge.size();
}

void Mesh::create_cube_mesh()
{
    std::vector<glm::vec3> cube_v;
    std::vector<int>cube_v_indice;
    std::vector<glm::vec3> cube_color;
    //This array is used to deal with the case that the number of mesh face is not constant.
    //In this assignment, all the elements in the array are always 4.
    std::vector<int> facesides;
    facesides.resize(6);
    cube_color.resize(6);
    cube_v.resize(8);
    cube_v_indice.resize(24);

    for(int i=0;i<6;i++)
    {
        facesides[i]=4;
    }
    //cube face color
    cube_color[0]=glm::vec3(1.0f,0.0f,0.0f);
    cube_color[1]=glm::vec3(0.0f,1.0f,0.0f);
    cube_color[2]=glm::vec3(0.0f,0.0f,1.0f);
    cube_color[3]=glm::vec3(0.0f,1.0f,0.0f);
    cube_color[4]=glm::vec3(0.0f,0.0f,1.0f);
    cube_color[5]=glm::vec3(1.0f,0.0f,0.0f);
    //cube vertex
    cube_v[0]=glm::vec3(0.5f,0.5f,0.5f);
    cube_v[1]=glm::vec3(-0.5f,0.5f,0.5f);
    cube_v[2]=glm::vec3(-0.5f,-0.5f,0.5f);
    cube_v[3]=glm::vec3(0.5f,-0.5f,0.5f);

    cube_v[4]=glm::vec3(0.5f,0.5f,-0.5f);
    cube_v[5]=glm::vec3(0.5f,-0.5f,-0.5f);
    cube_v[6]=glm::vec3(-0.5f,-0.5f,-0.5f);
    cube_v[7]=glm::vec3(-0.5f,0.5f,-0.5f);

    //Front face indice
    cube_v_indice[0]=0;
    cube_v_indice[1]=1;
    cube_v_indice[2]=2;
    cube_v_indice[3]=3;

    //right face vertex
    cube_v_indice[4]=0;
    cube_v_indice[5]=3;
    cube_v_indice[6]=5;
    cube_v_indice[7]=4;

    //top face vertex
    cube_v_indice[8]=0;
    cube_v_indice[9]=4;
    cube_v_indice[10]=7;
    cube_v_indice[11]=1;

    //left face vertex
    cube_v_indice[12]=2;
    cube_v_indice[13]=1;
    cube_v_indice[14]=7;
    cube_v_indice[15]=6;

    //botttom face vertex
    cube_v_indice[16]=3;
    cube_v_indice[17]=2;
    cube_v_indice[18]=6;
    cube_v_indice[19]=5;

    //back face
    cube_v_indice[20]=4;
    cube_v_indice[21]=5;
    cube_v_indice[22]=6;
    cube_v_indice[23]=7;

    Mesh_Initialize(cube_v,cube_v_indice,cube_color,facesides);


}

void Mesh::Mesh_Initialize(const std::vector<glm::vec3>& v,\
                           const std::vector<int>& v_indice,\
                           const std::vector<glm::vec3> face_color,\
                           const std::vector<int>& face_sides)//Initialize Mesh using halfedge data structure
{
    clearmesh();

    int index=0;
    //This is not a halfedge vector.This edge vector is used to save the startpoint and endpoint of each edge,
    //which can help us to find "sym" member for each halfedge.
    std::map<tuple,HalfEdge*> edge_map;
    std::map<tuple,HalfEdge*>::iterator it;
    mesh_face.reserve(face_sides.size()*300);
    mesh_halfedge.reserve(v_indice.size()*600);
    mesh_vertex.reserve(v.size()*300);

    for(int i=0;i<v.size();i++)
    {
        Vertex vert_temp(i);
        vert_temp.SetPosition(v[i]);
        mesh_vertex.push_back(vert_temp);
    }
    for(int i=0;i<face_sides.size();i++)
    {
        Face face_temp(i);
        mesh_face.push_back(face_temp);
        mesh_face[i].SetColor(face_color[i]);
        for(int j=index;j<index+face_sides[i];j++)
        {
            HalfEdge halfedge_temp(j);
            mesh_halfedge.push_back(halfedge_temp);
            if(mesh_vertex[v_indice[j]].GetHalfEdge()==NULL)
                mesh_vertex[v_indice[j]].SetHalfEdge(&mesh_halfedge[j]);
            mesh_halfedge[j].SetVertex(&mesh_vertex[v_indice[j]]);
            mesh_halfedge[j].SetFace(&mesh_face[i]);
            tuple p,p_inverse;
            if(j!=index)
            {
                mesh_halfedge[j-1].SetNext(&mesh_halfedge[j]);
                p=tuple(v_indice[j-1],v_indice[j]);
                p_inverse=tuple(v_indice[j],v_indice[j-1]);
            }
            else
            {
                p=tuple(v_indice[index+face_sides[i]-1],v_indice[j]);
                p_inverse=tuple(v_indice[j],v_indice[index+face_sides[i]-1]);
            }
            if(j==index+face_sides[i]-1)
            {
                mesh_halfedge[j].SetNext(&mesh_halfedge[index]);
            }

            it=edge_map.find(p_inverse);
            if(it!=edge_map.end())
            {
                mesh_halfedge[j].SetSym(it->second);
                it->second->SetSym(&mesh_halfedge[j]);
            }
            else
            {
                edge_map.insert(std::pair<tuple,HalfEdge*>(p,&mesh_halfedge[j]));
            }


        }
        mesh_face[i].SetStartEdge(&mesh_halfedge[index]);
        index+=face_sides[i];
    }
    Mesh_sharp_Initialize();
    create();
}
void Mesh::Mesh_sharp_Initialize()
{
    for(int i=0;i<mesh_face.size();i++)
        mesh_face_sharp.push_back(false);
    for(int i=0;i<mesh_halfedge.size();i++)
        mesh_halfedge_sharp.push_back(false);
    for(int i=0;i<mesh_vertex.size();i++)
        mesh_vertex_sharp.push_back(false);
}

bool Mesh::Empty()
{
    if(mesh_vertex.size()==0)
        return true;
    else
    {
        return false;
    }
}

void Mesh::create()
{
    std::vector<GLuint> index;
    std::vector<glm::vec3> points;
    std::vector<glm::vec3> color;
    std::vector<glm::vec3>face_normal;

//    std::vector<glm::ivec2> Joint_Inf;
    std::vector<glm::vec2> Joint_Inf;
    std::vector<glm::vec2> Joint_W;
    int index_num=0;
    for(int i=0;i<mesh_face.size();i++)
    {
        HalfEdge* edge=mesh_face[i].GetStartEdge();
        glm::vec3 normal;
        int sides_num=0;
        int temp_index=1,start_id=edge->GetVertex()->GetID();
        do
        {
            Vertex* v=edge->GetVertex();
            glm::ivec2 J;
            glm::vec2 W;
            points.push_back(v->GetPosition());
            sides_num++;
            color.push_back(mesh_face[i].GetColor());
            edge=edge->GetNext();

            if(v->GetJointNum()>0)
            {
                J[0]=v->GetJoint(0);
                J[1]=v->GetJoint(1);
                W[0]=v->GetJointWeight(0);
                W[1]=v->GetJointWeight(1);
                Joint_Inf.push_back(J);
                Joint_W.push_back(W);

            }
        }  while(edge!=mesh_face[i].GetStartEdge());

        while(temp_index!=sides_num-1)
        {
            index.push_back(index_num);
            index.push_back(index_num+temp_index);
            index.push_back(index_num+temp_index+1);
            temp_index++;
        }
        for(int i=0;i<sides_num;i++)
        {
            if(glm::normalize(points[index_num+i+1]-points[index_num+i])!=\
                    glm::normalize(points[index_num+2+i]-points[index_num+1+i]))
            {
                normal=glm::cross(points[index_num+1+i]-points[index_num+i],\
                        points[index_num+2+i]-points[index_num+1+i]);
                break;
            }
        }

        for(int j=0;j<sides_num;j++)
            face_normal.push_back(normal);
        index_num+=sides_num;


    }

    count = index.size();
    //Using OpenGl to render the mesh
    generateIdx();
    context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(GLuint), index.data(), GL_STATIC_DRAW);

    generatePos();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    context->glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(glm::vec3), points.data(), GL_STATIC_DRAW);

    generateCol();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    context->glBufferData(GL_ARRAY_BUFFER, color.size() * sizeof(glm::vec3), color.data(), GL_STATIC_DRAW);

    generateNor();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    context->glBufferData(GL_ARRAY_BUFFER, face_normal.size() * sizeof(glm::vec3), face_normal.data(), GL_STATIC_DRAW);

    generateVertex_Weight();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufVertex_Weights);
    context->glBufferData(GL_ARRAY_BUFFER, Joint_W.size() * sizeof(glm::vec2), Joint_W.data(), GL_STATIC_DRAW);

    generateInfluence_ID();
    context->glBindBuffer(GL_ARRAY_BUFFER, bufInfluence_ID);
    //context->glBufferData(GL_ARRAY_BUFFER, Joint_Inf.size() * sizeof(glm::ivec2), Joint_Inf.data(), GL_STATIC_DRAW);
    context->glBufferData(GL_ARRAY_BUFFER, Joint_Inf.size() * sizeof(glm::vec2), Joint_Inf.data(), GL_STATIC_DRAW);







}

void Mesh::create_joint_influence()
{
//    std::vector<glm::ivec2> Joint_Inf;
//    std::vector<glm::vec2> Joint_W;

//    for(int i=0;i<mesh_face.size();i++)
//    {

//        HalfEdge* edge=mesh_face[i].GetStartEdge();
//        do
//        {
//            Vertex* v=edge->GetVertex();
//            glm::ivec2 J;
//            glm::vec2 W;
//            if(v->GetJointNum()>0)
//            {
//                J[0]=v->GetJoint(0);
//                J[1]=v->GetJoint(1);
//                W[0]=v->GetJointWeight(0);
//                W[1]=v->GetJointWeight(1);
//                edge=edge->GetNext();

//                Joint_Inf.push_back(J);
//                Joint_W.push_back(W);

//            }

//        } while(edge!=mesh_face[i].GetStartEdge());
//    }
//    generateInfluence_ID();
//    context->glBindBuffer(GL_ARRAY_BUFFER, bufInfluence_ID);
//    context->glBufferData(GL_ARRAY_BUFFER, Joint_Inf.size() * sizeof(glm::ivec2), Joint_Inf.data(), GL_STATIC_DRAW);

//    generateVertex_Weight();
//    context->glBindBuffer(GL_ARRAY_BUFFER, bufVertex_Weights);
//    context->glBufferData(GL_ARRAY_BUFFER, Joint_W.size() * sizeof(glm::vec2), Joint_W.data(), GL_STATIC_DRAW);




}

void Mesh::Add_Mesh_Vertex(int l_selected_ID,glm::vec3 insert_pos)
{
    int v_ID=Get_Vertex_num(),HE_1B_ID=Get_HalfEdge_num(),HE_2B_ID=HE_1B_ID+1,\
            HE_1_ID=l_selected_ID;

    mesh_vertex.push_back(Vertex(v_ID));
    mesh_halfedge.push_back(HalfEdge(HE_1B_ID));
    mesh_halfedge.push_back(HalfEdge(HE_2B_ID));

    HalfEdge& HE_1B=mesh_halfedge[HE_1B_ID],&HE_2B=mesh_halfedge[HE_2B_ID],\
            &HE_1=mesh_halfedge[HE_1_ID],&HE_2=*(HE_1.GetSym());
    Vertex& v_add=mesh_vertex[v_ID],&v1_origin=*(HE_1.GetVertex()),\
            &v2_origin=*(HE_2.GetVertex());
    //Set vertex attribute
    v_add.SetHalfEdge(&HE_1);
    v_add.SetPosition(insert_pos);

    //Set the attribute of a pair of sym HalfEdges
    HE_1B.SetVertex(&v1_origin);
    HE_2B.SetVertex(&v2_origin);
    if(v1_origin.GetHalfEdge()==&HE_1)
        v1_origin.SetHalfEdge(&HE_1B);
    if(v2_origin.GetHalfEdge()==&HE_2)
        v2_origin.SetHalfEdge(&HE_2B);
    HE_1B.SetFace(HE_1.GetFace());
    HE_2B.SetFace(HE_2.GetFace());


    //Adjust the sym, next, and vert pointers of new and origin halfedges
    HE_1B.SetNext(HE_1.GetNext());
    HE_2B.SetNext(HE_2.GetNext());
    HE_1.SetNext(&HE_1B);
    HE_2.SetNext(&HE_2B);
    HE_1.SetVertex(&v_add);
    HE_2.SetVertex(&v_add);
    //Set sym
    HE_1.SetSym(&HE_2B);
    HE_2B.SetSym(&HE_1);
    HE_2.SetSym(&HE_1B);
    HE_1B.SetSym(&HE_2);


}

void Mesh::Triangluate_Mesh_Face(int f_selected_ID)
{
    int v_0_ID=mesh_face[f_selected_ID].GetStartEdge()->GetVertex()->GetID(),\
            HE_START_ID=mesh_face[f_selected_ID].GetStartEdge()->GetID();
    HalfEdge HE_flag=*(mesh_face[f_selected_ID].GetStartEdge()->GetNext());
    Vertex &v_start=mesh_vertex[v_0_ID];
    Face &f_selected=mesh_face[f_selected_ID];
    while(HE_flag.GetNext()->GetNext()->GetID()!=HE_START_ID)
    {

        int HE_A_ID=mesh_halfedge.size(),HE_B_ID=mesh_halfedge.size()+1,\
                HE_0_ID=HE_flag.GetNext()->GetID(),HE_flag_ID=HE_flag.GetID();
        //Create 2 new halfedges
        mesh_halfedge.push_back(HalfEdge(HE_A_ID));
        mesh_halfedge.push_back(HalfEdge(HE_B_ID));

        HalfEdge &HE_A=mesh_halfedge[HE_A_ID],&HE_B=mesh_halfedge[HE_B_ID],\
                &HE_0=mesh_halfedge[HE_0_ID];
        HE_A.SetVertex(HE_0.GetVertex());
        HE_B.SetVertex(&v_start);
        HE_A.SetSym(&HE_B);
        HE_B.SetSym(&HE_A);
        //Create a new face
        int FACE_ADD_ID=mesh_face.size();
        mesh_face.push_back(Face(FACE_ADD_ID));
        Face &FACE_ADD=mesh_face[FACE_ADD_ID];
        HE_A.SetFace(&f_selected);
        HE_B.SetFace(&FACE_ADD);
        HE_0.SetFace(&FACE_ADD);
        mesh_halfedge[HE_flag_ID].SetFace(&FACE_ADD);
        FACE_ADD.SetStartEdge(&HE_B);
        FACE_ADD.SetColor(f_selected.GetColor());
        //Fix up "next" pointer for halfedge
        HE_B.SetNext(&mesh_halfedge[HE_flag_ID]);
        mesh_halfedge[HE_START_ID].SetNext(&HE_A);
        HE_A.SetNext(HE_0.GetNext());
        HE_0.SetNext(&HE_B);

        HE_flag=HE_A;
    }
}


glm::vec3 Mesh::Centroid(Face f)
{
    HalfEdge l=*(f.GetStartEdge());
    int side_num=1;
    glm::vec3 result=l.GetVertex()->GetPosition();
    while(l.GetNext()!=f.GetStartEdge())
    {
        l=*(l.GetNext());
        result+=l.GetVertex()->GetPosition();
        side_num++;
    }
    result/=float(side_num);
    return result;
}

void Mesh::Subdivision_Insert_MidPoint(std::vector<glm::vec3>centroid_point)
{
    int halfedge_num_origin=mesh_halfedge.size();

    std::vector<HalfEdge> mesh_halfedge_copy;
    std::vector<bool> halfedge_flag;

    mesh_halfedge_copy.reserve(mesh_halfedge.capacity());
    halfedge_flag.reserve(mesh_halfedge.capacity());

    for(int i=0;i<halfedge_num_origin;i++)
    {
        halfedge_flag.push_back(false);
        mesh_halfedge_copy.push_back(mesh_halfedge[i]);
    }
    for(int i=0;i<halfedge_num_origin;i++)
    {
        glm::vec3 v1,v2,f1,f2;
        HalfEdge HE=mesh_halfedge_copy[i],HE_SYM=*HE.GetSym();
        int HE_ID=HE.GetID(),HE_SYM_ID=HE_SYM.GetID();
        if(halfedge_flag[HE_ID])
            continue;
        else
        {
            int F1_ID=HE.GetFace()->GetID(),F2_ID=HE_SYM.GetFace()->GetID();
            v1=HE.GetVertex()->GetPosition();
            v2=HE_SYM.GetVertex()->GetPosition();
            f1=centroid_point[F1_ID];
            f2=centroid_point[F2_ID];
            Add_Mesh_Vertex(HE_ID,(v1+v2+f1+f2)/4.0f);
            halfedge_flag[HE_ID]=true;
            halfedge_flag[HE_SYM_ID]=true;
        }

    }


}


void Mesh::Mesh_Subdivison()
{
    subdivision_flag=true;
    int v_origin_num=mesh_vertex.size(),f_num=mesh_face.size();
    std::vector<int> v_origin_ID;
    std::vector<glm::vec3> centroid_point;
    v_origin_ID.reserve(mesh_vertex.capacity());
    centroid_point.reserve(mesh_face.capacity());
    for(int i=0;i<v_origin_num;i++)
        v_origin_ID.push_back(mesh_vertex[i].GetID());
    for(int i=0;i<f_num;i++)
        centroid_point.push_back(Centroid(mesh_face[i]));
    Subdivision_Insert_MidPoint(centroid_point);
    for(int i=0;i<v_origin_num;i++)
    {
        int n=1;

        Vertex &v=mesh_vertex[v_origin_ID[i]];
        HalfEdge l=*(v.GetHalfEdge()),l_temp=*(l.GetNext());
        glm::vec3 sum_e=l_temp.GetVertex()->GetPosition(),\
                sum_f=centroid_point[l_temp.GetFace()->GetID()];
        while(l_temp.GetSym()->GetID()!=l.GetID())
        {
            l_temp=*(l_temp.GetSym()->GetNext());
            sum_e+=l_temp.GetVertex()->GetPosition();
            sum_f+=centroid_point[l_temp.GetFace()->GetID()];
            n++;
        }
        float n_f=float(n);
        v.SetPosition((n_f-2)*v.GetPosition()/n_f+sum_e/(n_f*n_f)+sum_f/(n_f*n_f));

    }
    for(int i=0;i<f_num;i++)
        Quadrangulate(mesh_face[i], centroid_point[i]);
    subdivision_flag=false;


}
//only used for Subdivision
 void Mesh::Quadrangulate(Face f,glm::vec3 centroid)
{

     if(!subdivision_flag)
         return;
     int edge_num=mesh_halfedge.size(),edge_num_origin=edge_num,v_centroid_ID=mesh_vertex.size(),\
             f_num=mesh_face.size(),TEMP_ID=f.GetStartEdge()->GetID();

     std::vector<HalfEdge> HE_origin;
     for(int i=0;i<edge_num;i++)
        HE_origin.push_back(mesh_halfedge[i]);
     mesh_vertex.push_back(Vertex(v_centroid_ID));
     Vertex &v_centroid=mesh_vertex[v_centroid_ID];
     v_centroid.SetPosition(centroid);
     HalfEdge HE_START=HE_origin[TEMP_ID],HE_TEMP=HE_START;
     do
     {
         int HE_1_ID=edge_num,HE_2_ID=edge_num+1,F_ID=-1;
         if(HE_TEMP.GetID()!=HE_START.GetID())
         {
             F_ID=f_num;
             mesh_face.push_back(Face(F_ID));
             f_num++;
         }
         else
             F_ID=f.GetID();

         mesh_halfedge.push_back(HalfEdge(HE_1_ID));
         mesh_halfedge.push_back(HalfEdge(HE_2_ID));
         HalfEdge &HE_1=mesh_halfedge[HE_1_ID],&HE_2=mesh_halfedge[HE_2_ID];
         Face &F=mesh_face[F_ID];
         HE_1.SetVertex(HE_TEMP.GetVertex());
         HE_1.SetNext(HE_TEMP.GetNext());
         HE_1.SetFace(&F);
         HE_2.SetVertex(&v_centroid);
         if(!v_centroid.GetHalfEdge())
             v_centroid.SetHalfEdge(&HE_2);
         HE_2.SetNext(&HE_1);
         HE_2.SetFace(&F);

         HE_TEMP.GetNext()->SetFace(&F);
         HE_TEMP.GetNext()->GetNext()->SetFace(&F);
         HE_TEMP.GetNext()->GetNext()->SetNext(&HE_2);
         F.SetStartEdge(HE_TEMP.GetNext()->GetNext());
         F.SetColor(f.GetColor());
         if(HE_1.GetID()-1>edge_num_origin)
         {
             HE_1.SetSym(&mesh_halfedge[HE_1.GetID()-1]);
             mesh_halfedge[HE_1.GetID()-1].SetSym(&HE_1);
         }
         edge_num+=2;
         TEMP_ID=HE_TEMP.GetNext()->GetNext()->GetID();
         HE_TEMP=HE_origin[TEMP_ID];

     }while(HE_TEMP.GetID()!=HE_START.GetID());
     mesh_halfedge[edge_num_origin].SetSym(&mesh_halfedge[edge_num-1]);
     mesh_halfedge[edge_num-1].SetSym(&mesh_halfedge[edge_num_origin]);

}

void Mesh::Mesh_Face_Extrude(int f_selected_ID,float trans_distance)
{
    int v_num=mesh_vertex.size(),v_origin_num=v_num;
    int l_num=mesh_halfedge.size(),l_num_origin=l_num;
    int f_num=mesh_face.size(),f_num_origin=f_num;
    Face *f_selected=&mesh_face[f_selected_ID];
    glm::vec3 distance;
    HalfEdge* HE_PRE=f_selected->GetStartEdge(),\
            *HE_1=HE_PRE->GetNext(),*HE_2=HE_1->GetSym();
    do
    {
        glm::vec3 point1=HE_PRE->GetVertex()->GetPosition();
        glm::vec3 point2=HE_PRE->GetNext()->GetVertex()->GetPosition();
        glm::vec3 point3=HE_PRE->GetNext()->GetNext()->GetVertex()->GetPosition();
        if(glm::normalize(point2-point1)!=glm::normalize(point3-point2))
        {
            distance=glm::normalize(glm::cross(point2-point1,point3-point2))*trans_distance;
            break;
        }
        HE_PRE=HE_PRE->GetNext();
    }while(HE_PRE->GetID()!=f_selected->GetStartEdge()->GetID());
    HE_PRE=f_selected->GetStartEdge();
    mesh_vertex.push_back(Vertex(v_num));

    Vertex* v1=HE_1->GetVertex(),*v2=HE_2->GetVertex(),*v3=NULL,*v4=&mesh_vertex[v_num];
    v4->SetPosition(HE_2->GetVertex()->GetPosition()+distance);
    v_num++;

    do
    {
        if(HE_1->GetID()==f_selected->GetStartEdge()->GetID())
            v3=&mesh_vertex[v_origin_num];
        else
        {
            mesh_vertex.push_back(Vertex(v_num));
            v3=&mesh_vertex[v_num];
            v3->SetPosition(HE_1->GetVertex()->GetPosition()+distance);
        }

        mesh_halfedge.push_back(HalfEdge(l_num));
        mesh_halfedge.push_back(HalfEdge(l_num+1));
        mesh_halfedge.push_back(HalfEdge(l_num+2));
        mesh_halfedge.push_back(HalfEdge(l_num+3));
        mesh_face.push_back(Face(f_num));
        HalfEdge *HE_1_B=&mesh_halfedge[l_num],*HE_2_B=&mesh_halfedge[l_num+1],\
                *HE_3=&mesh_halfedge[l_num+2],*HE_4=&mesh_halfedge[l_num+3];
        Face* F=&mesh_face[f_num];
        l_num+=4;
        v_num++;
        f_num++;

        HE_1->SetVertex(v3);

        HE_1->SetSym(HE_1_B);
        HE_2->SetSym(HE_2_B);
        HE_1_B->SetSym(HE_1);
        HE_2_B->SetSym(HE_2);
        HE_1_B->SetVertex(v4);
        HE_2_B->SetVertex(v1);

        HE_1_B->SetFace(F);
        HE_2_B->SetFace(F);
        HE_3->SetFace(F);
        HE_4->SetFace(F);
        HE_3->SetVertex(v3);
        HE_4->SetVertex(v2);
        if(v1->GetHalfEdge()==HE_1)
           v1->SetHalfEdge(HE_2_B);
        v4->SetHalfEdge(HE_1_B);
        HE_1_B->SetNext(HE_4);
        HE_4->SetNext(HE_2_B);
        HE_2_B->SetNext(HE_3);
        HE_3->SetNext(HE_1_B);
        F->SetStartEdge(HE_1_B);
        F->SetColor(f_selected->GetColor());
        if(HE_4->GetID()-5>l_num_origin-1)
        {
            HE_4->SetSym(&mesh_halfedge[HE_4->GetID()-5]);
            mesh_halfedge[HE_4->GetID()-5].SetSym(HE_4);
        }
        HE_PRE=HE_1;
        HE_1=HE_1->GetNext();
        HE_2=HE_1->GetSym();
        v1=HE_1->GetVertex();
        v2=HE_2->GetVertex();
        v4=v3;
    }while(HE_PRE->GetID()!=f_selected->GetStartEdge()->GetID());
    mesh_halfedge[l_num_origin+3].SetSym(&mesh_halfedge[l_num-2]);
    mesh_halfedge[l_num-2].SetSym(&mesh_halfedge[l_num_origin+3]);

}

bool Mesh::Planarity_test(int f_selected_ID)
{
    bool Planarity=true;
    Face f=mesh_face[f_selected_ID];
    HalfEdge *l=f.GetStartEdge();
    do
    {
        glm::vec3 normal1;
        glm::vec3 normal2;
        glm::vec3 point1=l->GetVertex()->GetPosition();
        glm::vec3 point2=l->GetNext()->GetVertex()->GetPosition();
        glm::vec3 point3=l->GetNext()->GetNext()->GetVertex()->GetPosition();
        glm::vec3 point4=l->GetNext()->GetNext()->GetNext()->GetVertex()->GetPosition();
        if(glm::normalize(point2-point1)!=glm::normalize(point3-point2)&&\
                glm::normalize(point3-point2)!=glm::normalize(point4-point3))
        {
            normal1=glm::normalize(glm::cross(point2-point1,point3-point2));
            normal2=glm::normalize(glm::cross(point3-point2,point4-point3));
            if(normal1!=normal2)
            {
                Planarity=false;
                break;
            }
        }
        l=l->GetNext();
    }while(l->GetID()!=f.GetStartEdge()->GetID());

    return Planarity;

}
void Mesh::Bevel_Face(int f_selected_ID)
{
    for(int i=0;i<3;i++)
    {
        Mesh_Face_Extrude(f_selected_ID,0.1);
        HalfEdge*l=mesh_face[f_selected_ID].GetStartEdge();
        glm::vec3 centroid=Centroid(mesh_face[f_selected_ID]);
        do
        {
            glm::vec3 v=l->GetVertex()->GetPosition();
            v=centroid+(v-centroid)*0.8f;
            l->GetVertex()->SetPosition(v);
            l=l->GetNext();
        }while(l!=mesh_face[f_selected_ID].GetStartEdge());
    }

}
void Mesh::clear_joint_influence()
{
    for(int i=0;i<Get_Vertex_num();i++)
    {
        mesh_vertex[i].Joint_Influence_clear();
        mesh_vertex[i].Joint_Weights_clear();
    }

}




void Mesh::clearmesh()
{
    mesh_face.clear();
    std::vector<Face>().swap(mesh_face);
    mesh_halfedge.clear();
    std::vector<HalfEdge>().swap(mesh_halfedge);
    mesh_vertex.clear();
    std::vector<Vertex>().swap(mesh_vertex);
}
