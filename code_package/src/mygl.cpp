#define _USE_MATH_DEFINES
#include "mygl.h"
#include <la.h>
#include "math.h"
#include <iostream>
#include<QMessageBox>
#include <QApplication>
#include <QKeyEvent>


MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent),
      geom_cylinder(this), geom_sphere(this),geom_mesh(this),\
      v_selected(this),l_selected(this),f_selected(this),\
      joint_points(this),bone(this),wireframe(this),Selected_Joint(this),\
      prog_lambert(this), prog_flat(this),prog_skeleton(this),\
      gl_camera(),draw_point(false),draw_edge(false),draw_face(false),\
      skeleton_mode(false),draw_joint(false),skinning_mode(false),\
      Subdivison_times(0),timeCount(0),renderMode(0)
{
    // Connect the timer to a function so that when the timer ticks the function is executed
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    // Tell the timer to redraw 60 times per second
    timer.start(100);
    setFocusPolicy(Qt::StrongFocus);
}

MyGL::~MyGL()
{
    makeCurrent();
    glDeleteVertexArrays(1, &vao);
    geom_cylinder.destroy();
    geom_sphere.destroy();
    geom_mesh.destroy();
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    //Create the instances of Cylinder and Sphere.
 //   geom_cylinder.create();

 //   geom_sphere.create();

    //geom_mesh.create_cube_mesh();//create a cube mesh

    // Create and set up the diffuse shader
    prog_lambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the flat lighting shader
    prog_flat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");
    // Create and set up the skinning shader
    prog_skeleton.create(":/glsl/skeleton.vert.glsl", ":/glsl/skeleton.frag.glsl");

    // Set a color with which to draw geometry since you won't have one
    // defined until you implement the Node classes.
    // This makes your geometry render green.
    //prog_lambert.setGeometryColor(glm::vec4(0,1,0,1));

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
//    vao.bind();
    glBindVertexArray(vao);
    v_selected.SetColor(glm::vec3(1,1,1));
    l_selected.SetStartColor(glm::vec3(1,0,0));
    l_selected.SetEndColor(glm::vec3(1,1,0));


    Subdivison_times=0;
    initialize_seleced_ID();
    emit_geom_signal();

}


void MyGL::initializeMesh(const std::vector<glm::vec3>&v,\
                    const std::vector<int>& v_indice,\
                    const std::vector<glm::vec3> face_color,\
                    const std::vector<int>& face_sides)
{
    geom_mesh.Mesh_Initialize(v,v_indice,face_color,face_sides);
    initialize_draw_mode();
    Subdivison_times=0;
    initialize_seleced_ID();
    emit_geom_signal();
    emit Spinbox_disable();

}
void MyGL::initializeSkeleton(const std::vector<QString>&name,
                        const std::vector<glm::vec3> &pos,\
                        const std::vector<glm::quat>&rot,\
                        const std::vector<int> &parent_ID)
{
    int root_id=0;
    skeleton_mode=true;
    draw_joint=false;
    skeleton_joints.clear();
    std::vector<Joint>().swap(skeleton_joints);
    skeleton_joints.reserve(100);

    for(int i=0;i<name.size();i++)
    {
        Joint j(name[i]);
        j.SetPosition(pos[i]);
        j.SetRotation(rot[i]);
        if(parent_ID[i]==-1)
        {
            j.SetParent(NULL);
            root_id=i;
        }
        else
            j.SetParent(&skeleton_joints[parent_ID[i]]);
        j.SetBindMatrix();
        j.Set_Joint_ID(i);
        skeleton_joints.push_back(j);
    }
    for(int i=0;i<skeleton_joints.size();i++)
    {
        for(int j=i;j<skeleton_joints.size();j++)
            if(skeleton_joints[j].GetParent()==&skeleton_joints[i])
                skeleton_joints[i].AddChild(&skeleton_joints[j]);
    }
    emit Show_Tree(&skeleton_joints[root_id]);
    update();

}

void MyGL::initialize_seleced_ID()
{
    v_selected.SetID(-1);
    l_selected.SetID(-1);
    f_selected.SetID(-1);
}
void MyGL::initialize_draw_mode()
{
    draw_edge=false;
    draw_face=false;
    draw_point=false;
    skinning_mode=false;
}

void MyGL::resizeGL(int w, int h)
{
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    gl_camera = Camera(w, h);
    glm::mat4 viewproj = gl_camera.getViewProj();

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)

    prog_lambert.setViewProjMatrix(viewproj);
    prog_flat.setViewProjMatrix(viewproj);
    prog_skeleton.setViewProjMatrix(viewproj);

    printGLErrorLog();
}
void MyGL::emit_geom_signal()
{
    emit Show_ListItem_v(geom_mesh.Get_Vertex_num(),v_selected.GetID());
    emit Show_ListItem_f(geom_mesh.Get_Face_num(),f_selected.GetID());
    emit Show_ListItem_l(geom_mesh.Get_HalfEdge_num(),l_selected.GetID());

}

void MyGL::drawVertex(int id)
{
    draw_point=true;
    draw_edge=false;
    draw_face=false;
    v_selected.SetVerts((geom_mesh.Get_Mesh_Vertex(id)).GetPosition());
    v_selected.create();
}

void MyGL::drawEdge(int id)
{
    draw_point=false;
    draw_edge=true;
    draw_face=false;
    l_selected.SetEnd(geom_mesh.Get_Mesh_HalfEdge(id).GetVertex()->GetPosition());
    l_selected.SetStart(geom_mesh.Get_Mesh_HalfEdge(id).GetSym()->GetVertex()->GetPosition());
    l_selected.create();
}

void MyGL::drawFaceBorder(int id)
{
    f_selected.clear_vert();
    draw_point=false;
    draw_edge=false;
    draw_face=true;
    HalfEdge* l=geom_mesh.Get_Mesh_Face(id).GetStartEdge();
    while(l->GetNext()!=geom_mesh.Get_Mesh_Face(id).GetStartEdge())
    {
        f_selected.push_vertex(l->GetVertex()->GetPosition());
        l=l->GetNext();
    }
    f_selected.SetColor(geom_mesh.Get_Mesh_Face(id).GetColor());
    f_selected.push_vertex(l->GetVertex()->GetPosition());
    f_selected.create();
}
void MyGL::drawVertex_topography(QString s)
{
    if(draw_point)
    {
        HalfEdge l=*(geom_mesh.Get_Mesh_Vertex(v_selected.GetID()).GetHalfEdge());
        if(s=="HALF-EDGE")
        {
              l_selected.SetID(l.GetID());
              l_selected.SetEnd(v_selected.GetVerts());
              l_selected.SetStart(l.GetSym()->GetVertex()->GetPosition());
              l_selected.create();
              draw_point=false;
              draw_edge=true;
              emit halfedge_selected(l_selected.GetID());

        }

    }
    else return;
}
void MyGL::drawHalfEdge_topography(QString s)
{
    if(draw_edge)
    {
        HalfEdge l=geom_mesh.Get_Mesh_HalfEdge(l_selected.GetID());
        if(s=="NEXT")
        {
            l_selected.SetID(l.GetNext()->GetID());
            l_selected.SetEnd(l.GetNext()->GetVertex()->GetPosition());
            l_selected.SetStart(l.GetVertex()->GetPosition());
            l_selected.create();
            emit halfedge_selected(l_selected.GetID());

        }
        else if(s=="SYM")
        {
            l_selected.SetID(l.GetSym()->GetID());
            l_selected.SetEnd(l.GetSym()->GetVertex()->GetPosition());
            l_selected.SetStart(l.GetVertex()->GetPosition());
            l_selected.create();
            emit halfedge_selected(l_selected.GetID());

        }
        else if(s=="FACE")
        {
            HalfEdge l_copy=l;
            f_selected.clear_vert();
            f_selected.SetID(l.GetFace()->GetID());
            f_selected.push_vertex(l.GetVertex()->GetPosition());
            l=*(l.GetNext());
            while(l.GetID()!=l_copy.GetID())
            {
                f_selected.push_vertex(l.GetVertex()->GetPosition());
                l=*(l.GetNext());
            }
            f_selected.SetColor(geom_mesh.Get_Mesh_Face(f_selected.GetID()).GetColor());
            f_selected.create();
            emit face_selected(f_selected.GetID());

            draw_edge=false;
            draw_face=true;

        }
        else if(s=="VERTEX")
        {
            v_selected.SetID(l.GetVertex()->GetID());
            v_selected.SetVerts(l.GetVertex()->GetPosition());
            v_selected.create();
            emit vertex_selected(v_selected.GetID());

            draw_edge=false;
            draw_point=true;

        }

    }


}

void MyGL::drawFace_topography(QString s)
{
    if(draw_face)
    {
        HalfEdge l=*(geom_mesh.Get_Mesh_Face(f_selected.GetID()).GetStartEdge());
        if(s=="S+HAlfEDGE")
        {
            l_selected.SetID(l.GetID());
            l_selected.SetEnd(l.GetVertex()->GetPosition());
            l_selected.SetStart(l.GetSym()->GetVertex()->GetPosition());
            l_selected.create();
            emit halfedge_selected(l_selected.GetID());
            draw_face=false;
            draw_edge=true;
        }
    }
}

void MyGL::drawSkeleton()
{
    joint_points.SetColor(glm::vec3(1,0,0));
    bone.SetStartColor(glm::vec3(1,0,1));
    bone.SetEndColor(glm::vec3(1,1,0));
    for(int i=0;i<skeleton_joints.size();i++)
    {
        glm::mat4 m=skeleton_joints[i].GetOverallTransformation();
        float theta=0;
        for(int i=0;i<20;i++)
        {
            glm::vec4 wireframe1(0.5*cos(theta),0.5*sin(theta),0,1);
            glm::vec4 wireframe2(0.5*cos(theta+M_PI/10),0.5*sin(theta+M_PI/10),0,1);
            wireframe1=m*wireframe1;
            wireframe2=m*wireframe2;
            wireframe.SetStart(glm::vec3(wireframe1[0],wireframe1[1],wireframe1[2]));
            wireframe.SetEnd(glm::vec3(wireframe2[0],wireframe2[1],wireframe2[2]));
            wireframe.SetStartColor(glm::vec3(0,0,1));
            wireframe.SetEndColor(glm::vec3(0,0,1));
            wireframe.create();
            prog_flat.draw(wireframe);
            theta+=M_PI/10;

        }
        for(int i=0;i<20;i++)
        {
            glm::vec4 wireframe1(0.5*cos(theta),0,0.5*sin(theta),1);
            glm::vec4 wireframe2(0.5*cos(theta+M_PI/10),0,0.5*sin(theta+M_PI/10),1);
            wireframe1=m*wireframe1;
            wireframe2=m*wireframe2;
            wireframe.SetStart(glm::vec3(wireframe1[0],wireframe1[1],wireframe1[2]));
            wireframe.SetEnd(glm::vec3(wireframe2[0],wireframe2[1],wireframe2[2]));
            wireframe.SetStartColor(glm::vec3(0,1,0));
            wireframe.SetEndColor(glm::vec3(0,1,0));
            wireframe.create();
            prog_flat.draw(wireframe);
            theta+=M_PI/10;

        }
        for(int i=0;i<20;i++)
        {
            glm::vec4 wireframe1(0,0.5*cos(theta),0.5*sin(theta),1);
            glm::vec4 wireframe2(0,0.5*cos(theta+M_PI/10),0.5*sin(theta+M_PI/10),1);
            wireframe1=m*wireframe1;
            wireframe2=m*wireframe2;
            wireframe.SetStart(glm::vec3(wireframe1[0],wireframe1[1],wireframe1[2]));
            wireframe.SetEnd(glm::vec3(wireframe2[0],wireframe2[1],wireframe2[2]));
            wireframe.SetStartColor(glm::vec3(1,0,0));
            wireframe.SetEndColor(glm::vec3(1,0,0));
            wireframe.create();
            prog_flat.draw(wireframe);
            theta+=M_PI/10;

        }


        joint_points.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));

        if(skeleton_joints[i].GetParent())
        {
            glm::mat4 m_parent=skeleton_joints[i].GetParent()->GetOverallTransformation();
            bone.SetEnd(glm::vec3(m[3][0],m[3][1],m[3][2]));
            bone.SetStart(glm::vec3(m_parent[3][0],m_parent[3][1],m_parent[3][2]));
            bone.create();
            prog_flat.draw(bone);
        }
        joint_points.create();        
        prog_flat.draw(joint_points);

    }

}

int MyGL::Get_mesh_vertex_num()
{
    return geom_mesh.Get_Vertex_num();
}

int MyGL::Get_mesh_halfedge_num()
{
    return geom_mesh.Get_HalfEdge_num();
}
int MyGL::Get_mesh_face_num()
{
    return geom_mesh.Get_Face_num();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, ntntGL is called implicitly.
//DO NOT CONSTRUCT YOUR SCENE GRAPH IN THIS FUNCTION!
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    prog_flat.setViewProjMatrix(gl_camera.getViewProj());
    prog_lambert.setViewProjMatrix(gl_camera.getViewProj());
    prog_skeleton.setViewProjMatrix(gl_camera.getViewProj());
#define NOPE
#ifdef NOPE
    //Create a model matrix. This one scales the sphere uniformly by 3, then translates it by <-2,0,0>.
    //Note that we have to transpose the model matrix before passing it to the shader
    //This is because OpenGL expects column-major matrices, but you've
    //implemented row-major matrices.
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-2,0,0)) * glm::scale(glm::mat4(1.0f), glm::vec3(3,3,3));
    //Send the geometry's transformation matrix to the shader
    prog_lambert.setModelMatrix(model);
    //Draw the example sphere using our lambert shader
    //prog_lambert.draw(geom_sphere);

    //Now do the same to render the cylinder
    //We've rotated it -45 degrees on the Z axis, then translated it to the point <2,2,0>
    //model = glm::translate(glm::mat4(1.0f), glm::vec3(2,2,0)) * glm::rotate(glm::mat4(1.0f), glm::radians(-45.0f), glm::vec3(0,0,1));
    prog_lambert.setModelMatrix(model);
    //prog_lambert.draw(geom_cylinder);
    model=glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(1,0,0))*\
            glm::rotate(glm::mat4(1.0f), glm::radians(-45.0f), glm::vec3(0,1,0))*\
            glm::scale(glm::mat4(0.5f), glm::vec3(1,1,1));
    prog_skeleton.setModelMatrix(model);
    prog_lambert.setModelMatrix(model);
    prog_flat.setModelMatrix(model);
    if(!geom_mesh.Empty())
    {
        if(!skinning_mode)
        {
            prog_lambert.draw(geom_mesh);
            if(renderMode!=0)
            {
                draw_point=false;
                draw_edge=false;
                draw_face=false;
            }
            glDisable(GL_DEPTH_TEST);
            if(draw_point)
                prog_flat.draw(v_selected);
            if(draw_edge)
                prog_flat.draw(l_selected);
            if(draw_face)
                prog_flat.draw(f_selected);
            glEnable(GL_DEPTH_TEST);
        }
        else
        {
            prog_skeleton.draw(geom_mesh);
        }
    }

    timerUpdate();
    if(renderMode!=0)
    {
        skeleton_mode=false;
        draw_joint=false;
    }

    glDisable(GL_DEPTH_TEST);
    if(skeleton_mode)
        drawSkeleton();
    if(draw_joint)
        prog_flat.draw(Selected_Joint);
    glEnable(GL_DEPTH_TEST);



#endif
}


void MyGL::keyPressEvent(QKeyEvent *e)
{

    float amount = 2.0f;
    if(e->modifiers() & Qt::ShiftModifier){
        amount = 10.0f;
    }
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    // This could all be much more efficient if a switch
    // statement were used, but I really dislike their
    // syntax so I chose to be lazy and use a long
    // chain of if statements instead
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    } else if (e->key() == Qt::Key_Right) {
        gl_camera.RotateAboutUp(-amount);
    } else if (e->key() == Qt::Key_Left) {
        gl_camera.RotateAboutUp(amount);
    } else if (e->key() == Qt::Key_Up) {
        gl_camera.RotateAboutRight(-amount);
    } else if (e->key() == Qt::Key_Down) {
        gl_camera.RotateAboutRight(amount);
    } else if (e->key() == Qt::Key_1) {
        gl_camera.fovy += amount;
    } else if (e->key() == Qt::Key_2) {
        gl_camera.fovy -= amount;
    } else if (e->key() == Qt::Key_W) {
        gl_camera.TranslateAlongLook(amount);
    } else if (e->key() == Qt::Key_S) {
        gl_camera.TranslateAlongLook(-amount);
    } else if (e->key() == Qt::Key_D) {
        gl_camera.TranslateAlongRight(amount);
    } else if (e->key() == Qt::Key_A) {
        gl_camera.TranslateAlongRight(-amount);
    } else if (e->key() == Qt::Key_Q) {
        gl_camera.TranslateAlongUp(-amount);
    } else if (e->key() == Qt::Key_E) {
        gl_camera.TranslateAlongUp(amount);
    } else if (e->key() == Qt::Key_R) {
        gl_camera = Camera(this->width(), this->height());
    } else if(e->key()==Qt::Key_N){
        drawHalfEdge_topography("NEXT");
    } else if(e->key()==Qt::Key_M){
        drawHalfEdge_topography("SYM");
    } else if(e->key()==Qt::Key_F){
        drawHalfEdge_topography("FACE");
    } else if(e->key()==Qt::Key_V){
        drawHalfEdge_topography("VERTEX");
    } else if((e->modifiers()&Qt::ShiftModifier)&& (e->key()==Qt::Key_H)){
        drawFace_topography("S+HAlfEDGE");
    } else if(e->key()==Qt::Key_H){
        drawVertex_topography("HALF-EDGE");
    }


    gl_camera.RecomputeAttributes();
    update();  // Calls paintGL, among other things
}

void MyGL::timerUpdate()
{
    // This function is called roughly 60 times per second.
    // Use it to perform any repeated actions you want to do,
    // such as
    timeCount++;
    prog_lambert.SetRenderMode(renderMode);
    if(renderMode!=0)
    {
        prog_lambert.SetTimer(timeCount);
        update();
    }

}
void MyGL::highlight_vertex(QListWidgetItem* v_Item)
{
    if(!v_Item->isSelected())
        return;
    int id=(v_Item->text()).toInt();
    v_selected.SetID(id);
    drawVertex(id);
    update();
    emit Show_Spinbox_vx((v_selected.GetVerts())[0]);
    emit Show_Spinbox_vy((v_selected.GetVerts())[1]);
    emit Show_Spinbox_vz((v_selected.GetVerts())[2]);

}

void MyGL::highlight_edge(QListWidgetItem* l_Item)
{
    if(!l_Item->isSelected())
        return;
    int id=(l_Item->text()).toInt();
    l_selected.SetID(id);
    drawEdge(id);
    update();

}

void MyGL::highlight_face(QListWidgetItem* f_Item)
{
    if(!f_Item->isSelected())
        return;
    int id=(f_Item->text()).toInt();
    f_selected.SetID(id);
    drawFaceBorder(id);
    update();
    emit Show_Spinbox_color_R((f_selected.GetColor())[0]);
    emit Show_Spinbox_color_G((f_selected.GetColor())[1]);
    emit Show_Spinbox_color_B((f_selected.GetColor())[2]);



}
void MyGL::vert_x_change(double vx)
{
    if(skinning_mode)
        return;
    glm::vec3 pos=(geom_mesh.Get_Mesh_Vertex(v_selected.GetID())).GetPosition();
    pos[0]=vx;
    geom_mesh.SetVertexPosition(v_selected.GetID(),pos);

    geom_mesh.create();
    drawVertex(v_selected.GetID());
    update();
}

void MyGL::vert_y_change(double vy)
{
    if(skinning_mode)
        return;
    glm::vec3 pos=(geom_mesh.Get_Mesh_Vertex(v_selected.GetID())).GetPosition();
    pos[1]=vy;
    geom_mesh.SetVertexPosition(v_selected.GetID(),pos);

    geom_mesh.create();
    drawVertex(v_selected.GetID());
    update();
}
void MyGL::vert_z_change(double vz)
{
    if(skinning_mode)
        return;
    glm::vec3 pos=(geom_mesh.Get_Mesh_Vertex(v_selected.GetID())).GetPosition();
    pos[2]=vz;
    geom_mesh.SetVertexPosition(v_selected.GetID(),pos);

    geom_mesh.create();
    drawVertex(v_selected.GetID());
    update();

}

void MyGL::face_color_R_change(double color_R)
{
    if(skinning_mode)
        return;
    glm::vec3 color=(geom_mesh.Get_Mesh_Face(f_selected.GetID())).GetColor();
    color[0]=color_R;
    geom_mesh.SetFaceColor(f_selected.GetID(),color);

    geom_mesh.create();
    update();
}
void MyGL::face_color_G_change(double color_G)
{
    if(skinning_mode)
        return;
    glm::vec3 color=(geom_mesh.Get_Mesh_Face(f_selected.GetID())).GetColor();
    color[1]=color_G;
    geom_mesh.SetFaceColor(f_selected.GetID(),color);

    geom_mesh.create();
    update();
}
void MyGL::face_color_B_change(double color_B)
{
    if(skinning_mode)
        return;
    glm::vec3 color=(geom_mesh.Get_Mesh_Face(f_selected.GetID())).GetColor();
    color[2]=color_B;
    geom_mesh.SetFaceColor(f_selected.GetID(),color);

    geom_mesh.create();
    update();
}

void MyGL::Skinning_Skeleton()
{

    skinning_mode=true;
    draw_edge=false;
    draw_point=false;
    draw_face=false;
    Linear_Skinning();
    update();

}


void MyGL::SetRenderMode_Value(int mode)
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot use OpenGL fun in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    renderMode=mode;
}
void MyGL::UndoSkinningMode()
{
    if(skinning_mode)
    {
        skinning_mode=false;
        geom_mesh.clear_joint_influence();
        update();
    }
}

void MyGL::Add_vertex()
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot add vertex in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    if(l_selected.GetID()!=-1)
    {
        geom_mesh.Add_Mesh_Vertex(l_selected.GetID(),\
                                  0.5f*(l_selected.GetStartVerts()+l_selected.GetEndVerts()));
        geom_mesh.create();
        drawEdge(l_selected.GetID());
        emit_geom_signal();
        update();
    }
    else
        QMessageBox::information(NULL,"Note","Please select a halfedge");

}
void MyGL::Triangulate_face()
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot Triangulate_face in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    if(f_selected.GetID()!=-1)
    {
        geom_mesh.Triangluate_Mesh_Face(f_selected.GetID());
        geom_mesh.create();
        drawFaceBorder(f_selected.GetID());
        emit_geom_signal();
        update();
    }
    else
        QMessageBox::information(NULL,"Note","Please select a face");

}
void MyGL::Subdivison()
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot subdivide the mesh in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    if(Subdivison_times>3)
    {
        QMessageBox::information(NULL,"Note","Subdivision times limited");
        return;
    }
    initialize_draw_mode();
    geom_mesh.Mesh_Subdivison();
    geom_mesh.create();
    emit_geom_signal();
    update();
    Subdivison_times++;


}

void MyGL::Extrude_Face()
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot extrude face in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    if(f_selected.GetID()!=-1)
    {
        geom_mesh.Mesh_Face_Extrude(f_selected.GetID(),0.2f);
        geom_mesh.create();
        drawFaceBorder(f_selected.GetID());
        emit_geom_signal();
        update();
    }
    else
        QMessageBox::information(NULL,"Note","Please select a face");
}
void MyGL::ReInitialize()
{
    geom_mesh.clearmesh();
//    geom_mesh.create_cube_mesh();
    initialize_draw_mode();
    skeleton_mode=false;
    draw_joint=false;
    emit_geom_signal();
    update();
}
void MyGL::Planarity_test()
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot use Planarity_test in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    if(f_selected.GetID()!=-1)
    {
        bool Planarity=geom_mesh.Planarity_test(f_selected.GetID());
        if(!Planarity)
        {
            QMessageBox::information(NULL,"Test Result","The face is not planar.");
            geom_mesh.Triangluate_Mesh_Face(f_selected.GetID());
            geom_mesh.create();
            drawFaceBorder(f_selected.GetID());
            emit_geom_signal();
            update();
        }
        else
            QMessageBox::information(NULL,"Test Result","The face is planar.");

    }
    else
        QMessageBox::information(NULL,"Note","Please select a face");
}

void MyGL::Bevel_Face()
{
    if(skinning_mode)
    {
        QMessageBox::information\
                (NULL,"Note","Cannot use bevel face in skinning mode.Please undo the skinning first(in the main menu)");
        return;
    }
    if(f_selected.GetID()!=-1)
    {
        geom_mesh.Bevel_Face(f_selected.GetID());
        geom_mesh.create();
        drawFaceBorder(f_selected.GetID());
        emit_geom_signal();
        update();
    }
    else
        QMessageBox::information(NULL,"Note","Please select a face");


}

void MyGL::Linear_Skinning()
{
    if(!skeleton_mode)
    {
        QMessageBox::information(NULL,"Note","Please load a skeleton first");
        return;
    }
    else
    {
        if(geom_mesh.Empty())
        {
            QMessageBox::information(NULL,"Note","Please load a mesh obj");
            return;
        }
        else
        {
            for(int i=0;i<geom_mesh.Get_Vertex_num();i++)
            {
                glm::vec3 v_pos=geom_mesh.Get_Mesh_Vertex(i).GetPosition();
                int Joint_ID1=0,Joint_ID2=1;
                float distance1=skeleton_joints[0].Joint_distance(v_pos),\
                        distance2=skeleton_joints[1].Joint_distance(v_pos);
                for(int j=2;j<skeleton_joints.size();j++)
                {
                    float d=skeleton_joints[j].Joint_distance(v_pos);
                    if(d<distance1)
                    {
                        distance1=d;
                        Joint_ID1=j;
                        continue;
                    }
                    if(d<distance2)
                    {
                        distance2=d;
                        Joint_ID2=j;
                        continue;
                    }
                }
                geom_mesh.SetVertexJoint(i,Joint_ID1);
                geom_mesh.SetVertexJoint(i,Joint_ID2);
                geom_mesh.SetVertexJointWeight(i,1-distance1/(distance1+distance2));
                geom_mesh.SetVertexJointWeight(i,1-distance2/(distance1+distance2));

            }
            geom_mesh.create();
            SetSkinningMatrix();
            QMessageBox::information(NULL,"Note","Skinning Completed");

        }
    }
}

void MyGL::SetSkinningMatrix()
{
    if(skinning_mode)
    {
        std::vector<glm::mat4>BindMatrix;
        std::vector<glm::mat4>OverallTransformation;
        for(int i=0;i<skeleton_joints.size();i++)
        {
            BindMatrix.push_back(skeleton_joints[i].GetBindMatrix());
            OverallTransformation.push_back(skeleton_joints[i].GetOverallTransformation());

        }
        prog_skeleton.SetBindMatrix(BindMatrix);
        prog_skeleton.SetOverallTransformation(OverallTransformation);
    }

}

void MyGL::SetTreeSelected(QTreeWidgetItem *node, int n)
{   
    for(int i=0;i<skeleton_joints.size();i++)
    {
        if(node->text(n)==skeleton_joints[i].GetName())
        {
            draw_joint=true;
            glm::mat4 m=skeleton_joints[i].GetOverallTransformation();
            Selected_Joint.SetID(skeleton_joints[i].Get_Joint_ID());
            Selected_Joint.SetColor(glm::vec3(1,1,0));
            Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));
            Selected_Joint.create();
        }

    }
    update();
}

void MyGL::X_Rotation_Add()
{
    int id=Selected_Joint.GetID();

    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::quat q0=skeleton_joints[id].GetRotation();
    glm::quat q_X(cos(2.5/360*M_PI),sin(2.5/360*M_PI),0,0);//local
    glm::quat q_total=q0*q_X;
    skeleton_joints[id].SetRotation(q_total);
//    geom_mesh.create();
    SetSkinningMatrix();


    update();



}
void MyGL::X_Rotation_Minus()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::quat q0=skeleton_joints[id].GetRotation();
    glm::quat q_X(cos(-2.5/360*M_PI),sin(-2.5/360*M_PI),0,0);//local
    glm::quat q_total=q0*q_X;

    skeleton_joints[id].SetRotation(q_total);
    update();

}

void MyGL::Y_Rotation_Add()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::quat q0=skeleton_joints[id].GetRotation();
    glm::quat q_Y(cos(2.5/360*M_PI),0,sin(2.5/360*M_PI),0);//local
    glm::quat q_total=q0*q_Y;

    skeleton_joints[id].SetRotation(q_total);
    update();

}
void MyGL::Y_Rotation_Minus()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::quat q0=skeleton_joints[id].GetRotation();
    glm::quat q_Y(cos(-2.5/360*M_PI),0,sin(-2.5/360*M_PI),0);//local
    glm::quat q_total=q0*q_Y;

    skeleton_joints[id].SetRotation(q_total);
    update();

}

void MyGL::Z_Rotation_Add()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::quat q0=skeleton_joints[id].GetRotation();
    glm::quat q_Z(cos(2.5/360*M_PI),0,0,sin(2.5/360*M_PI));//local
    glm::quat q_total=q0*q_Z;

    skeleton_joints[id].SetRotation(q_total);
    update();

}
void MyGL::Z_Rotation_Minus()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::quat q0=skeleton_joints[id].GetRotation();
    glm::quat q_Z(cos(-2.5/360*M_PI),0,0,sin(-2.5/360*M_PI));//local
    glm::quat q_total=q0*q_Z;

    skeleton_joints[id].SetRotation(q_total);
    update();

}


void MyGL::X_Translation_Add()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::vec3 pos=skeleton_joints[id].GetPosition();
    pos[0]+=0.2;
    skeleton_joints[id].SetPosition(pos);
    glm::mat4 m=skeleton_joints[id].GetOverallTransformation();
    Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));

    Selected_Joint.create();
    update();

}
void MyGL::X_Translation_Minus()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::vec3 pos=skeleton_joints[id].GetPosition();
    pos[0]-=0.2;

    skeleton_joints[id].SetPosition(pos);
    glm::mat4 m=skeleton_joints[id].GetOverallTransformation();
    Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));
    Selected_Joint.create();
    update();
}

void MyGL::Y_Translation_Add()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::vec3 pos=skeleton_joints[id].GetPosition();
    pos[1]+=0.2;

    skeleton_joints[id].SetPosition(pos);
    glm::mat4 m=skeleton_joints[id].GetOverallTransformation();
    Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));
    Selected_Joint.create();
    update();

}
void MyGL::Y_Translation_Minus()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::vec3 pos=skeleton_joints[id].GetPosition();
    pos[1]-=0.2;

    skeleton_joints[id].SetPosition(pos);
    glm::mat4 m=skeleton_joints[id].GetOverallTransformation();
    Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));
    Selected_Joint.create();
    update();

}

void MyGL::Z_Translation_Add()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::vec3 pos=skeleton_joints[id].GetPosition();
    pos[2]+=0.2;

    skeleton_joints[id].SetPosition(pos);
    glm::mat4 m=skeleton_joints[id].GetOverallTransformation();
    Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));
    Selected_Joint.create();
    update();

}
void MyGL::Z_Translation_Minus()
{
    int id=Selected_Joint.GetID();
    if(id==-1)
    {
        QMessageBox::information(NULL,"Note","Please Select a Joint from the treewidget first");
        return;
    }
    glm::vec3 pos=skeleton_joints[id].GetPosition();
    pos[2]-=0.2;

    skeleton_joints[id].SetPosition(pos);
    glm::mat4 m=skeleton_joints[id].GetOverallTransformation();
    Selected_Joint.SetVerts(glm::vec3(m[3][0],m[3][1],m[3][2]));
    Selected_Joint.create();
    update();

}


