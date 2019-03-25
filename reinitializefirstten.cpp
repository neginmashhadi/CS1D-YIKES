#include "reinitializefirstten.h"
#include "ui_reinitializefirstten.h"

ReinitializeFirstTen::ReinitializeFirstTen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReinitializeFirstTen)
{
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

ReinitializeFirstTen::~ReinitializeFirstTen()
{
    delete ui;
}

void ReinitializeFirstTen::on_pushButton_clicked()
{
    clicked = true;

    ui->pushButton->setEnabled(false);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
}

bool ReinitializeFirstTen::getClicked()
{
    return clicked;
}
