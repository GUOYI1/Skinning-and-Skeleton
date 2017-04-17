#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/cylinder.h>
#include <scene/sphere.h>
#include <scene/temp_face.h>
#include <scene/temp_vertex.h>
#include <scene/temp_line.h>
#include"mesh.h"
#include"joint.h"
#include "camera.h"

#include <QListWidgetItem>
#include<QObject>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public GLWidget277
{
    Q_OBJECT
private:
    Cylinder geom_cylinder;// The instance of a unit cylinder we can use to render any cylinder
    Sphere geom_sphere;// The instance of a unit sphere we can use to render any sphere
    Mesh geom_mesh; //The mesh for geometries
    std::vector<Joint> skeleton_joints;

    temp_vertex Selected_Joint;
    temp_vertex joint_points;
    temp_line bone;
    temp_line wireframe;

    temp_vertex v_selected;//The highlight vertex that is selected
    temp_line l_selected;//The highlight edge that is selected
    temp_face_border f_selected;//The highlight face that is selected


    ShaderProgram prog_lambert;// A shader program that uses lambertian reflection
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)
    ShaderProgram prog_skeleton;//A shader program that used to render the skinning cow.


    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
                // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera gl_camera;

    /// Timer linked to timerUpdate(). Fires approx. 60 times per second
    QTimer timer;

    //draw mode flags
    bool draw_point;
    bool draw_edge;
    bool draw_face;
    bool draw_joint;
    bool skeleton_mode;
    bool skinning_mode;

    int Subdivison_times;
    int timeCount;
    int renderMode;


public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void initializeMesh(const std::vector<glm::vec3>&v,\
                        const std::vector<int>& v_indice,\
                        const std::vector<glm::vec3> face_color,\
                        const std::vector<int>& face_sides);
    void initializeSkeleton(const std::vector<QString>&name,
                            const std::vector<glm::vec3> &pos,\
                            const std::vector<glm::quat>&rot,\
                            const std::vector<int> &parent_ID);
    void initialize_seleced_ID();
    void initialize_draw_mode();
    void resizeGL(int w, int h);
    void emit_geom_signal();
    void drawFaceBorder(int id);
    void drawEdge(int id);
    void drawVertex(int id);
    void drawVertex_topography(QString s);
    void drawFace_topography(QString s);
    void drawHalfEdge_topography(QString s);
    void drawSkeleton();
    int Get_mesh_vertex_num();
    int Get_mesh_halfedge_num();
    int Get_mesh_face_num();
    void paintGL();
    void SetRenderMode_Value(int mode);
    void UndoSkinningMode();

    //Planarity test
    void Planarity_test();
    void Bevel_Face();

    //
    void Linear_Skinning();
    void SetSkinningMatrix();

protected:
    void keyPressEvent(QKeyEvent *e);
signals:
    void Show_ListItem_v(int v_num,int selected_ID);
    void Show_ListItem_f(int f_num,int selected_ID);
    void Show_ListItem_l(int l_num,int selected_ID);
    void Show_Spinbox_vx(float vx);
    void Show_Spinbox_vy(float vy);
    void Show_Spinbox_vz(float vz);
    void Show_Spinbox_color_R(float r);
    void Show_Spinbox_color_G(float g);
    void Show_Spinbox_color_B(float b);
    void Spinbox_disable();
    void Show_Tree(QTreeWidgetItem* root);

    void vertex_selected(int v_ID);
    void halfedge_selected(int l_ID);
    void face_selected(int f_ID);
private slots:
    /// Slot that gets called ~60 times per second
    void timerUpdate();
    void highlight_vertex(QListWidgetItem* v_Item);
    void highlight_edge(QListWidgetItem* l_Item);
    void highlight_face(QListWidgetItem* f_Item);
    void vert_x_change(double vx);
    void vert_y_change(double vy);
    void vert_z_change(double vz);
    void face_color_R_change(double color_R);
    void face_color_G_change(double color_G);
    void face_color_B_change(double color_B);
    void Add_vertex();
    void Triangulate_face();
    void Subdivison();
    void Extrude_Face();
    void Skinning_Skeleton();
    void ReInitialize();

    //Tree
    void SetTreeSelected(QTreeWidgetItem* node,int n);

    //Joint Transformation
    void X_Rotation_Add();
    void X_Rotation_Minus();
    void Y_Rotation_Add();
    void Y_Rotation_Minus();
    void Z_Rotation_Add();
    void Z_Rotation_Minus();

    void X_Translation_Add();
    void X_Translation_Minus();
    void Y_Translation_Add();
    void Y_Translation_Minus();
    void Z_Translation_Add();
    void Z_Translation_Minus();
};


#endif // MYGL_H
