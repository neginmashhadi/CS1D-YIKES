#include "customtripmenu.h"
#include "mainwindow.h"
#include "Restaurant.h"
#include <qmessagebox.h>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include "ui_customtripmenu.h"

using namespace std;

CustomTripMenu::CustomTripMenu(QWidget *parent) :
    QDialog(parent),
    CTui(new Ui::CustomTripMenu),
    notSelected(false)
{
    totalDistance = 0.0;

    CTui->setupUi(this);
}

CustomTripMenu::~CustomTripMenu()
{
    delete CTui;
}

void CustomTripMenu::fillCheckBoxes(vector<Restaurant> restaurant)
{
    CTui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    for(unsigned int i = 0; i < restaurant.size() && !back; i++)
    {
        restaurantList.push_back(restaurant.at(i));
    }

    int rSize = restaurantList.size();

    for(unsigned int i = 0; i < rSize && !back ; i++)
    {
        QCheckBox *thisCheckBox = new QCheckBox(restaurantList.at(i).GetName(), this); //(restaurantList.at(1).GetName(), this);
        CTui -> verticalLayout->addWidget(thisCheckBox);

        checkBoxList.push_back(thisCheckBox);        
    }

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

double CustomTripMenu::returnTotalDistance()
{
    return totalDistance;
}



void CustomTripMenu::on_buttonBox_accepted()
{
    //get the users first choice

    first = group.checkedId();

    //***********************
    //Organize the vector key
    //***********************

    if(selectedRestaurant.size() > 0 && !back)
    {
        int spot;
        double smallest; //selectedRestaurant.at(1).GetDistancesToRestaurants(IDsChosenRestaurants.at(counter));

        bool check;
        int index = selectedRestaurant.at(first).getLocationID() ;

        IDsChosenRestaurants.push_back(selectedRestaurant.at(first).getLocationID() );

        double current;



        for(unsigned int k = 0; k < selectedRestaurant.size() - 1 && !back; k++ )
        {
            smallest = 100;

            for(unsigned int j = 0; j < selectedRestaurant.size() && !back; j++)
            {
                check = true;

                current = selectedRestaurant.at(j).GetMilesFromRestaurantList(index);

               // CHECK FOR REPETITION

//                if(k != 0)
//                {
                    for(unsigned int i = 0; i < IDsChosenRestaurants.size() && check && !back; i++)
                    {
                        if(selectedRestaurant.at(j).getLocationID() == IDsChosenRestaurants.at(i))
                        {
                            check = false;


                            qDebug() << selectedRestaurant.at(j).getLocationID() << "******!";
                            qDebug() << IDsChosenRestaurants.at(i) << "******!" << endl;
                        }

                    }
//                }
                qDebug() << check;
                // CHECK FOR SMALLEST

                if(current != 0.0 && current < smallest && check && index != j)
                {
                    smallest = current;
                    spot = selectedRestaurant.at(j).getLocationID();
                }

            } // for(int j = 0; j < selectedRestaurant.size(); j++)

            totalDistance += smallest;

            IDsChosenRestaurants.push_back(spot);

            index = spot;

        } // for(int k = 0; k < selectedRestaurant.size() - 1; k++ )

    }//END IF


    if(selectedRestaurant.size() != 0 && !back)
    {
        notSelected = true;
        for(unsigned int i = 0; i < IDsChosenRestaurants.size() && !back; i++ )
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

void CustomTripMenu::on_pushButton_clicked()
{
    for(unsigned int i = 0; i < checkBoxList.size() && !back; i++)
    {
        if(checkBoxList.at(i)->checkState())
        {
            //IDsChosenRestaurants.push_back(i);
            selectedRestaurant.push_back((restaurantList.at(i)));
        }
    }

    for(unsigned int i = 0; i < checkBoxList.size() && !back; i++)
    {
        delete checkBoxList.at(i);
    }

    CTui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

    CTui->pushButton->hide();

    for(unsigned int i = 0; i < selectedRestaurant.size() && !back; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        QRadioButton *thisButton = new QRadioButton(selectedRestaurant.at(i).GetName(), this);

        if(i == 0)
        {
            thisButton->setChecked(true);
        }

        CTui -> verticalLayout->addWidget(thisButton);
        group.addButton(thisButton,i);
    }

    if(back)
    {
        restaurantList.clear();
        checkBoxList.clear();
        selectedRestaurant.clear();
    }
}

bool CustomTripMenu::returnBack()
{
    restaurantList.clear();
    checkBoxList.clear();
    selectedRestaurant.clear();

    return back;
}

void CustomTripMenu::on_buttonBox_rejected()
{
    back = true;

    restaurantList.clear();
    checkBoxList.clear();
    selectedRestaurant.clear();
}
