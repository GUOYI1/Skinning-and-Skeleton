#pragma once
#ifndef JOINT
#define JOINT

#endif // JOINT
#include<QImage>
#include<QString>
#include <la.h>
#include <utils.h>
#include"drawable.h"
#include <QTreeWidgetItem>
class Joint:public QTreeWidgetItem
{
protected:
    QString Name;
    Joint* Parent;
    std::vector<Joint*> Children;
    glm::vec3 Position;
    glm::quat Rotation;
    glm::mat4 Bind_Matrix;
    int Joint_ID;

public:
    Joint();
    Joint(QString name);
    void Set_Joint_ID(int n);
    int Get_Joint_ID();
    void Joint_Initialize(glm::vec3 pos,glm::quat orientation,Joint* parent);
    void SetParent(Joint* p);
    Joint* GetParent();
    void AddChild(QTreeWidgetItem*Child);
    Joint* GetChild(int n);
    void SetPosition(glm::vec3 pos);
    glm::vec3 GetPosition();
    void SetRotation(glm::quat q);
    glm::quat GetRotation();
    void SetBindMatrix();

    QString GetName();
    glm::mat4 GetBindMatrix();
    glm::mat4 GetLocalTransformation();
    glm::mat4 GetOverallTransformation();
    float Joint_distance(glm::vec3 p);

};
glm::mat4 ToTransformationMatrix(glm::quat q,glm::vec3 pos);



