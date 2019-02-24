#include "mainwindow.h"
#include "customtripmenu.h"
#include "blocker.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adminPrivW = false;
    ui->AdminSetting_button->setEnabled(false);
    ui->actionLogout->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLogin_triggered()
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

// void MainWindow::activateButtons()
// {
//     ui -> AdminSetting_button -> setEnabled(true);
// }




//uiLogin = new AdminLogin(this);
//uiLogin->exec();

//if(uiLogin->GetAdminPriv())
//{
//    ui->AdminSetting_button->setEnabled(true);
//}
//}

// void MainWindow::activateButtons()
// {
//     ui -> AdminSetting_button -> setEnabled(true);
// }

void MainWindow::on_CT_button_clicked()
{
     ui->CT_button->setEnabled(false);
     ui->AllRestaurants_Button->setEnabled(false);
     ui->AdminSetting_button->setEnabled(false);
     ui->ShortestTrip_Button->setEnabled(false);

     CustomTripMenu* trip = new CustomTripMenu(this);
     ui->verticalLayout_2->addWidget(trip);
     trip->exec();

     if(trip->returnBack())
     {
         ui->CT_button->setEnabled(true);
         ui->AllRestaurants_Button->setEnabled(true);
         ui->ShortestTrip_Button->setEnabled(true);

         if(adminPrivW)
         {
             ui->AdminSetting_button->setEnabled(true);
         }
     }

}

void MainWindow::on_actionLogout_triggered()
{
    ui->AdminSetting_button->setEnabled(false);
    ui->actionLogout->setEnabled(false);
    adminPrivW = false;
}
