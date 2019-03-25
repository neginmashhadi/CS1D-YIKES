#include "deleteitem.h"
#include "ui_deleteitem.h"
#include <QRadioButton>
#include "Restaurant.h"
#include <QString>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>
#include <QMessageBox>

DeleteItem::DeleteItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteItem)
{
    ui->setupUi(this);

    restaurantID = 0;
}

void DeleteItem::fillCheckBoxes(vector<Restaurant> restaurant)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    for(unsigned int i = 0; i < restaurant.size(); i++)
    {
        restaurantList.push_back(restaurant.at(i));
    }

    int rSize = restaurantList.size();
    for(unsigned int i = 0; i < rSize ; i++)
    {
        QRadioButton *thisButton = new QRadioButton(restaurantList.at(i).GetName(), this); //(restaurantList.at(1).GetName(), this);

        if(i==0)
        {
            thisButton->setChecked(true);
        }

        ui -> verticalLayout->addWidget(thisButton);
        buttonList.push_back(thisButton);
    }

    ui->submit_button->hide();

}

int DeleteItem::getRestaurantID()
{
    return restaurantID;
}

int DeleteItem::getDeletedID()
{
    return deletedID;
}

vector<QString> DeleteItem::getDeletedItems()
{
    return deletedItems;
}

vector<double> DeleteItem::getDeletedPrices()
{
    return deletedPrices;
}

DeleteItem::~DeleteItem()
{
    delete ui;
}

void DeleteItem::on_buttonBox_accepted()
{

}

void DeleteItem::on_next_button_clicked()
{
    ui->submit_button->show();
    ui->next_button->hide();

    bool checked = false;

    while(!checked)
    {
        if(buttonList.at(restaurantID)->isChecked())
        {
            qDebug() << restaurantID << endl;
            checked = true;
            deletedID = restaurantList.at(restaurantID).GetID();

            qDebug() << restaurantID << endl;
        }
        else
        {
            restaurantID++;
        }
    }

    for(int i = 0; i < buttonList.size(); i++)
    {
        delete buttonList.at(i);
    }

    buttonList.clear();


    bool notChecked = true;
    int index = 0;


    for(unsigned int i = 0; i < restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().size() ; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        QString price = QString::number(restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(i).GetItemPrice(),'f',2);

        QCheckBox *thisCheckBox = new QCheckBox(" -  " + restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(i).GetItemName() + " - $"+ price, this);

        ui -> verticalLayout->addWidget(thisCheckBox);

        checkButtonList.push_back(thisCheckBox);

    }

}

void DeleteItem::on_submit_button_clicked()
{
    for(int i = 0; i < checkButtonList.size(); i++)
    {
        if(checkButtonList.at(i)->isChecked())
        {
            deletedPrices.push_back(restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
            deletedItems.push_back(restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(i).GetItemName());
        }
    }

    if(deletedItems.size()==0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No Items Selected");
    }
    else
    {
        ui->submit_button->setEnabled(false);

        for(unsigned int i = 0; i < checkButtonList.size(); i++)
        {
            checkButtonList.at(i)->setEnabled(false);
        }

        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}
