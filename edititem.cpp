#include "edititem.h"
#include "ui_edititem.h"
#include <QDebug>
#include <QMessageBox>

EditItem::EditItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditItem)
{
    restaurantID = 0;
    ui->setupUi(this);

    newName = "";
}

void EditItem::fillCheckBoxes(vector<Restaurant> restaurant)
{
    ui->verticalSpacer->changeSize(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->verticalSpacer_2->changeSize(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->verticalSpacer_3->changeSize(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);

    ui->food_name->hide();
    ui->food_price->hide();

    ui->name_label->hide();
    ui->price_label->hide();

    ui->food_name->hide();
    ui->food_price->hide();

    ui->food_price->setSingleStep(0.01);

    ui->submit_button->hide();

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



EditItem::~EditItem()
{
    delete ui;
}

void EditItem::on_next_button_clicked()
{

    if(next == 0)
    {

        bool checked = false;

        while(!checked)
        {
            qDebug() << restaurantID << endl;
            if(buttonList.at(restaurantID)->isChecked())
            {
                checked = true;
                editRestaurantID = restaurantList.at(restaurantID).GetID();
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

        for(unsigned int i = 0; i < restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().size() ; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
        {
            QString price = QString::number(restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(i).GetItemPrice(),'f',2);

            QRadioButton *thisCheckBox = new QRadioButton(" -  " + restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(i).GetItemName() + " - $"+ price, this);

            if(i==0)
            {
                thisCheckBox->setChecked(true);
            }

            ui -> verticalLayout->addWidget(thisCheckBox);

            checkButtonList.push_back(thisCheckBox);
        }

        next++;
    }
    else
    {
        int checked = false;
        int index = 0;

        while(!checked && index < restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().size())
        {
            if(checkButtonList.at(index)->isChecked())
            {
                checked  = true;
                oldName  = restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(index).GetItemName();
                oldPrice =  restaurantList.at(restaurantID).GetMenuItemsOfRestaurant().at(index).GetItemPrice();
            }
            else
            {
                index++;
            }
        }

        for(int i = 0; i < checkButtonList.size(); i++)
        {
            delete checkButtonList.at(i);
        }


        ui->verticalSpacer->changeSize(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->verticalSpacer_2->changeSize(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->verticalSpacer_3->changeSize(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);

        ui->food_name->show();
        ui->food_price->show();

        ui->name_label->show();
        ui->price_label->show();

        ui->name_label->setText("The new name for \"" + oldName + "\":");
        ui->price_label->setText("The new price for \"" + oldName + "\":");

        ui->food_name->setText(oldName);
        ui->food_price->setValue(oldPrice);

        ui->next_button->hide();
        ui->submit_button->show();
    }
}

void EditItem::on_submit_button_clicked()
{
    newName = ui->food_name->text();
    newPrice = ui->food_price->value();

    if(newName == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","There was no name input.");
    }
    else
    {
        ui->submit_button->hide();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

QString EditItem::getOldName()
{
    return oldName;
}

double EditItem::getOldPrice()
{
    return oldPrice;
}

QString EditItem::getNewName()
{
    return newName;
}

double EditItem::getNewPrice()
{
    return newPrice;
}

int EditItem::getRestaurantID()
{
    return restaurantID;
}

int EditItem::getEditRestaurantID()
{
    return editRestaurantID;
}

void EditItem::on_buttonBox_rejected()
{
    exit = true;
}

bool EditItem::getExit()
{
   return exit;
}

