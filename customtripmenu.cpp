#include "customtripmenu.h"
#include "mainwindow.h"
#include "Restaurant.h"
#include <qmessagebox.h>
#include <QCheckBox>
#include "ui_customtripmenu.h"

using namespace std;

CustomTripMenu::CustomTripMenu(QWidget *parent) :
    QDialog(parent),
    CTui(new Ui::CustomTripMenu),
    notSelected(false)
{

     //this->CTui->verticalLayout->addWidget(thisCheckBox);


   // CTui->QBoxLayout(lay);

    totalDistance = 0.0;

    CTui->setupUi(this);
}

CustomTripMenu::~CustomTripMenu()
{
    delete CTui;
}

void CustomTripMenu::fillCheckBoxes(vector<Restaurant> restaurant)
{
//    QCheckBox *thisCheckBox = new QCheckBox("Check test box", this);
//    thisCheckBox->setChecked(true);
//    CTui -> verticalLayout->addWidget(thisCheckBox);

    for(unsigned int i = 0; i < restaurant.at(1).GetTotalDistance(); i++)
    {
        restaurantList.push_back(restaurant.at(i));
    }

    int rSize = restaurantList.at(1).GetTotalDistance();
    for(unsigned int i = 0; i < rSize ; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        QCheckBox *thisCheckBox = new QCheckBox(restaurantList.at(i).GetName(), this); //(restaurantList.at(1).GetName(), this);
        CTui -> verticalLayout->addWidget(thisCheckBox);

        checkBoxList.push_back(thisCheckBox);        
    }


}


void CustomTripMenu::on_buttonBox_rejected()
{
    back = true;
}

bool CustomTripMenu::returnBack()
{
    return back;
}

vector<Restaurant> CustomTripMenu::ReturnSelectedRestaurant()
{
    return selectedRestaurant;
}

vector<int> CustomTripMenu::ReturnIDsChosenRestaurants()
{
    return IDsChosenRestaurants;
}

bool CustomTripMenu::returnNotSelected()
{
    return notSelected;
}

float CustomTripMenu::returnTotalDistance()
{
    return totalDistance;
}

void CustomTripMenu::on_buttonBox_accepted()
{
    for(unsigned int i = 0; i < checkBoxList.size(); i++)
    {
        if(checkBoxList.at(i)->checkState())
        {
            //IDsChosenRestaurants.push_back(i);
            selectedRestaurant.push_back((restaurantList.at(i)));
        }

    }

    if(selectedRestaurant.size() > 0)
    {
        int spot;
        float smallest; //selectedRestaurant.at(1).GetDistancesToRestaurants(IDsChosenRestaurants.at(counter));
        bool check;
        int index = selectedRestaurant.at(0).GetID() -1 ;

        qDebug() << "index is " << index << endl;
        IDsChosenRestaurants.push_back(selectedRestaurant.at(0).GetID() -1 );
       // qDebug() << "psuhing" << selectedRestaurant.at(0).GetID() -1 << endl;
        float current ;

        for(int k = 0; k < selectedRestaurant.size() - 1; k++ )
        {
            smallest = 100;

            for(int j = 0; j < selectedRestaurant.size(); j++)
            {
                check = true;

                qDebug() << "index is " << index << endl;

                qDebug() << "Size: " << selectedRestaurant.at(j).GetDistancesToRestaurants().size() << endl;

                current = selectedRestaurant.at(j).GetMilesFromRestaurantList(index);

               // CHECK FOR REPETITION

                if(k != 0)
                {
                    for(int i = 0; i < IDsChosenRestaurants.size() && check; i++)
                    {
                        qDebug() << "Inside CHECK:" << endl;
                        qDebug() << "j is " << j << endl;
                        qDebug() << "i is " << i << endl;
                        if(selectedRestaurant.at(j).GetID() - 1 == IDsChosenRestaurants.at(i))
                        {
                            check = false;
                            qDebug() << "NOOOOOOOOOOOOOOO\n" ;
                        }
                    }
                }

                // CHECK FOR SMALLEST
                if(current != 0.0 && current < smallest && check)
                {
                    smallest = current;
                    spot = selectedRestaurant.at(j).GetID() - 1;
                }

            } // for(int j = 0; j < selectedRestaurant.size(); j++)

            totalDistance += smallest;

            IDsChosenRestaurants.push_back(spot);

            index = spot;

        } // for(int k = 0; k < selectedRestaurant.size() - 1; k++ )

    }//END IF


    if(selectedRestaurant.size() != 0)
    {
//        qDebug() << restaurantList.at(8).GetName() << endl;
        notSelected = true;
        for(unsigned int i = 0; i < IDsChosenRestaurants.size(); i++ )
        {
            qDebug() << IDsChosenRestaurants.at(i) << endl;
            qDebug() << restaurantList.at(IDsChosenRestaurants.at(i)).GetName() << endl;
        }
    }
    else
    {
        notSelected = false;
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No restaurants Selected");

    }
}
