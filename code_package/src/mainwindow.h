#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"drawable.h"
#include <QQuaternion>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void on_actionLoad_Obj_triggered();
    void on_actionLoad_Json_triggered();
    void on_actionColor_Fun_triggered();
    void on_actionShape_Fun_triggered();
    void on_actionMixture_Fun_triggered();
    void on_actionRegular_Form_triggered();
    void on_actionPlanarity_test_triggered();
    void on_actionBevel_Face_triggered();
    void on_actionSharp_Current_Item_triggered();
    void on_actionUndo_skinning_triggered();

    void on_actionCamera_Controls_triggered();


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
