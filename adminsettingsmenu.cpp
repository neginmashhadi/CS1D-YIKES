#include "adminsettingsmenu.h"
#include "mainwindow.h"
#include "ui_adminsettingsmenu.h"

AdminSettingsMenu::AdminSettingsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminSettingsMenu)
{
    ui->setupUi(this);

    //back = false;
}

AdminSettingsMenu::~AdminSettingsMenu()
{
    delete ui;
}

bool AdminSettingsMenu::returnBack()
{
    return true;
}

void AdminSettingsMenu::on_buttonBox_rejected()
{
    back = true;
}
