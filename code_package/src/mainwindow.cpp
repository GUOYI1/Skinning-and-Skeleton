#define _USE_MATH_DEFINES
#include "mainwindow.h"
#include <ui_mainwindow.h>
#include "cameracontrolshelp.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVarLengthArray>
#include<iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include<math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionLoad_Obj_triggered()
{
    std::vector<glm::vec3> vertex;
    std::vector<int> index;
    std::vector<glm::vec3> face_color;
    std::vector<int> face_sides;
    //Note:We don't use the value of uv and normal read from OBJ file for this assignment,
    //For normals, we'd better calculate them by ourselves,since they are not absolutely
    //accurate.I write this just to show that we can read uv and normals from obj file if it
    //necessary.

    std::vector<glm::vec3> normals_read;
    std::vector<glm::vec3>face_normals;
    std::vector<glm::vec2>uv_read;
    std::vector<glm::vec2>uv_coords;


    QString filename = QFileDialog::getOpenFileName\
             (0, QString("Load Obj File"),\
              QDir::currentPath().append(QString("../..")),\
              QString("*.obj"));
    if (filename.isEmpty())
         return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
           return;
    QTextStream in(&file);

    while (!in.atEnd())
    {
         QString input = in.readLine();
         if (input.isEmpty() || input[0] == '#')
              continue;
         QTextStream ts(&input);
         QString id;
         ts>>id;
         if(id=="v")
         {
             glm::vec3 p;
             QString vert;
             for(int i=0;i<3;i++)
             {
                 ts>>vert;
                 p[i]=vert.toFloat();
             }
             vertex.push_back(p);
         }
         else if(id=="vt")
         {
             glm::vec2 uv;
             QString uv_value;
             for(int i=0;i<2;i++)
             {
                 ts>>uv_value;
                 uv[i]=uv_value.toFloat();
             }
             uv_read.push_back(uv);

         }
         else if(id=="vn")
         {
             glm::vec3 n;
             QString normal_value;
             for(int i=0;i<3;i++)
             {
                 ts>>normal_value;
                 n[i]=normal_value.toFloat();
             }
             normals_read.push_back(n);
         }


         else if(id=="f")
         {
             int sides=0;
             while (!ts.atEnd())
             {
                 QString index_info;
                 ts >> index_info;
                 int vertexIndex = index_info.split('/').value(0).toInt()-1;
                 int uvIndex=index_info.split('/').value(2).toInt()-1;
                 int normalIndex=index_info.split('/').value(2).toInt()-1;

                 face_normals.push_back(normals_read[normalIndex]);
                 uv_coords.push_back(uv_read[uvIndex]);
                 index.push_back(vertexIndex);
                 sides++;
             }
             face_sides.push_back(sides);

         }

    }
    for(int i=0;i<index.size();i++)
        face_color.push_back(glm::vec3(float(qrand()%255)/255.0f,float(qrand()%255)/255.0f,float(qrand()%255)/255.0f));//Default color

    ui->mygl->initializeMesh(vertex,index,face_color,face_sides);
}
void Jsonread_Iteration(std::vector<QString>&joint_name,std::vector<glm::vec3> &joint_pos,\
                        std::vector<glm::quat>&joint_rot,std::vector<int> &joint_parent_ID,\
                        int joint_p_ID, QJsonArray joint_objects)
{
    for(int i=0;i<joint_objects.size();i++)
    {
        QJsonObject obj = joint_objects[i].toObject();
        QString name = obj["name"].toString();
        glm::vec3 pos;
        glm::quat rot;

        QJsonArray pos_read = obj["pos"].toArray();
        for(int i=0;i<pos_read.size();i++)
            pos[i]=pos_read[i].toDouble();


        QJsonArray rot_read = obj["rot"].toArray();
        double theta=rot_read[0].toDouble()/M_PI*180;
        glm::vec3 axis(rot_read[1].toDouble(),rot_read[2].toDouble(),rot_read[3].toDouble());
        glm::normalize(axis);

        rot.w=cos(theta/2);
        rot.x=sin(theta/2)*axis[0];
        rot.y=sin(theta/2)*axis[1];
        rot.z=sin(theta/2)*axis[2];


        QJsonArray child = obj["children"].toArray();
        joint_name.push_back(name);
        joint_pos.push_back(pos);
        joint_rot.push_back(rot);
        joint_parent_ID.push_back(joint_p_ID);
        Jsonread_Iteration(joint_name,joint_pos,joint_rot,joint_parent_ID,joint_name.size()-1,child);

    }


}
void MainWindow::on_actionLoad_Json_triggered()
{
    std::vector<QString>joint_name;
    std::vector<glm::vec3>joint_pos;
    std::vector<glm::quat>joint_rot;
    std::vector<int> joint_parent_ID;
    joint_name.reserve(100);
    joint_pos.reserve(100);
    joint_rot.reserve(100);
    joint_parent_ID.reserve(100);
    QString filename = QFileDialog::getOpenFileName(0, QString("Load josn File"), QDir::currentPath().append(QString("../..")), QString("*.json"));
    if (filename.isEmpty())
        return;
//    int i = filename.length() - 1;
//    while(QString::compare(filename.at(i), QChar('/')) != 0)
//    {
//        i--;
//    }
//   QStringRef local_path = filename.leftRef(i+1);
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Could not open the JSON file.");
        return;
    }
    QByteArray file_data = file.readAll();
    QJsonDocument jdoc(QJsonDocument::fromJson(file_data));
    QJsonObject obj  = jdoc.object()["root"].toObject();



    QString name = obj["name"].toString();
    glm::vec3 pos;
    glm::quat rot;

    QJsonArray pos_read = obj["pos"].toArray();
    for(int i=0;i<pos_read.size();i++)
        pos[i]=pos_read[i].toDouble();


    QJsonArray rot_read = obj["rot"].toArray();
    double theta=rot_read[0].toDouble()/M_PI*180;
    glm::vec3 axis(rot_read[1].toDouble(),rot_read[2].toDouble(),rot_read[3].toDouble());
    glm::normalize(axis);
    rot.w=(cos(theta/2));
    rot.x=(sin(theta/2)*axis[0]);
    rot.y=(sin(theta/2)*axis[1]);
    rot.z=(sin(theta/2)*axis[2]);


    QJsonArray child = obj["children"].toArray();
    joint_name.push_back(name);
    joint_pos.push_back(pos);
    joint_rot.push_back(rot);
    joint_parent_ID.push_back(-1);


    Jsonread_Iteration(joint_name,joint_pos,joint_rot,joint_parent_ID,joint_name.size()-1,child);

    ui->mygl->initializeSkeleton(joint_name,joint_pos,joint_rot,joint_parent_ID);
}

void MainWindow::on_actionRegular_Form_triggered()
{
    ui->mygl->SetRenderMode_Value(0);
}

void MainWindow::on_actionColor_Fun_triggered()
{
    ui->mygl->SetRenderMode_Value(1);
}

void MainWindow::on_actionShape_Fun_triggered()
{
    ui->mygl->SetRenderMode_Value(2);
}

void MainWindow::on_actionMixture_Fun_triggered()
{
    ui->mygl->SetRenderMode_Value(3);
}
void MainWindow::on_actionPlanarity_test_triggered()
{
    ui->mygl->Planarity_test();

}
void MainWindow::on_actionBevel_Face_triggered()
{
    ui->mygl->Bevel_Face();
}
void MainWindow::on_actionSharp_Current_Item_triggered()
{

}

void MainWindow::on_actionUndo_skinning_triggered()
{
    ui->mygl->UndoSkinningMode();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

