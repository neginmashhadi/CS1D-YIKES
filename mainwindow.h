#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "receipt.h"
#include "adminlogin.h"
#include "Database.h"
#include "structs.h"
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createTable();

    void activateButtons();

private slots:
    void on_actionLogin_triggered();

    void on_CT_button_clicked();

    void on_actionLogout_triggered();

    void on_AdminSetting_button_clicked();

    void on_ShortestTrip_Button_clicked();

    void on_AllRestaurants_Button_clicked();

protected:
    Ui::MainWindow *ui;

    Database* DB;

    AdminLogin *uiLogin;
    bool adminPrivW;
    bool runningProgram;
    vector<int> restaurntStopList;
    vector<foodAndPrice> boughtItems;
    receipt *startTable;

    QString dynamicBox[13];

//    int allRestaurantsT;
//    int customTripT;
//    int shortestTripT;
//    int restaurantStopT;
//    int adminSettingsT;
//    int mainMenuT;
//    int receiptT;
//    QString addRestaurantT;
//    QString deleteRestaurantT;
//    QString reinitializeRestaurantT;
//    QString addItemsT;
//    QString deleteItemsT;
//    QString editItemsT;

    double totalDistance;
};

#endif // MAINWINDOW_H
