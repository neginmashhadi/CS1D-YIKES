#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminlogin.h"
#include "Database.h"
#include "functions.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void activateButtons();

private slots:
    void on_actionLogin_triggered();

  //  void addWidget();


    //void on_AdminSetting_button_clicked();

    void on_CT_button_clicked();

    void on_actionLogout_triggered();

    void on_AdminSetting_button_clicked();

protected:
    Ui::MainWindow *ui;

    Database DB;

    AdminLogin *uiLogin;
    bool adminPrivW;
    bool runningProgram;
    vector<int> restaurntStopList;
    vector<foodAndPrice> boughtItems;
    float totalDistance;
};

#endif // MAINWINDOW_H
