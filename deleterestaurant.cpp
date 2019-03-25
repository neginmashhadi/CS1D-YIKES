#include "deleterestaurant.h"
#include "ui_deleterestaurant.h"
#include "Restaurant.h"
#include <QTableWidget>
#include <QString>
#include <QMessageBox>


deleteRestaurant::deleteRestaurant(vector<Restaurant> restaurants, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteRestaurant)
{
    ui->setupUi(this);

    for(unsigned int i = 0; i < restaurants.size(); i++ )
    {
        restaurantList.push_back(restaurants.at(i));
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);


}

int deleteRestaurant::getRestaurantID()
{
    return restaurantID;
}

void deleteRestaurant::fillTable()
{
    QTableWidget *table = new QTableWidget();
    //item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int rowCount = 1;

    for(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        rowCount++;
    }

    table->setRowCount(rowCount);
    table->setColumnCount(2);

    table->setItem(0, 0, new QTableWidgetItem("Restaurant"));
    table->setItem(0, 1, new QTableWidgetItem("ID"));

    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);

    //table->setShowGrid(false);

    int col = 0;
    int row = 1;

    for(unsigned int i = 0; i < restaurantList.size(); i++)
    {

        table->setItem(row, col, new QTableWidgetItem(restaurantList.at(i).GetName()));
        col++;
        table->setItem(row, col, new QTableWidgetItem( QString::number(restaurantList.at(i).GetID())));
        row++;
        col = 0;
    }

    ui->scrollArea->setWidget(table);
}

deleteRestaurant::~deleteRestaurant()
{
    delete ui;
}

void deleteRestaurant::on_pushButton_clicked()
{
   QString value =  ui->lineEdit->text();

   bool good = false;

   for(unsigned int i = 0; i < restaurantList.size() && !good; i++)
   {
       if(value == QString::number(restaurantList.at(i).GetID()))
       {
           restaurantID = restaurantList.at(i).GetID();
           good = true;
       }
   }

   if(!good)
   {
       QMessageBox messageBox;
       messageBox.critical(0,"Error",value + " Does Not Exist");
   }
   else
   {
       ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
       ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
       ui->pushButton->setEnabled(false);
   }
}
