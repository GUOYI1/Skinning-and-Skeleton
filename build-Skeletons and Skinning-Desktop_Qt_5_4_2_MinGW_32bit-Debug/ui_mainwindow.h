/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mytree.h>
#include "list.h"
#include "mygl.h"
#include "spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionCamera_Controls;
    QAction *actionLoad_Obj;
    QAction *actionColor_Fun;
    QAction *actionShape_Fun;
    QAction *actionRegular_Form;
    QAction *actionMixture_Fun;
    QAction *actionPlanarity_test;
    QAction *actionInsert_edge_loop;
    QAction *actionBevel_Face;
    QAction *actionSharp_Current_Item;
    QAction *actionLoad_Json;
    QAction *actionUndo_skinning;
    QWidget *centralWidget;
    MyGL *mygl;
    HalfEdge_List *listWidget;
    Vertex_List *listWidget_2;
    spinbox_vy *doubleSpinBox;
    spinbox_vz *doubleSpinBox_2;
    spinbox_vx *doubleSpinBox_3;
    spinbox_color_R *doubleSpinBox_4;
    spinbox_color_B *doubleSpinBox_5;
    spinbox_color_G *doubleSpinBox_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    Face_List *listWidget_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    MyTree *treeWidget;
    QLabel *label_10;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuRenderModer;
    QMenu *menuOperation;
    QMenu *menuSkinningMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1057, 553);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionCamera_Controls = new QAction(MainWindow);
        actionCamera_Controls->setObjectName(QStringLiteral("actionCamera_Controls"));
        actionLoad_Obj = new QAction(MainWindow);
        actionLoad_Obj->setObjectName(QStringLiteral("actionLoad_Obj"));
        actionColor_Fun = new QAction(MainWindow);
        actionColor_Fun->setObjectName(QStringLiteral("actionColor_Fun"));
        actionShape_Fun = new QAction(MainWindow);
        actionShape_Fun->setObjectName(QStringLiteral("actionShape_Fun"));
        actionRegular_Form = new QAction(MainWindow);
        actionRegular_Form->setObjectName(QStringLiteral("actionRegular_Form"));
        actionMixture_Fun = new QAction(MainWindow);
        actionMixture_Fun->setObjectName(QStringLiteral("actionMixture_Fun"));
        actionPlanarity_test = new QAction(MainWindow);
        actionPlanarity_test->setObjectName(QStringLiteral("actionPlanarity_test"));
        actionInsert_edge_loop = new QAction(MainWindow);
        actionInsert_edge_loop->setObjectName(QStringLiteral("actionInsert_edge_loop"));
        actionBevel_Face = new QAction(MainWindow);
        actionBevel_Face->setObjectName(QStringLiteral("actionBevel_Face"));
        actionSharp_Current_Item = new QAction(MainWindow);
        actionSharp_Current_Item->setObjectName(QStringLiteral("actionSharp_Current_Item"));
        actionLoad_Json = new QAction(MainWindow);
        actionLoad_Json->setObjectName(QStringLiteral("actionLoad_Json"));
        actionUndo_skinning = new QAction(MainWindow);
        actionUndo_skinning->setObjectName(QStringLiteral("actionUndo_skinning"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setGeometry(QRect(11, 11, 618, 432));
        listWidget = new HalfEdge_List(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(650, 110, 111, 111));
        listWidget_2 = new Vertex_List(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(780, 110, 121, 111));
        doubleSpinBox = new spinbox_vy(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setEnabled(false);
        doubleSpinBox->setGeometry(QRect(850, 10, 61, 31));
        doubleSpinBox->setMinimum(-1000);
        doubleSpinBox->setMaximum(1000);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox_2 = new spinbox_vz(centralWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setEnabled(false);
        doubleSpinBox_2->setGeometry(QRect(990, 10, 61, 31));
        doubleSpinBox_2->setMinimum(-1000);
        doubleSpinBox_2->setMaximum(1000);
        doubleSpinBox_2->setSingleStep(0.01);
        doubleSpinBox_3 = new spinbox_vx(centralWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setEnabled(false);
        doubleSpinBox_3->setGeometry(QRect(710, 10, 61, 31));
        doubleSpinBox_3->setMinimum(-1000);
        doubleSpinBox_3->setMaximum(1000);
        doubleSpinBox_3->setSingleStep(0.01);
        doubleSpinBox_4 = new spinbox_color_R(centralWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setEnabled(false);
        doubleSpinBox_4->setGeometry(QRect(710, 50, 61, 31));
        doubleSpinBox_4->setMaximum(1);
        doubleSpinBox_4->setSingleStep(0.01);
        doubleSpinBox_5 = new spinbox_color_B(centralWidget);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setEnabled(false);
        doubleSpinBox_5->setGeometry(QRect(990, 50, 61, 31));
        doubleSpinBox_5->setMaximum(1);
        doubleSpinBox_5->setSingleStep(0.01);
        doubleSpinBox_6 = new spinbox_color_G(centralWidget);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setEnabled(false);
        doubleSpinBox_6->setGeometry(QRect(850, 50, 61, 31));
        doubleSpinBox_6->setMaximum(1);
        doubleSpinBox_6->setSingleStep(0.01);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(650, 20, 54, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(790, 20, 54, 12));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(930, 20, 54, 12));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(650, 60, 54, 12));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(790, 60, 54, 12));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(930, 60, 54, 12));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(670, 90, 71, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(810, 90, 71, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(950, 90, 71, 21));
        listWidget_3 = new Face_List(centralWidget);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(920, 110, 121, 111));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 171, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 50, 171, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 80, 171, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 110, 171, 21));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 390, 161, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 140, 171, 21));
        treeWidget = new MyTree(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(650, 260, 391, 261));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(800, 230, 111, 21));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(550, 450, 31, 31));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(340, 450, 31, 31));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(130, 450, 31, 31));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(130, 490, 31, 31));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(340, 490, 31, 31));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(550, 490, 31, 31));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 460, 121, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 490, 101, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(220, 460, 121, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(220, 490, 101, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(430, 460, 121, 16));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(430, 490, 131, 16));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(160, 450, 31, 31));
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(160, 490, 31, 31));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(370, 450, 31, 31));
        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(370, 490, 31, 31));
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(580, 450, 31, 31));
        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(580, 490, 31, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1057, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuRenderModer = new QMenu(menuBar);
        menuRenderModer->setObjectName(QStringLiteral("menuRenderModer"));
        menuOperation = new QMenu(menuBar);
        menuOperation->setObjectName(QStringLiteral("menuOperation"));
        menuSkinningMode = new QMenu(menuBar);
        menuSkinningMode->setObjectName(QStringLiteral("menuSkinningMode"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuRenderModer->menuAction());
        menuBar->addAction(menuOperation->menuAction());
        menuBar->addAction(menuSkinningMode->menuAction());
        menuFile->addAction(actionLoad_Obj);
        menuFile->addAction(actionLoad_Json);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionCamera_Controls);
        menuRenderModer->addAction(actionRegular_Form);
        menuRenderModer->addAction(actionColor_Fun);
        menuRenderModer->addAction(actionShape_Fun);
        menuRenderModer->addAction(actionMixture_Fun);
        menuOperation->addAction(actionPlanarity_test);
        menuOperation->addAction(actionBevel_Face);
        menuOperation->addAction(actionSharp_Current_Item);
        menuSkinningMode->addAction(actionUndo_skinning);

        retranslateUi(MainWindow);
        QObject::connect(mygl, SIGNAL(Show_ListItem_v(int,int)), listWidget_2, SLOT(Show_VertexItems(int,int)));
        QObject::connect(mygl, SIGNAL(Show_ListItem_f(int,int)), listWidget_3, SLOT(Show_FaceItems(int,int)));
        QObject::connect(mygl, SIGNAL(Show_ListItem_l(int,int)), listWidget, SLOT(Show_HalfEdgeItems(int,int)));
        QObject::connect(listWidget_2, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(highlight_vertex(QListWidgetItem*)));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(highlight_edge(QListWidgetItem*)));
        QObject::connect(listWidget_3, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(highlight_face(QListWidgetItem*)));
        QObject::connect(mygl, SIGNAL(Show_Spinbox_vx(float)), doubleSpinBox_3, SLOT(Show_Vx_value(float)));
        QObject::connect(mygl, SIGNAL(Show_Spinbox_vy(float)), doubleSpinBox, SLOT(Show_Vy_value(float)));
        QObject::connect(mygl, SIGNAL(Show_Spinbox_vz(float)), doubleSpinBox_2, SLOT(Show_Vz_value(float)));
        QObject::connect(mygl, SIGNAL(Show_Spinbox_color_R(float)), doubleSpinBox_4, SLOT(Show_color_R(float)));
        QObject::connect(mygl, SIGNAL(Show_Spinbox_color_G(float)), doubleSpinBox_6, SLOT(Show_color_G(float)));
        QObject::connect(mygl, SIGNAL(Show_Spinbox_color_B(float)), doubleSpinBox_5, SLOT(Show_color_B(float)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), mygl, SLOT(vert_x_change(double)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), mygl, SLOT(vert_y_change(double)));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), mygl, SLOT(vert_z_change(double)));
        QObject::connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), mygl, SLOT(face_color_R_change(double)));
        QObject::connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), mygl, SLOT(face_color_G_change(double)));
        QObject::connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), mygl, SLOT(face_color_B_change(double)));
        QObject::connect(pushButton, SIGNAL(released()), mygl, SLOT(Add_vertex()));
        QObject::connect(pushButton_2, SIGNAL(released()), mygl, SLOT(Triangulate_face()));
        QObject::connect(pushButton_3, SIGNAL(released()), mygl, SLOT(Subdivison()));
        QObject::connect(pushButton_5, SIGNAL(released()), mygl, SLOT(Extrude_Face()));
        QObject::connect(mygl, SIGNAL(halfedge_selected(int)), listWidget, SLOT(SetSelected_item(int)));
        QObject::connect(mygl, SIGNAL(vertex_selected(int)), listWidget_2, SLOT(SetSelected_item(int)));
        QObject::connect(mygl, SIGNAL(face_selected(int)), listWidget_3, SLOT(SetSelected_item(int)));
        QObject::connect(pushButton_4, SIGNAL(released()), mygl, SLOT(ReInitialize()));
        QObject::connect(pushButton_6, SIGNAL(released()), mygl, SLOT(Skinning_Skeleton()));
        QObject::connect(mygl, SIGNAL(Show_Tree(QTreeWidgetItem*)), treeWidget, SLOT(Show_Tree_Widget(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), mygl, SLOT(SetTreeSelected(QTreeWidgetItem*,int)));
        QObject::connect(pushButton_10, SIGNAL(released()), mygl, SLOT(X_Rotation_Add()));
        QObject::connect(pushButton_11, SIGNAL(released()), mygl, SLOT(Y_Rotation_Add()));
        QObject::connect(pushButton_12, SIGNAL(released()), mygl, SLOT(Z_Rotation_Add()));
        QObject::connect(pushButton_9, SIGNAL(released()), mygl, SLOT(X_Translation_Add()));
        QObject::connect(pushButton_8, SIGNAL(released()), mygl, SLOT(Y_Translation_Add()));
        QObject::connect(pushButton_7, SIGNAL(released()), mygl, SLOT(Z_Translation_Add()));
        QObject::connect(pushButton_13, SIGNAL(released()), mygl, SLOT(X_Translation_Minus()));
        QObject::connect(pushButton_14, SIGNAL(released()), mygl, SLOT(X_Rotation_Minus()));
        QObject::connect(pushButton_15, SIGNAL(released()), mygl, SLOT(Y_Translation_Minus()));
        QObject::connect(pushButton_16, SIGNAL(released()), mygl, SLOT(Y_Rotation_Minus()));
        QObject::connect(pushButton_17, SIGNAL(released()), mygl, SLOT(Z_Translation_Minus()));
        QObject::connect(pushButton_18, SIGNAL(released()), mygl, SLOT(Z_Rotation_Minus()));
        QObject::connect(mygl, SIGNAL(Spinbox_disable()), doubleSpinBox_3, SLOT(box_disable()));
        QObject::connect(mygl, SIGNAL(Spinbox_disable()), doubleSpinBox, SLOT(box_disable()));
        QObject::connect(mygl, SIGNAL(Spinbox_disable()), doubleSpinBox_2, SLOT(box_disable()));
        QObject::connect(mygl, SIGNAL(Spinbox_disable()), doubleSpinBox_4, SLOT(box_disable()));
        QObject::connect(mygl, SIGNAL(Spinbox_disable()), doubleSpinBox_6, SLOT(box_disable()));
        QObject::connect(mygl, SIGNAL(Spinbox_disable()), doubleSpinBox_5, SLOT(box_disable()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGLDemo", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionCamera_Controls->setText(QApplication::translate("MainWindow", "Camera Controls", 0));
        actionLoad_Obj->setText(QApplication::translate("MainWindow", "Load Obj", 0));
        actionColor_Fun->setText(QApplication::translate("MainWindow", "Color_Fun", 0));
        actionShape_Fun->setText(QApplication::translate("MainWindow", "Shape_Fun", 0));
        actionRegular_Form->setText(QApplication::translate("MainWindow", "Regular_Form", 0));
        actionMixture_Fun->setText(QApplication::translate("MainWindow", "Mixture_Fun", 0));
        actionPlanarity_test->setText(QApplication::translate("MainWindow", "Planarity test", 0));
        actionInsert_edge_loop->setText(QApplication::translate("MainWindow", "Insert edge loop", 0));
        actionBevel_Face->setText(QApplication::translate("MainWindow", "Bevel Face", 0));
        actionSharp_Current_Item->setText(QApplication::translate("MainWindow", "Sharp Current Item", 0));
        actionLoad_Json->setText(QApplication::translate("MainWindow", "Load Json", 0));
        actionUndo_skinning->setText(QApplication::translate("MainWindow", "Undo skinning", 0));
        label->setText(QApplication::translate("MainWindow", "Vertex_X", 0));
        label_2->setText(QApplication::translate("MainWindow", "Vertex_Y", 0));
        label_3->setText(QApplication::translate("MainWindow", "Vertex_Z", 0));
        label_4->setText(QApplication::translate("MainWindow", "R_Color", 0));
        label_5->setText(QApplication::translate("MainWindow", "G_Color", 0));
        label_6->setText(QApplication::translate("MainWindow", "B_Color", 0));
        label_7->setText(QApplication::translate("MainWindow", "HalfEdge_ID", 0));
        label_8->setText(QApplication::translate("MainWindow", "Vertex_ID", 0));
        label_9->setText(QApplication::translate("MainWindow", "Face_ID", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add Vertex", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Triangulate Face", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Catmull-Clark subdivision ", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Extrude Face", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "ReInitialize", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Linear Skeleton", 0));
        label_10->setText(QApplication::translate("MainWindow", "Skeleton Structure", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "+", 0));
        label_11->setText(QApplication::translate("MainWindow", "Joint_X_Translation", 0));
        label_12->setText(QApplication::translate("MainWindow", "Joint_X_Rotation", 0));
        label_13->setText(QApplication::translate("MainWindow", "Joint_Y_Translation", 0));
        label_14->setText(QApplication::translate("MainWindow", "Joint_Y_Rotation", 0));
        label_15->setText(QApplication::translate("MainWindow", "Joint_Z_Translation", 0));
        label_16->setText(QApplication::translate("MainWindow", "Joint_Z_Rotation", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "-", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuRenderModer->setTitle(QApplication::translate("MainWindow", "RenderModer", 0));
        menuOperation->setTitle(QApplication::translate("MainWindow", "Operation", 0));
        menuSkinningMode->setTitle(QApplication::translate("MainWindow", "SkinningMode", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
