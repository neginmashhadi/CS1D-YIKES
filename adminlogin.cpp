#include "adminlogin.h"
#include "ui_adminlogin.h"
#include <QMessageBox>

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_buttonBox_accepted()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();
    if(username == "admin" && password == "pass000")
    {
        adminPrivA = true;
    }
    else
    {
        QMessageBox::critical(this, "Admin Login", "Wrong password and/or username.");
        AdminLogin *uiLogin = new AdminLogin(this);
        uiLogin->exec();
        if(uiLogin->GetAdminPriv())
        {
            this->adminPrivA = true;
        }
    }
}

void AdminLogin::on_buttonBox_rejected()
{}

bool AdminLogin::GetAdminPriv()
{
    return adminPrivA;
}
