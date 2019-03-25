
#include "restaurantstop.h"
#include "ui_restaurantstop.h"
#include "mainwindow.h"
#include "Restaurant.h"
#include <QCheckBox>
#include <QSpinBox>

restaurantStop::restaurantStop(vector<Restaurant> restaurant, vector<int> keyList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restaurantStop)
{
    for(unsigned int i = 0; i < restaurant.size(); i++)
    {
        restaurantList.push_back(restaurant.at(i));
    }

    for(unsigned int i = 0; i < keyList.size(); i++)
    {
        stopKey.push_back(keyList.at(i));
    }

    for(unsigned int i = 0; i < keyList.size(); i++ )
    {
        qDebug() << restaurantList.at(keyList.at(i)).GetName() << " # "<< endl;
    }

    counter = 0;

    ui->setupUi(this);

    ui->Submit_Button->hide();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    notExit = true;

    //ui->buttonBox->setDisabled(true);
}



restaurantStop::~restaurantStop()
{
    delete ui;
}

vector<foodAndPrice> restaurantStop::returnEachRestantFood()
{
    return eachRestantFood;
}

bool restaurantStop::returnNotExit()
{
    return notExit;
}


void restaurantStop::fillCheckBoxes()
{
//    QCheckBox *thisCheckBox = new QCheckBox("Check test box", this);
//    thisCheckBox->setChecked(true);
//    ui -> verticalLayout->addWidget(thisCheckBox);


    ui->label->setText(restaurantList.at(stopKey.at(counter)).GetName() + " Menu");

    ui->label->setAlignment(Qt::AlignCenter);

    qDebug() << "name: " << restaurantList.at(stopKey.at(counter)).GetName() << endl;

    foodAndPrice New;

    eachRestantFood.push_back(New);

    eachRestantFood.at(counter).name = (restaurantList.at(stopKey.at(counter)).GetName());

    qDebug() << "menu size: " << restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().size() << endl;

    for(unsigned int i = 0; i < restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().size() ; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        QString price = QString::number(restaurantList.at(stopKey.at(counter)).
                                        GetMenuItemsOfRestaurant().at(i).
                                        GetItemPrice(),'f',2);

        QSpinBox *thisSpinBox = new QSpinBox(this);

        thisSpinBox->setSuffix( " -  " + restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() + " - $"+ price);

        ui -> verticalLayout->addWidget(thisSpinBox);

        spinBoxList.push_back(thisSpinBox);

      //  QCheckBox *thisCheckBox = new QCheckBox(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() + " - $" + price, this); //(restaurantList.at(1).GetName(), this);
        //ui -> verticalLayout->addWidget(thisCheckBox);

       // checkBoxList.push_back(thisCheckBox);
    }

    for(unsigned int i = 0; i < checkBoxList.size(); i++ )
    {
        qDebug() << "test " << i << endl;
    }

    if(counter == stopKey.size() - 1)
    {
        ui->Next_Button->hide();
        ui->Submit_Button->show();
    }
}


void restaurantStop::on_buttonBox_accepted()
{

    for(unsigned int i = 0; i < eachRestantFood.size(); i++)
    {
        qDebug() << "Restaurant: " << eachRestantFood.at(i).name << endl;

        for(unsigned int j = 0; j < eachRestantFood.at(i).food.size(); j++)
        {
            qDebug() << "Food #" << j + 1 << eachRestantFood.at(i).food.at(j) << " - $" << eachRestantFood.at(i).price.at(j) << endl;
        }
    }

    for(unsigned int i = 0; i < spinBoxList.size(); i++)
    {
        qDebug() << "amount " << spinBoxList.at(i)->value() << endl;
    }


//    for(unsigned int i = 0; i < selectedFood.size(); i++ )
//    {
//        qDebug() << "#" << i+1<<" item " << selectedFood.at(i).GetItemName() << endl;
//    }
}

void restaurantStop::on_buttonBox_rejected()
{
   notExit = false;
}

void restaurantStop::on_Next_Button_clicked()
{
//    for(unsigned int i = 0; i < checkBoxList.size(); i++)
//    {
//        if(checkBoxList.at(i)->checkState())
//        {
//            qDebug() << "adding " <<  restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() << endl;

//            selectedFood.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i));

//            eachRestantFood.at(counter).food.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName());
//            eachRestantFood.at(counter).price.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
//        }
//    }

    for(unsigned int i = 0; i < spinBoxList.size(); i++)
    {
        for(int j = 0; j < spinBoxList.at(i)->value() != 0; j++)
        {
            qDebug() << "adding " <<  restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() << endl;
            selectedFood.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i));

            eachRestantFood.at(counter).food.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName());
            eachRestantFood.at(counter).price.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
        }
    }

    for(unsigned int i = 0; i < checkBoxList.size(); i++)
    {
        delete checkBoxList.at(i);

    }

    for(unsigned int i = 0; i < spinBoxList.size(); i++)
    {
        delete spinBoxList.at(i);

    }

    checkBoxList.clear();
    spinBoxList.clear();

    if(counter <= stopKey.size() - 1)
    {
        counter++;
        fillCheckBoxes();
    }
}

void restaurantStop::on_Submit_Button_clicked()
{
    for(unsigned int i = 0; i < spinBoxList.size(); i++)
    {
        for(int j = 0; j < spinBoxList.at(i)->value() != 0; j++)
        {
            qDebug() << "adding " <<  restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() << endl;
            selectedFood.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i));

            eachRestantFood.at(counter).food.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName());
            eachRestantFood.at(counter).price.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
        }
    }

    ui->Submit_Button->setEnabled(false);

    for(unsigned int i = 0; i < spinBoxList.size(); i++)
    {
        spinBoxList.at(i)->setEnabled(false);
    }

    for(unsigned int i = 0; i < checkBoxList.size(); i++)
    {
        checkBoxList.at(i)->setEnabled(false);
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

//#include "restaurantstop.h"
//#include "ui_restaurantstop.h"
//#include "mainwindow.h"
//#include "Restaurant.h"
//#include <QCheckBox>

//restaurantStop::restaurantStop(vector<Restaurant> restaurant, vector<int> keyList, QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::restaurantStop)
//{
//    for(unsigned int i = 0; i < restaurant.size(); i++)
//    {
//        restaurantList.push_back(restaurant.at(i));
//    }

//    for(unsigned int i = 0; i < keyList.size(); i++)
//    {
//        stopKey.push_back(keyList.at(i));
//    }

//    for(unsigned int i = 0; i < keyList.size(); i++ )
//    {
//        qDebug() << restaurantList.at(keyList.at(i)).GetName() << " # "<< endl;
//    }

//    counter = 0;

//    ui->setupUi(this);

//    ui->Submit_Button->hide();

//    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

//    notExit = true;

//    //ui->buttonBox->setDisabled(true);
//}



//restaurantStop::~restaurantStop()
//{
//    delete ui;
//}

//vector<foodAndPrice> restaurantStop::returnEachRestantFood()
//{
//    return eachRestantFood;
//}

//bool restaurantStop::returnNotExit()
//{
//    return notExit;
//}


//void restaurantStop::fillCheckBoxes() //fillSpinBoxes
//{
////    QCheckBox *thisCheckBox = new QCheckBox("Check test box", this);
////    thisCheckBox->setChecked(true);
////    ui -> verticalLayout->addWidget(thisCheckBox);


//    ui->label->setText(restaurantList.at(stopKey.at(counter)).GetName() + " Menu");

//    ui->label->setAlignment(Qt::AlignCenter);

//    qDebug() << "name: " << restaurantList.at(stopKey.at(counter)).GetName() << endl;

//    foodAndPrice New;

//    eachRestantFood.push_back(New);

//    eachRestantFood.at(counter).name = (restaurantList.at(stopKey.at(counter)).GetName());

//    qDebug() << "menu size: " << restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().size() << endl;

//    for(unsigned int i = 0; i < restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().size() ; i++) //(unsigned int i = 0; i < restaurantList.size(); i++)
//    {
//        QString price = QString::number(restaurantList.at(stopKey.at(counter)).
//                                        GetMenuItemsOfRestaurant().at(i).
//                                        GetItemPrice());

//        QCheckBox *thisCheckBox = new QCheckBox(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() + " - $" + price, this); //(restaurantList.at(1).GetName(), this);
//        ui -> verticalLayout->addWidget(thisCheckBox);

//        checkBoxList.push_back(thisCheckBox);
//    }

//    for(unsigned int i = 0; i < checkBoxList.size(); i++ )
//    {
//        qDebug() << "test " << i << endl;
//    }

//    if(counter == stopKey.size() - 1)
//    {
//        ui->Next_Button->hide();
//        ui->Submit_Button->show();
//    }
//}


//void restaurantStop::on_buttonBox_accepted()
//{

//    for(unsigned int i = 0; i < eachRestantFood.size(); i++)
//    {
//        qDebug() << "Restaurant: " << eachRestantFood.at(i).name << endl;

//        for(unsigned int j = 0; j < eachRestantFood.at(i).food.size(); j++)
//        {
//            qDebug() << "Food #" << j + 1 << eachRestantFood.at(i).food.at(j) << " - $" << eachRestantFood.at(i).price.at(j) << endl;
//        }
//    }


////    for(unsigned int i = 0; i < selectedFood.size(); i++ )
////    {
////        qDebug() << "#" << i+1<<" item " << selectedFood.at(i).GetItemName() << endl;
////    }
//}

//void restaurantStop::on_buttonBox_rejected()
//{
//   notExit = false;
//}

//void restaurantStop::on_Next_Button_clicked()
//{
//    for(unsigned int i = 0; i < checkBoxList.size(); i++)
//    {
//        if(checkBoxList.at(i)->checkState())
//        {
//            qDebug() << "adding " <<  restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() << endl;

//            selectedFood.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i));

//            eachRestantFood.at(counter).food.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName());
//            eachRestantFood.at(counter).price.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
//        }
//    }

//    for(unsigned int i = 0; i < checkBoxList.size(); i++)
//    {
//        delete checkBoxList.at(i);

//    }

//    checkBoxList.clear();

//    if(counter <= stopKey.size() - 1)
//    {
//        counter++;
//        fillCheckBoxes();
//    }
//}

//void restaurantStop::on_Submit_Button_clicked()
//{
//    for(unsigned int i = 0; i < checkBoxList.size(); i++)
//    {
//        if(checkBoxList.at(i)->checkState())
//        {
//            qDebug() << "adding " <<  restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName() << endl;
//            selectedFood.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i));

//            eachRestantFood.at(counter).food.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemName());
//            eachRestantFood.at(counter).price.push_back(restaurantList.at(stopKey.at(counter)).GetMenuItemsOfRestaurant().at(i).GetItemPrice());
//        }
//    }

//    ui->Submit_Button->setEnabled(false);

//    for(unsigned int i = 0; i < checkBoxList.size(); i++)
//    {
//        checkBoxList.at(i)->setEnabled(false);
//    }

//    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
//}
