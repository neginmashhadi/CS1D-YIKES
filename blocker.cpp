#include "blocker.h"
#include "ui_blocker.h"

Blocker::Blocker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Blocker)
{
    ui->setupUi(this);
}

Blocker::~Blocker()
{
    delete ui;
}
