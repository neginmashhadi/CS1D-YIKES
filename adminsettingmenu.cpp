#include "adminsettingmenu.h"
#include "ui_adminsettingmenu.h"
#include <QDebug>
#include "Database.h"
#include <QMessageBox>

AdminSettingMenu::AdminSettingMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminSettingMenu)
{
    next = -1;

    ui->setupUi(this);

    ui->RestaurantAdd->hide();
    ui->RestaurantDelete->hide();
    ui->Reinitialize->hide();
    ui->ItemAdd->hide();
    ui->ItemDelete->hide();
    ui->ItemEdit->hide();
}

AdminSettingMenu::~AdminSettingMenu()
{
    delete ui;
}

void AdminSettingMenu::on_buttonBox_rejected()
{
    back = true;
}

bool AdminSettingMenu::returnBack()
{
    return back;
}

int AdminSettingMenu::returnNext()
{
    return next;
}

bool AdminSettingMenu::returnNotSelected()
{
    return notSelected;
}

void AdminSettingMenu::on_buttonBox_accepted()
{

    if(ui->RestaurantAdd->isChecked())
    {
        next = 1;
    }
    else if(ui->RestaurantDelete -> isChecked())
    {
        next = 2;
    }
    else if(ui->Reinitialize->isChecked())
    {
        next = 3;
    }
    else if(ui->ItemAdd->isChecked())
    {
        next = 4;
    }
    else if(ui->ItemDelete->isChecked())
    {
        next = 5;
    }
    else if(ui->ItemEdit->isChecked())
    {
        next = 6;
    }

    qDebug() << "the next is " << next << endl;


    if(next != -1)
    {
        notSelected = true;
    }
    else
    {
        notSelected = false;
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No Settings Selected");

    }
}

void AdminSettingMenu::on_RestaurantButton_clicked()
{
    ui->RestaurantAdd->show();
    ui->RestaurantDelete->show();
    ui->Reinitialize->show();

    ui->ItemAdd->hide();
    ui->ItemDelete->hide();
    ui->ItemEdit->hide();
}

void AdminSettingMenu::on_ItemButton_clicked()
{
    ui->ItemAdd->show();
    ui->ItemDelete->show();
    ui->ItemEdit->show();

    ui->RestaurantAdd->hide();
    ui->RestaurantDelete->hide();
    ui->Reinitialize->hide();
}
