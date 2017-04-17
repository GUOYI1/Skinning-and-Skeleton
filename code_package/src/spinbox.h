#ifndef SPINBOX_H
#define SPINBOX_H

#endif // SPINBOX_H
#include<QListWidgetItem>
#include<QSpinBox>
#include<QObject>

//verts spin box
class spinbox_vx:public QDoubleSpinBox
{
    Q_OBJECT
private slots:
    void Show_Vx_value(float vx);
    void box_disable();


public:
    spinbox_vx(QWidget *parent = 0):QDoubleSpinBox(parent){}
};


class spinbox_vy:public QDoubleSpinBox
{
    Q_OBJECT
private slots:
    void Show_Vy_value(float vy);
    void box_disable();


public:
    spinbox_vy(QWidget *parent = 0):QDoubleSpinBox(parent){}


};


class spinbox_vz:public QDoubleSpinBox
{
    Q_OBJECT
private slots:
    void Show_Vz_value(float vz);
    void box_disable();


public:
    spinbox_vz(QWidget *parent = 0):QDoubleSpinBox(parent){}


};


//color spinbox
class spinbox_color_R:public QDoubleSpinBox
{
    Q_OBJECT
private slots:
    void Show_color_R(float r);
    void box_disable();


public:
    spinbox_color_R(QWidget *parent = 0):QDoubleSpinBox(parent){}
};



class spinbox_color_G:public QDoubleSpinBox
{
    Q_OBJECT
private slots:
    void Show_color_G(float g);
    void box_disable();

public:
    spinbox_color_G(QWidget *parent = 0):QDoubleSpinBox(parent){}
};



class spinbox_color_B:public QDoubleSpinBox
{
    Q_OBJECT
private slots:
    void Show_color_B(float b);
    void box_disable();

public:
    spinbox_color_B(QWidget *parent = 0):QDoubleSpinBox(parent){}
};

