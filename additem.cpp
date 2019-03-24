#include "additem.h"
#include "ui_additem.h"
#include "structs.h"
#include <QSizePolicy>
#include <QString>
#include <QMessageBox>


AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
    restaurantID = 0;
    foodPrice = -1.0;
    foodName = "";

    ui->food_price->setSingleStep(0.01);

}

int AddItem::getOtherID()
{
    return otherID;
}

int AddItem::getRestaurantID()
{
    return restaurantID;
}

QString AddItem::getFoodName()
{
    return foodName;
}

double AddItem::getFoodPrice()
{
    return foodPrice;
}

void AddItem::fillCheckBoxes(vector<Restaurant> restaurant)
{
    ui->verticalSpacer->changeSize(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->verticalSpacer_2->changeSize(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->verticalSpacer_3->changeSize(0,0, QSizePolicy::Fixed, QSizePolicy::Fixed);

    ui->label->hide();
    ui->label_2->hide();

    ui->food_name->hide();
    ui->food_price->hide();
    ui->Submit->hide();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    for(unsigned int i = 0; i < restaurant.size(); i++)
    {
        restaurantList.push_back(restaurant.at(i));
    }

    restaurantList2.clear();

    for(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        restaurantList2.push_back(restaurantList.at(i));
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


}




AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_buttonBox_accepted()
{

}

void AddItem::on_Next_Button_clicked()
{
    bool checked = false;

    while(!checked)
    {
        if(buttonList.at(restaurantID)->isChecked())
        {
            checked = true;
            otherID = restaurantID;
            restaurantID = restaurantList.at(restaurantID).GetID();
        }
        else
        {
            restaurantID++;
        }
    }

    qDebug() << restaurantList.at(otherID).GetSize();

    if(restaurantList.at(otherID).GetSize() == 8)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","The maximum number of 8 items for " + restaurantList.at(otherID).GetName() + " has been reached.");

        restaurantID = 0;
        foodPrice = -1.0;
        foodName = "";

        for(unsigned int i = 0; i < buttonList.size(); i++)
        {
            delete buttonList.at(i);
        }

        buttonList.clear();

        restaurantList.clear();

        fillCheckBoxes(restaurantList2);

    }
    else
    {
        ui->verticalSpacer->changeSize(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->verticalSpacer_2->changeSize(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);
        ui->verticalSpacer_3->changeSize(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);

        ui->label->show();
        ui->label_2->show();

        ui->food_name->show();
        ui->food_price->show();

        ui->Next_Button->hide();
        ui->Submit->show();

        for(unsigned int i = 0; i < buttonList.size(); i++)
        {
            delete buttonList.at(i);
        }

        buttonList.clear();
    }
}

void AddItem::on_Submit_clicked()
{
    foodName = ui->food_name->text();
    foodPrice = ui->food_price->value();

    if(foodName == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","There was no name input.");
    }
    else
    {
        ui->food_name->setEnabled(false);
        ui->food_price->setEnabled(false);
        ui->Submit->setEnabled(false);
        ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}
