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

    for(unsigned int i = 0; i < restaurantList.size(); i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
    {
       // QCheckBox *thisCheckBox = new QCheckBox("test", this); //(restaurantList.at(i).GetName(), this);
       // CTui -> verticalLayout->addWidget(thisCheckBox);

        qDebug() << "Test #" << i << endl;
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
//    if(CTui->MacDonalds_checkBox->checkState())
//    {
//        restaurants.push_back("ManDonalds");
//    }

//    if(CTui->Chipotle_checkBox->checkState())
//    {
//        restaurants.push_back("Chipotle");
//    }

//    if(CTui->Dominos_checkBox->checkState())
//    {
//        restaurants.push_back("Domino's Pizza");
//    }

//    if(CTui->KFC_checkBox->checkState())
//    {
//        restaurants.push_back("KFC");
//    }

//    if(CTui->Subway_checkBox->checkState())
//    {
//        restaurants.push_back("Subway");
//    }
//    if(CTui->InNOut_checkBox->checkState())
//    {
//        restaurants.push_back("In-N-Out");
//    }

//    if(CTui->Wendys_checkBox->checkState())
//    {
//        restaurants.push_back("Wendy's");
//    }

//    if(CTui->JackInTheBox_checkBox->checkState())
//    {
//        restaurants.push_back("Jack in the Box");
//    }

//    if(CTui->ElPolloLoco_checkBox->checkState())
//    {
//        restaurants.push_back("El Pollo Loco");
//    }

//    if(CTui->PapaJohns_checkBox->checkState())
//    {
//        restaurants.push_back("Papa John's Pizza");
//    }
}
