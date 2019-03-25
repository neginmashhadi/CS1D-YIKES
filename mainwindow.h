/*
 *  Fast Food Project
 *  Spring 2019
 *
 *  Oscar Lopez <olopez23@saddleback.edu>
 *  Jeff Adams <jadams62@saddleback.edu>
 *  Isaac Estrada <iestrada5@saddleback.edu>
 *  Caroline Ta <tta24@saddleback.edu>
 *  Negin Mashhadi <nmashhadi0@ivc.edu>
 *
 *  Descr: Fast Food Project for Spring 2019 CS1D
 *  Professor: Jerry Lebowitz
 *
 *  This program is an application in which a foodie
 *  at Saddleback College can plan various trips to
 *  fast food restaurants.
 *
 **/
/*
    File: mainwindow.h
    Class for the user interface of the main menu page
*/

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

/**
@brief used to control MainWindow like Canvas, where button are displayed to perform selected tasks accordingly
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /** Default constructor
    */
    explicit MainWindow(QWidget *parent = nullptr);

    /** Destructor
    */
    ~MainWindow();

    /** Creates a table of list of restaurants with distances from Saddleback
    */
    void createTable();

    /** Allows buttons to be activated
    */
    void activateButtons();

private slots:
    /** Handles when [Admin] Login is clicked
    */
    void on_actionLogin_triggered();

    /** Handles when [Admin] Logout is clicked
    */
    void on_actionLogout_triggered();

    /** Handles when All Starting at Saddleback button is clicked
    */
    void on_AllRestaurants_Button_clicked();

    /** Handles when Custom Trip button is clicked
    */
    void on_CT_button_clicked();

    /** Handles when Shortest Trip button is clicked
    */
    void on_ShortestTrip_Button_clicked();

    /** Handles when Admin Setting button is clicked
    */
    void on_AdminSetting_button_clicked();

protected:
    Ui::MainWindow          *ui;                /**<Handles the UI for the MainWindow*/
    Database                *DB;                /**<Handles Database access*/
    AdminLogin              *uiLogin;           /**<Handles the UI after login*/
    bool                    adminPrivW;         /**<Saves boolean expression if admin privilege is given*/
    bool                    runningProgram;     /**<Saves boolean expression if the user is in a trip*/
    vector<int>             restaurntStopList;  /**<Saves the list of restaurant stops*/
    vector<foodAndPrice>    boughtItems;        /**<Saves the bought items*/
    receipt                 *startTable;        /**<Saves the startup table when first entering the program*/
    QString                 dynamicBox[13];     /**<Saves texts displayed for program discription into an array*/
    double                  totalDistance;      /**<Saves the total distance*/
};

#endif // MAINWINDOW_H
