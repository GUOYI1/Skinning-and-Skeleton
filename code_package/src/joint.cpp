#include<joint.h>
#include<iostream>
Joint::Joint():Name("No name"),Parent(NULL){}
Joint::Joint(QString name):Name(name),Parent(NULL)
{
     QTreeWidgetItem::setText(0, name);
}

void Joint::Set_Joint_ID(int n)
{
    Joint_ID=n;
}

int Joint::Get_Joint_ID()
{
    return Joint_ID;
}

void Joint::SetParent(Joint *p)
{
    Parent=p;
}
Joint* Joint::GetParent()
{
    return Parent;
}
void Joint::Joint_Initialize(glm::vec3 pos, glm::quat orientation, Joint *parent)
{
    SetPosition(pos);
    SetRotation(orientation);
    SetParent(parent);
    SetBindMatrix();
}
QString Joint::GetName()
{
    return Name;
}

void Joint::AddChild(QTreeWidgetItem* Child)
{
    QTreeWidgetItem::addChild(Child);
    Children.push_back((Joint*)Child);
}

Joint* Joint::GetChild(int n)
{
    return Children[n];
}

void Joint::SetPosition(glm::vec3 pos)
{
    Position=pos;
}
glm::vec3 Joint::GetPosition()
{
    return Position;
}
void Joint::SetRotation(glm::quat q)
{
    Rotation=q;
}
glm::quat Joint::GetRotation()
{
    return Rotation;
}

void Joint::SetBindMatrix()
{
    Bind_Matrix=GetOverallTransformation();
    glm::mat3 R_Transpose;
    glm::vec3 pos;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            R_Transpose[i][j]=Bind_Matrix[j][i];
    for(int i=0;i<3;i++)
        pos[i]=Bind_Matrix[3][i];
    pos=-R_Transpose*pos;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            Bind_Matrix[i][j]=R_Transpose[i][j];
    for(int i=0;i<3;i++)
    {
        Bind_Matrix[3][i]=pos[i];
        Bind_Matrix[i][3]=0;
    }
    Bind_Matrix[3][3]=1;
}

glm::mat4 Joint::GetBindMatrix()
{
    return Bind_Matrix;
}

glm::mat4 Joint::GetLocalTransformation()
{
    return(ToTransformationMatrix(Rotation,Position));

}
glm::mat4 Joint::GetOverallTransformation()
{
    glm::mat4 OverallTransformation;
    Joint* p=this;
    if(p->GetParent())
        OverallTransformation=p->GetParent()->GetOverallTransformation()*GetLocalTransformation();
    else
        OverallTransformation=GetLocalTransformation();
    return OverallTransformation;
}
glm::mat4 ToTransformationMatrix(glm::quat Q,glm::vec3 pos)
{

    glm::mat4 OverallTransformation;
    glm::mat4 trans = glm::translate(glm::mat4(), pos);
    glm::mat4 rotation = glm::toMat4(Q);
    OverallTransformation=trans*rotation;
    return OverallTransformation;
}

float Joint::Joint_distance(glm::vec3 p)
{
    glm::mat4 T=GetOverallTransformation();
    glm::vec3 joint_point(T[3][0],T[3][1],T[3][2]);
    float distance=glm::length(joint_point-p);
    return distance;
}

