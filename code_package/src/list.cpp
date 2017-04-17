#include"list.h"

void Vertex_List::Show_VertexItems(int v_num,int selected_ID)
{
    clear();
    for(int i=0;i<v_num;i++)
    {
        addItem(QString::number(i,10));
    }
    if(selected_ID!=-1)
    {
        setCurrentItem(item(selected_ID));
    }
}
void Vertex_List::SetSelected_item(int v_ID)
{
    if(v_ID!=-1)
        setCurrentItem(item(v_ID));
}

void Face_List::Show_FaceItems(int f_num,int selected_ID)
{
    clear();
    for(int i=0;i<f_num;i++)
    {
        addItem(QString::number(i,10));
    }
    if(selected_ID!=-1)
    {
        setCurrentItem(item(selected_ID));
    }


}
void Face_List::SetSelected_item(int f_ID)
{
    if(f_ID!=-1)
        setCurrentItem(item(f_ID));
}

void HalfEdge_List::Show_HalfEdgeItems(int l_num,int selected_ID)
{
    clear();
    for(int i=0;i<l_num;i++)
    {
        addItem(QString::number(i,10));
    }
    if(selected_ID!=-1)
    {
        setCurrentItem(item(selected_ID));
    }
}
void HalfEdge_List::SetSelected_item(int l_ID)
{
    if(l_ID!=-1)
        setCurrentItem(item(l_ID));
}
