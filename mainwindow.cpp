#include "mainwindow.h"
#include "customtripmenu.h"
#include "adminsettingmenu.h"
#include "ui_mainwindow.h"
#include "Restaurant.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //DataBase
    DB.InputFileToDatabase(":/files/Input.txt");
    DB.DatabaseToRestaurants();

    DB.testDatabase();

    ui->setupUi(this);
    adminPrivW = false;
    runningProgram = false;
    ui->AdminSetting_button->setEnabled(false);
    ui->actionLogout->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLogin_triggered()
{
    if(runningProgram)
    {
        uiLogin = new AdminLogin(this);
        uiLogin->exec();
        if(uiLogin->GetAdminPriv())
        {

            ui->actionLogout->setEnabled(true);
            adminPrivW = true;
        }

//        QMessageBox messageBox;
//        messageBox.critical(0,"Error","Can Not Login\nProgram Runnning!");
    }
    else
    {
        uiLogin = new AdminLogin(this);
        uiLogin->exec();

        if(uiLogin->GetAdminPriv())
        {
            ui->AdminSetting_button->setEnabled(true);
            ui->actionLogout->setEnabled(true);
            adminPrivW = true;
        }
    }
}

void MainWindow::on_CT_button_clicked()
{
    runningProgram = true;

     ui->CT_button->setEnabled(false);
     ui->AllRestaurants_Button->setEnabled(false);
     ui->AdminSetting_button->setEnabled(false);
     ui->ShortestTrip_Button->setEnabled(false);
//     vector<Restaurant> test = DB.GetRestuarantList();

     CustomTripMenu* trip = new CustomTripMenu(DB.GetRestuarantList(),this);
     ui->verticalLayout_2->addWidget(trip);

     trip->fillCheckBoxes();

     trip->exec();

     if(trip->returnBack())
     {
         runningProgram = false;

         ui->CT_button->setEnabled(true);
         ui->AllRestaurants_Button->setEnabled(true);
         ui->ShortestTrip_Button->setEnabled(true);

         if(adminPrivW)
         {
             ui->AdminSetting_button->setEnabled(true);
         }
     }

}

void MainWindow::on_AdminSetting_button_clicked()
{
    runningProgram = true;

    ui->CT_button->setEnabled(false);
    ui->AllRestaurants_Button->setEnabled(false);
    ui->AdminSetting_button->setEnabled(false);
    ui->ShortestTrip_Button->setEnabled(false);

    AdminSettingMenu* settingMenu = new AdminSettingMenu(this);
    ui->verticalLayout_2->addWidget(settingMenu);
    settingMenu->exec();

    if(settingMenu->returnBack())
    {
        runningProgram = false;

        ui->CT_button->setEnabled(true);
        ui->AllRestaurants_Button->setEnabled(true);
        ui->ShortestTrip_Button->setEnabled(true);

        if(adminPrivW)
        {
            ui->AdminSetting_button->setEnabled(true);
        }
    }
    else
    {
        switch (settingMenu->returnNext())
        {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
        }
    }
}

void MainWindow::on_actionLogout_triggered()
{
    ui->AdminSetting_button->setEnabled(false);
    ui->actionLogout->setEnabled(false);
    adminPrivW = false;
}
