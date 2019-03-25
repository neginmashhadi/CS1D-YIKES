#include "mainwindow.h"
#include "customtripmenu.h"
#include "adminsettingmenu.h"
#include "ui_mainwindow.h"
#include "Restaurant.h"
#include "restaurantstop.h"
#include "receipt.h"
#include "shortesttrip.h"
#include "addrestaurant.h"
#include "deleterestaurant.h"
#include "deleteitem.h"
#include "additem.h"
#include "edititem.h"
#include "reinitializefirstten.h"
#include <QMessageBox>
#include <QDebug>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    if(!QFile::exists("Restaurants.db"))
    {
        DB = new Database("Restaurants.db");
        DB->CreateTables();
        DB->InputFileToDatabase(":/files/Input.txt");

    }
    else
    {
        DB = new Database("Restaurants.db");
        DB->CreateTables();
    }

    DB->isOpen();
    DB->DatabaseToRestaurants();
    DB->testDatabase();
    DB->PrintAllRestaurants();

    ui->setupUi(this);
    adminPrivW = false;
    runningProgram = false;
    ui->AdminSetting_button->setEnabled(false);
    ui->actionLogout->setEnabled(false);

    QFont fontType;

    fontType.setPointSize(11);

    ui->textBrowser->setFont(fontType);

    dynamicBox[0] = "Main Menu:\n\nYou may select one of the trip choices below."
               " Administrators may login to access Admin Settings."
               " All available restaurant names, items, and"
               " prices are displayed.";

    dynamicBox[1] = "All Restaurants:\n\nAll restaurants will stop at all available"
                      " restaurants starting with the closest to Saddleback College."
                      " Please press \"Next\" to move to the next"
                      " closest restaurant after selecting your items."
                      " Press \"Submit\" when you have completed"
                      " the last stop.";

    dynamicBox[2] = "Custom Trip:\n\nPlease select the fast-food restaurants "
                 "you would like to stop at, then press \"Confirm\" "
                 "to choose your starting restaurant.";

    dynamicBox[3] = "Shortest Trip:\n\nThis trip will start at Domino's"
                   " Pizza and stop at the number of restaurants specified"
                   " in the most efficient order. Please specify the"
                   " number of stops you would like to make, or enter 0 to"
                   " only stop at Domino's Pizza.";

    dynamicBox[4] = "Restaurant Stop:\n\nYou may now order anything from the menu of this"
                    " restaurant. Please press \"Next\" to move to the next"
                    " closest restaurant, and press \"Submit\" when you have completed"
                    " the last restaurant.";

    dynamicBox[5] = "Admin Setting:\n\nPlease select the modification you"
                     " would like to make. Press either \"Restaurant Add/Delete/Reinitialize\""
                     " or \"Item Add/Delete/Edit\" to reveal drop down menus of the"
                     " corresponding settings.";

    dynamicBox[6] = "Receipt:\n\nYou can veiw your final totals here including"
               " items bought from each restaurant and money spent at each"
               " restaurant. Your grand total is displayed at the bottom, and"
               " total distance traveled during your trip is displayed to the right."
               " Please press \"Close\" when finished.";

    dynamicBox[7] = "Add Restaurants:\n\nPlease click the button to add the 2"
                    " additional restaurants from the New Input file.";

    dynamicBox[8] = "Delete Restaurant:\n\nPlease find the ID number of the"
                        " restaurant you would like to delete by looking at the"
                        " table provided, then enter that corresponding ID number"
                        " in to the Line Edit and press \"Submit\".";

    dynamicBox[9] = "Reinitialize:\n\nPlease click the button to reinitialize"
                              " the Data Base with the initial 10 starting restaurants"
                              " from the Infile.";

    dynamicBox[10] = "Add Item:\n\nYou may add a new item to any restaurant by"
                " choosing the restaurant you would like to add to, then"
                " entering the data including name and price for the new "
                "item.";

    dynamicBox[11] = "Delete Item:\n\nYou may delete multiple items from a restaurant of your choice. Please"
                   " select the first restaurant you will be deleting the items from. Then, choose the items"
                   " you would like to delete.";

    dynamicBox[12] = "Edit Item:\n\nYou may Edit any item from a restaurant of"
                 " your choice. Please select the first restaurant you will"
                 " be editing an item from. Then, choose the item you would like"
                 " to edit. Finally, enter in the new data for that item.";


    ui->textBrowser->setText(dynamicBox[0]);

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
        uiLogin->setWindowTitle("Login");
        uiLogin->exec();
        if(uiLogin->GetAdminPriv())
        {

            ui->actionLogout->setEnabled(true);
            ui->actionLogin->setEnabled(false);
            adminPrivW = true;
        }

//        QMessageBox messageBox;
//        messageBox.critical(0,"Error","Can Not Login\nProgram Runnning!");
    }
    else
    {
        uiLogin = new AdminLogin(this);
        uiLogin->setWindowTitle("Login");
        uiLogin->exec();

        if(uiLogin->GetAdminPriv())
        {
            ui->AdminSetting_button->setEnabled(true);
            ui->actionLogout->setEnabled(true);
            adminPrivW = true;
            ui->actionLogin->setEnabled(false);
        }
    }
}

void MainWindow::on_CT_button_clicked()
{
     startTable->hide();

     boughtItems.clear();

     runningProgram = true;

     ui->CT_button->setEnabled(false);
     ui->AllRestaurants_Button->setEnabled(false);
     ui->AdminSetting_button->setEnabled(false);
     ui->ShortestTrip_Button->setEnabled(false);

     bool notSelected = false;
     bool notExit = true;

     while (!notSelected && notExit && this->isVisible())
     {
         ui->textBrowser->setText(dynamicBox[2]);

         CustomTripMenu* trip = new CustomTripMenu(this);

         ui->verticalLayout_2->addWidget(trip);

         trip->fillCheckBoxes(DB->GetRestuarantList());

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

             startTable->show();

             restaurntStopList.clear();
             boughtItems.clear();

             notExit = false;

             ui->textBrowser->setText(dynamicBox[0]);
         }



    }



     if(notExit && this->isVisible())
     {
         ui->textBrowser->setText(dynamicBox[4]);

         restaurantStop* Stops = new restaurantStop(DB->GetRestuarantList(), restaurntStopList, this);
         ui->verticalLayout_2->addWidget(Stops);

         Stops->fillCheckBoxes();

         Stops->exec();

         if(this->isVisible())
         {
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
         }


        notExit = Stops -> returnNotExit();

        if(notExit && this->isVisible())
        {
            ui->textBrowser->setText(dynamicBox[6]);

            receipt* receiptWindow = new receipt(boughtItems, totalDistance, this);
            ui->verticalLayout_2->addWidget(receiptWindow);

            receiptWindow->printReceipt();

            receiptWindow->exec();

            notExit = false;
        }


        if(!notExit)
        {
            runningProgram = false;

            ui->CT_button->setEnabled(true);
            ui->AllRestaurants_Button->setEnabled(true);
            ui->ShortestTrip_Button->setEnabled(true);
            ui->AdminSetting_button->setEnabled(adminPrivW);

            startTable->show();

            restaurntStopList.clear();
            boughtItems.clear();

            ui->textBrowser->setText(dynamicBox[0]);
        }


     }

}

void MainWindow::createTable()
{
    boughtItems.clear();

    for(unsigned int j = 0; j < DB->GetRestuarantList().size(); j++)
    {
        foodAndPrice New;

        boughtItems.push_back(New);

        boughtItems.at(j).name = DB->GetRestuarantList().at(j).GetName();

        boughtItems.at(j).distance = DB->GetRestuarantList().at(j).GetSaddlebackDistance();

        //qDebug() << boughtItems.at(j).distance << endl;

        for(unsigned int i = 0; i < DB->GetRestuarantList().at(j).GetMenuItemsOfRestaurant().size(); i++)
        {
            boughtItems.at(j).food.push_back( DB->GetRestuarantList().at(j).GetMenuItemsOfRestaurant().at(i).GetItemName());
            boughtItems.at(j).price.push_back(DB->GetRestuarantList().at(j).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
        }
    }

    ui->mainToolBar->setMovable(false);
    ui->mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);

    startTable = new receipt(boughtItems, 0.0, this);
    ui->verticalLayout_2->addWidget(startTable);

    startTable->printTable();

}

void MainWindow::on_AdminSetting_button_clicked()
{
    startTable->hide();
    runningProgram = true;

    ui->CT_button->setEnabled(false);
    ui->AllRestaurants_Button->setEnabled(false);
    ui->AdminSetting_button->setEnabled(false);
    ui->ShortestTrip_Button->setEnabled(false);

    bool notSelected = false;
    bool notExit = true;

    int next;

    while (!notSelected && notExit && this->isVisible())
    {
        ui->textBrowser->setText(dynamicBox[5]);
        AdminSettingMenu* settingMenu = new AdminSettingMenu(this);
        ui->verticalLayout_2->addWidget(settingMenu);
        settingMenu->exec();

        notSelected = settingMenu->returnNotSelected();

        next = settingMenu->returnNext();

        if(settingMenu->returnBack())
        {
            runningProgram = false;

            ui->CT_button->setEnabled(true);
            ui->AllRestaurants_Button->setEnabled(true);
            ui->ShortestTrip_Button->setEnabled(true);
            ui->AdminSetting_button->setEnabled(adminPrivW);

            startTable->show();

            restaurntStopList.clear();
            boughtItems.clear();

            ui->textBrowser->setText(dynamicBox[0]);

            notExit = false;
        }

   }


    if(notExit)
    {
        switch (next)
        {
            case 1:{
            ui->textBrowser->setText(dynamicBox[7]);

                       addRestaurant* addRest = new addRestaurant(this);
                       ui->verticalLayout_2->addWidget(addRest);
                       addRest->exec();

                       if(addRest->getPathBool())
                       {
                            AddingRestaurantsPath(addRest->getPath(), DB);
                       }
                       else
                       {
                           AddingRestaurants(addRest->returnClicked(), DB);
                       }
                       break;
                   }

            case 2:{
            ui->textBrowser->setText(dynamicBox[8]);

                        deleteRestaurant* delRest = new deleteRestaurant(DB->GetRestuarantList(),this);
                        ui->verticalLayout_2->addWidget(delRest);

                        delRest->fillTable();

                        delRest->exec();

                        if(delRest->getRestaurantID() > 0)
                        {
                            DB->DeleteRestaurant(delRest->getRestaurantID());

                            for(int i = 0; i < DB->GetRestuarantList().size(); i++)
                            {
                                DB->EditTotalDistances(DB->GetRestuarantList().at(i).GetID(), DB->GetRestuarantList().size() - 1);
                            }

                            DB->ClearRestaurantList();
                            DB->DatabaseToRestaurants();
                        }
                        break;
                   }
        case 3:{
            ui->textBrowser->setText(dynamicBox[9]);

                    ReinitializeFirstTen*  Reinitialize = new ReinitializeFirstTen(this);
                    ui->verticalLayout_2->addWidget( Reinitialize);

                     Reinitialize->exec();

                    if( Reinitialize->getClicked())
                    {
                       for(int i = 0; i < DB->GetRestuarantList().size(); i++)
                       {
                           DB->DeleteRestaurant(DB->GetRestuarantList().at(i).GetID());
                       }

                       DB->InputFileToDatabase(":/files/Input.txt");
                       DB->ClearRestaurantList();
                       DB->DatabaseToRestaurants();
                    }
                    break;
               }

            case 4:{
            ui->textBrowser->setText(dynamicBox[10]);

                        AddItem* addItem = new AddItem(this);
                        ui->verticalLayout_2->addWidget(addItem);

                        addItem->fillCheckBoxes(DB->GetRestuarantList());

                        addItem->exec();

                        if(addItem->getFoodName() != "")
                        {
                           DB->AddMenuItem(addItem->getRestaurantID(), addItem->getFoodName(), addItem->getFoodPrice());

                           DB->SetMenuSize(DB->GetRestuarantList().at(addItem->getOtherID()).GetSize() + 1, addItem->getRestaurantID());

                           DB->ClearRestaurantList();
                           DB->DatabaseToRestaurants();
                        }
                        break;
                   }


            case 5:{

            ui->textBrowser->setText(dynamicBox[11]);

                        DeleteItem* delItem = new DeleteItem(this);
                        ui->verticalLayout_2->addWidget(delItem);

                        delItem->fillCheckBoxes(DB->GetRestuarantList());

                        delItem->exec();

                        if(delItem->getDeletedItems().size() != 0)
                        {
                            DB->DeleteMenuItem(delItem->getDeletedID(),delItem->getDeletedItems(),delItem->getDeletedPrices());

                            DB->SetMenuSize(DB->GetRestuarantList().at(delItem->getRestaurantID()).GetSize() - delItem->getDeletedItems().size(), delItem->getDeletedID());

                            DB->ClearRestaurantList();
                            DB->DatabaseToRestaurants();
                        }
                        break;
                   }

            case 6:{
            ui->textBrowser->setText(dynamicBox[12]);

                        EditItem* thisEditItem = new EditItem(this);
                        ui->verticalLayout_2->addWidget(thisEditItem);

                        thisEditItem->fillCheckBoxes(DB->GetRestuarantList());

                        thisEditItem->exec();

                        if(!thisEditItem->getExit())
                        {
                            DB->EditMenuItem(thisEditItem->getEditRestaurantID(), thisEditItem->getOldName(), thisEditItem->getNewName(), thisEditItem->getNewPrice());

                            DB->ClearRestaurantList();
                            DB->DatabaseToRestaurants();
                        }

                        break;
                   }

        }

        createTable();
    }



    runningProgram = false;

    ui->CT_button->setEnabled(true);
    ui->AllRestaurants_Button->setEnabled(true);
    ui->ShortestTrip_Button->setEnabled(true);
    ui->AdminSetting_button->setEnabled(adminPrivW);

    startTable->show();

    ui->textBrowser->setText(dynamicBox[0]);
}

void MainWindow::on_actionLogout_triggered()
{
    ui->AdminSetting_button->setEnabled(false);
    ui->actionLogout->setEnabled(false);
    ui->actionLogin->setEnabled(true);
    adminPrivW = false;
}

void MainWindow::on_ShortestTrip_Button_clicked()
{
    ui->textBrowser->setText(dynamicBox[3]);
    startTable->hide();
    runningProgram = true;

    boughtItems.clear();

    ui->CT_button->setEnabled(false);
    ui->AllRestaurants_Button->setEnabled(false);
    ui->AdminSetting_button->setEnabled(false);
    ui->ShortestTrip_Button->setEnabled(false);

    shortesttrip* shortTrip = new shortesttrip(DB->GetRestuarantList(),this);
    ui->verticalLayout_2->addWidget(shortTrip);
    shortTrip->exec();

    for(unsigned int i = 0; i < shortTrip->ReturnIDsChosenRestaurants().size(); i++)
    {
        restaurntStopList.push_back(shortTrip->ReturnIDsChosenRestaurants().at(i));
    }

    totalDistance = shortTrip->returnTotalDistance();

    bool notExit = true;

        if(shortTrip->returnBack())
        {
            runningProgram = false;

            ui->CT_button->setEnabled(true);
            ui->AllRestaurants_Button->setEnabled(true);
            ui->ShortestTrip_Button->setEnabled(true);
            ui->AdminSetting_button->setEnabled(adminPrivW);

            startTable->show();

            restaurntStopList.clear();
            boughtItems.clear();

            ui->textBrowser->setText(dynamicBox[0]);
            notExit = false;
        }

    if(notExit)
    {
        restaurantStop* Stops = new restaurantStop(DB->GetRestuarantList(), restaurntStopList, this);
        ui->verticalLayout_2->addWidget(Stops);

        Stops->fillCheckBoxes();

        Stops->exec();

        for(unsigned int j = 0; j < Stops -> returnEachRestantFood().size(); j++)
        {
            ui->textBrowser->setText(dynamicBox[4]);

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

           ui->textBrowser->setText(dynamicBox[6]);

           receipt* receiptWindow = new receipt(boughtItems, totalDistance, this);
           ui->verticalLayout_2->addWidget(receiptWindow);

           receiptWindow->printReceipt();

           receiptWindow->exec();

           notExit = false;

       }


       if(!notExit)
       {
           runningProgram = false;

           ui->CT_button->setEnabled(true);
           ui->AllRestaurants_Button->setEnabled(true);
           ui->ShortestTrip_Button->setEnabled(true);
           ui->AdminSetting_button->setEnabled(adminPrivW);

           startTable->show();

           restaurntStopList.clear();
           boughtItems.clear();

           ui->textBrowser->setText(dynamicBox[0]);
       }


    }
}

void MainWindow::on_AllRestaurants_Button_clicked()
{
    ui->textBrowser->setText(dynamicBox[1]);

    startTable->hide();
    runningProgram = true;

    boughtItems.clear();

    ui->CT_button->setEnabled(false);
    ui->AllRestaurants_Button->setEnabled(false);
    ui->AdminSetting_button->setEnabled(false);
    ui->ShortestTrip_Button->setEnabled(false);


    int shortest = 0;
    double distance = DB->GetRestuarantList().at(0).GetSaddlebackDistance();

    for(int i = 1; i < DB->GetRestuarantList().size(); i++)
    {
        if(DB->GetRestuarantList().at(i).GetSaddlebackDistance() < distance)
        {
            shortest = i;
            distance = DB->GetRestuarantList().at(i).GetSaddlebackDistance();
        }
    }

    totalDistance = DB->GetRestuarantList().at(shortest).GetSaddlebackDistance();

    int spot;
    double smallest; //selectedRestaurant.at(1).GetDistancesToRestaurants(IDsChosenRestaurants.at(counter));

    bool check;
    int index = DB->GetRestuarantList().at(shortest).getLocationID() ;

    restaurntStopList.push_back(DB->GetRestuarantList().at(shortest).getLocationID() );

    double current;

    for(unsigned int k = 0; k < DB->GetRestuarantList().size() - 1; k++ )
    {
        smallest = 100;

        for(unsigned int j = 0; j < DB->GetRestuarantList().size(); j++)
        {
            check = true;

            current = DB->GetRestuarantList().at(j).GetMilesFromRestaurantList(index);

           // CHECK FOR REPETITION

            if(k != 0)
            {
                for(unsigned int i = 0; i < restaurntStopList.size() && check; i++)
                {
                    if(DB->GetRestuarantList().at(j).getLocationID() == restaurntStopList.at(i))
                    {
                        check = false;
                    }
                }
            }

            // CHECK FOR SMALLEST
            if(current != 0.0 && current < smallest && check)
            {
                smallest = current;
                spot = DB->GetRestuarantList().at(j).getLocationID();
            }

        } // for(int j = 0; j < selectedRestaurant.size(); j++)

        totalDistance += smallest;

        restaurntStopList.push_back(spot);

        index = spot;

    } // for(int k = 0; k < selectedRestaurant.size() - 1; k++ )

    restaurantStop* Stops = new restaurantStop(DB->GetRestuarantList(), restaurntStopList, this);
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

    bool notExit = true;

   notExit = Stops -> returnNotExit();

   if(notExit)
   {
       ui->textBrowser->setText(dynamicBox[6]);

       receipt* receiptWindow = new receipt(boughtItems, totalDistance, this);
       ui->verticalLayout_2->addWidget(receiptWindow);

       receiptWindow->printReceipt();

       receiptWindow->exec();

       notExit = false;

   }


   if(!notExit)
   {
       runningProgram = false;

       ui->CT_button->setEnabled(true);
       ui->AllRestaurants_Button->setEnabled(true);
       ui->ShortestTrip_Button->setEnabled(true);
       ui->AdminSetting_button->setEnabled(adminPrivW);

       startTable->show();

       ui->textBrowser->setText(dynamicBox[0]);

       restaurntStopList.clear();
       boughtItems.clear();
   }
}
