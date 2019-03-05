#include "customtripmenu.h"
#include "mainwindow.h"
#include "Restaurant.h"
#include <QCheckBox>
#include "ui_customtripmenu.h"
using namespace std;

CustomTripMenu::CustomTripMenu(vector<Restaurant> restaurant, QWidget *parent) :
    QDialog(parent),
    CTui(new Ui::CustomTripMenu)
{
    for(unsigned int i = 0; i < restaurant.size(); i++)
    {
        restaurantList.push_back(restaurant.at(i));
    }


     //this->CTui->verticalLayout->addWidget(thisCheckBox);


   // CTui->QBoxLayout(lay);
    CTui->setupUi(this);
}

CustomTripMenu::~CustomTripMenu()
{
    delete CTui;
}

void CustomTripMenu::fillCheckBoxes()
{
//    QCheckBox *thisCheckBox = new QCheckBox("Check test box", this);
//    thisCheckBox->setChecked(true);
//    CTui -> verticalLayout->addWidget(thisCheckBox);
    int rSize = restaurantList.at(1).GetTotalDistance();
    for(unsigned int i = 0; i < rSize ; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        QCheckBox *thisCheckBox = new QCheckBox(restaurantList.at(i).GetName(), this); //(restaurantList.at(1).GetName(), this);
        CTui -> verticalLayout->addWidget(thisCheckBox);

        checkBoxList.push_back(thisCheckBox);        
    }

    for(unsigned int i = 0; i < checkBoxList.size(); i++ )
    {
        qDebug() << "test " << i << endl;
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

void CustomTripMenu::on_buttonBox_accepted()
{
    for(unsigned int i = 0; i < checkBoxList.size(); i++)
    {
        if(checkBoxList.at(i)->checkState())
        {
            selectedRestaurant.push_back((restaurantList.at(i)));
        }

    }

    for(unsigned int i = 0; i < selectedRestaurant.size(); i++ )
    {
        qDebug() << selectedRestaurant.at(i).GetName() << endl;
    }

}
