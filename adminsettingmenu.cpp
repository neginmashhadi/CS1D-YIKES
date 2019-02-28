#include "adminsettingmenu.h"
#include "ui_adminsettingmenu.h"

AdminSettingMenu::AdminSettingMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminSettingMenu)
{
    ui->setupUi(this);
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

void AdminSettingMenu::on_buttonBox_accepted()
{
    if(ui->AD_Restaurant_Button->isChecked())
    {
        next = 1;
    }
    else if(ui->AD_Item_Button->isChecked())
    {
        next = 2;
    }
    else if(ui->AD_Item_Button->isChecked())
    {
        next = 3;
    }
}
