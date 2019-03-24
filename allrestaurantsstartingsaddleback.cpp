#include "allrestaurantsstartingsaddleback.h"
#include "ui_allrestaurantsstartingsaddleback.h"

allRestaurantsStartingSaddleback::allRestaurantsStartingSaddleback(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allRestaurantsStartingSaddleback)
{
    ui->setupUi(this);
}

allRestaurantsStartingSaddleback::~allRestaurantsStartingSaddleback()
{
    delete ui;
}
