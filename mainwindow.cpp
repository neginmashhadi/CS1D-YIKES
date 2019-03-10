#include "mainwindow.h"
#include "customtripmenu.h"
#include "adminsettingmenu.h"
#include "ui_mainwindow.h"
#include "Restaurant.h"
#include "restaurantstop.h"
#include "receipt.h"
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



     bool notSelected = false;
     bool notExit = true;

     while (!notSelected && notExit && this->isVisible())
     {
         CustomTripMenu* trip = new CustomTripMenu(this);

         ui->verticalLayout_2->addWidget(trip);

         trip->fillCheckBoxes(DB.GetRestuarantList());

         trip->exec();

         notSelected = trip->returnNotSelected();

         for(unsigned int i = 0; i < trip->ReturnSelectedRestaurant().size(); i++)
         {
             restaurntStopList.push_back(trip->ReturnIDsChosenRestaurants().at(i));
         }

         totalDistance = trip ->returnTotalDistance();

         if(trip->returnBack())
         {
             runningProgram = false;

             ui->CT_button->setEnabled(true);
             ui->AllRestaurants_Button->setEnabled(true);
             ui->ShortestTrip_Button->setEnabled(true);
             ui->AdminSetting_button->setEnabled(adminPrivW);

             notExit = false;
         }

    }



     if(notExit)
     {
         restaurantStop* Stops = new restaurantStop(DB.GetRestuarantList(), restaurntStopList, this);
         ui->verticalLayout_2->addWidget(Stops);

         Stops->fillCheckBoxes();

         Stops->exec();

         for(unsigned int j = 0; j < Stops -> returnEachRestantFood().size(); j++)
         {
             foodAndPrice New;

             boughtItems.push_back(New);

             boughtItems.at(j).name =  Stops -> returnEachRestantFood().at(j).name;

             for(unsigned int i = 0; i < Stops -> returnEachRestantFood().at(j).food.size(); i++)
             {
                 boughtItems.at(j).food.push_back( Stops -> returnEachRestantFood().at(j).food.at(i));
                 boughtItems.at(j).price.push_back(Stops -> returnEachRestantFood().at(j).price.at(i));
             }
         }

        notExit = Stops -> returnNotExit();

        if(notExit)
        {
            receipt* receiptWindow = new receipt(boughtItems, totalDistance, this);
            ui->verticalLayout_2->addWidget(receiptWindow);

            receiptWindow->printReceipt();

            receiptWindow->exec();



        }


        if(notExit)
        {
            runningProgram = false;

            ui->CT_button->setEnabled(true);
            ui->AllRestaurants_Button->setEnabled(true);
            ui->ShortestTrip_Button->setEnabled(true);
            ui->AdminSetting_button->setEnabled(adminPrivW);
        }


     }

//     else
//     {
//         runningProgram = false;

//         ui->CT_button->setEnabled(true);
//         ui->AllRestaurants_Button->setEnabled(true);
//         ui->ShortestTrip_Button->setEnabled(true);

//         if(adminPrivW)
//         {
//             ui->AdminSetting_button->setEnabled(true);
//         }
//     }

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
