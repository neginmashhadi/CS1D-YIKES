#include "addrestaurant.h"
#include "ui_addrestaurant.h"
#include <QLabel>
#include <QFile>
#include <QMessageBox>

addRestaurant::addRestaurant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRestaurant)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Close)->hide();
    clicked = false;
}

addRestaurant::~addRestaurant()
{
    delete ui;
}

bool addRestaurant::returnClicked()
{
    return clicked;
}

bool addRestaurant::getPathBool()
{
    return pathBool;
}

QString addRestaurant::getPath()
{
    return path;
}

void addRestaurant::on_pushButton_clicked()
{
    ui->buttonBox->button(QDialogButtonBox::Close)->show();
    ui->buttonBox->button(QDialogButtonBox::Cancel)->hide();

    ui->pushButton->hide();

    ui->pushButton_2->hide();

    ui->label->hide();
    ui->label_2->hide();

    ui->path->hide();

    QLabel *lable = new QLabel;
    lable->setText("Adding 2 New Restaurants...");

    ui->horizontalLayout->addWidget(lable);

    clicked = true;
}

void addRestaurant::on_pushButton_2_clicked()
{
    path = ui->path->text();

    if(QFile::exists(path))
    {
        ui->buttonBox->button(QDialogButtonBox::Close)->show();
        ui->buttonBox->button(QDialogButtonBox::Cancel)->hide();

        ui->path->setEnabled(false);
        pathBool = true;

        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);

    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error",path + "\nDoes not exist.");
    }
}
