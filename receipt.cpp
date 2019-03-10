#include "receipt.h"
#include "ui_receipt.h"
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>


receipt::receipt(vector<foodAndPrice> foodList, float totalDistance1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receipt)
{
    totalDistance = totalDistance1;

    for(unsigned int j = 0; j < foodList.size(); j++)
    {
        foodAndPrice New;

        boughtList.push_back(New);

        boughtList.at(j).name =  foodList.at(j).name;

        for(unsigned int i = 0; i < foodList.at(j).food.size(); i++)
        {
            boughtList.at(j).food.push_back(foodList.at(j).food.at(i));
            boughtList.at(j).price.push_back(foodList.at(j).price.at(i));
        }
    }

    rowCount = 1;

    ui->setupUi(this);
}

void receipt::printReceipt()
{

    QTableWidget *table = new QTableWidget();
    //item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    for(unsigned int i = 0; i < boughtList.size(); i++)
    {
        rowCount++;
        for(unsigned int j = 0; j < boughtList.at(i).food.size(); j++)
        {
            rowCount++;
        }
        rowCount++;
    }

    rowCount++;

    table->setRowCount(rowCount);
    table->setColumnCount(3);

    table->setItem(0, 0, new QTableWidgetItem("Restaurants"));
    table->setItem(0, 1, new QTableWidgetItem("Food Items"));
    table->setItem(0, 2, new QTableWidgetItem("Food Price"));

    table->setColumnWidth(1,200);
    table->setColumnWidth(2,80);

    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);

    int col = 0;
    int row = 1;
    float price = 0.0;
    float grandTotal = 0.0;
    for(unsigned int i = 0; i < boughtList.size(); i++)
    {
        for(unsigned int j = 0; j < boughtList.at(i).food.size(); j++)
        {
            table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name));
            col++;
            table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).food.at(j)));
            col++;
            table->setItem(row, col, new QTableWidgetItem("$" + QString::number(boughtList.at(i).price.at(j))));
            price += boughtList.at(i).price.at(j);
            col=0;
            row++;
        }
        //table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name));
        col++;
        table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name + " total:"));
        col++;
        table->setItem(row, col, new QTableWidgetItem("$"+ QString::number(price)));
        grandTotal += price;
        price = 0.0;
        col = 0;
        row++;
        row++;
    }

    table->setItem(row, 1, new QTableWidgetItem("Grand Total:"));
    table->setItem(row, 2, new QTableWidgetItem("$" + QString::number(grandTotal)));
    ui->scrollArea->setWidget(table);

}


receipt::~receipt()
{
    delete ui;
}
