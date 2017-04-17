#ifndef MYTREE_H
#define MYTREE_H

#endif // MYTREE_H

#include <QTreeWidgetItem>
#include<QObject>
class MyTree:public QTreeWidget
{
    Q_OBJECT
public:
    MyTree(QWidget* parent = NULL) : QTreeWidget(parent){}
public slots:
    void Show_Tree_Widget(QTreeWidgetItem* root);

};

