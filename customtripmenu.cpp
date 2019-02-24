#include "customtripmenu.h"
#include "mainwindow.h"
#include "ui_customtripmenu.h"

CustomTripMenu::CustomTripMenu(QWidget *parent) :
    QDialog(parent),
    CTui(new Ui::CustomTripMenu)
{
    CTui->setupUi(this);
}

CustomTripMenu::~CustomTripMenu()
{
    delete CTui;
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
    if(CTui->MacDonalds_checkBox->checkState())
    {
        restaurants.push_back("ManDonalds");
    }

    if(CTui->Chipotle_checkBox->checkState())
    {
        restaurants.push_back("Chipotle");
    }

    if(CTui->Dominos_checkBox->checkState())
    {
        restaurants.push_back("Domino's Pizza");
    }

    if(CTui->KFC_checkBox->checkState())
    {
        restaurants.push_back("KFC");
    }

    if(CTui->Subway_checkBox->checkState())
    {
        restaurants.push_back("Subway");
    }
    if(CTui->InNOut_checkBox->checkState())
    {
        restaurants.push_back("In-N-Out");
    }

    if(CTui->Wendys_checkBox->checkState())
    {
        restaurants.push_back("Wendy's");
    }

    if(CTui->JackInTheBox_checkBox->checkState())
    {
        restaurants.push_back("Jack in the Box");
    }

    if(CTui->ElPolloLoco_checkBox->checkState())
    {
        restaurants.push_back("El Pollo Loco");
    }

    if(CTui->PapaJohns_checkBox->checkState())
    {
        restaurants.push_back("Papa John's Pizza");
    }
}
