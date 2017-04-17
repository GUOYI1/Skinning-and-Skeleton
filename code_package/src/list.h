#ifndef LIST_H
#define LIST_H

#endif // LIST_H
#include <QListWidgetItem>
#include<QObject>

class Vertex_List:public QListWidget
{
    Q_OBJECT
public:
    Vertex_List(QWidget* parent = NULL) : QListWidget(parent){}
private slots:
    void Show_VertexItems(int v_num,int selected_ID);
    //void Add_VertexListItems();
    void SetSelected_item(int v_ID);

signals:
    void List_clear();


};

class Face_List:public QListWidget
{
    Q_OBJECT
public:
    Face_List(QWidget* parent = NULL) : QListWidget(parent){}
private slots:
    void Show_FaceItems(int f_num,int selected_ID);
    void SetSelected_item(int f_ID);
signals:
    void List_clear();

};


class HalfEdge_List:public QListWidget
{
    Q_OBJECT
public:
    HalfEdge_List(QWidget* parent = NULL) : QListWidget(parent){}
private slots:
    void Show_HalfEdgeItems(int l_num,int selected_ID);
    void SetSelected_item(int l_ID);
signals:
    void List_clear();

};
