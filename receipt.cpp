#include "receipt.h"
#include "ui_receipt.h"
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QFont>


receipt::receipt(vector<foodAndPrice> foodList, double totalDistance1, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receipt)
{
    totalDistance = totalDistance1;

    for(unsigned int j = 0; j < foodList.size(); j++)
    {
        foodAndPrice New;

        boughtList.push_back(New);

        boughtList.at(j).name =  foodList.at(j).name;
        boughtList.at(j).distance =  foodList.at(j).distance;

        for(unsigned int i = 0; i < foodList.at(j).food.size(); i++)
        {
            boughtList.at(j).food.push_back(foodList.at(j).food.at(i));
            boughtList.at(j).price.push_back(foodList.at(j).price.at(i));
        }
    }

    rowCount = 1;

    ui->setupUi(this);
}

void receipt::printTable()
{
    ui->buttonBox->hide();
    ui->label->hide();

    QTableWidget *table = new QTableWidget();
    //item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table->setWordWrap(false);

    for(unsigned int i = 0; i < boughtList.size(); i++)
    {
        for(unsigned int j = 0; j < boughtList.at(i).food.size(); j++)
        {
            rowCount++;
        }
        rowCount++;
    }

    table->setRowCount(rowCount);
    table->setColumnCount(4);

    table->setItem(0, 0, new QTableWidgetItem("Restaurant"));
    table->setItem(0, 1, new QTableWidgetItem("Food Items"));
    table->setItem(0, 2, new QTableWidgetItem("Food Price"));
    table->setItem(0, 3, new QTableWidgetItem("Saddleback Distance"));

    table->setColumnWidth(1,200);
    table->setColumnWidth(2,70);
    table->setColumnWidth(3,114);

    for(int i= 0; i < rowCount;i++)
    {
        table->setRowHeight(i,15);
    }


    table->setShowGrid(false);

    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);

    int col = 0;
    int row = 1;
    double price = 0.0;
    double grandTotal = 0.0;

    //QFont x;
    //x.setBold(true);

    for(unsigned int i = 0; i < boughtList.size(); i++)
    {
      //  table->item(row,col)->setFont(x);
        table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name));

        table->setItem(row, col + 3, new QTableWidgetItem(QString::number(boughtList.at(i).distance) + " miles"));

        for(unsigned int j = 0; j < boughtList.at(i).food.size(); j++)
        {
            col++;
            table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).food.at(j) + ".........................................................................."));
            col++;
            table->setItem(row, col, new QTableWidgetItem("$" + QString::number(boughtList.at(i).price.at(j),'f',2)));
            price += boughtList.at(i).price.at(j);
            col=0;
            row++;
        }
        col++;
        //table->item(row,col)->setFont(x);
        //table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name + " total:"));

        col++;
        //table->setItem(row, col, new QTableWidgetItem("$"+ QString::number(price)));
        grandTotal += price;
        price = 0.0;
        col = 0;
        row++;
    }
    //table->item(row,col)->setFont(bold);
    //table->setItem(row, 1, new QTableWidgetItem("Grand Total:"));

    //table->setItem(row, 2, new QTableWidgetItem("$" + QString::number(grandTotal)));
    ui->scrollArea->setWidget(table);
}


void receipt::printReceipt()
{
    ui->scrollArea->resize(391,391);

    ui->label->setText("Total Distance (miles):\n" + QString::number(totalDistance));

    QTableWidget *table = new QTableWidget();
    //item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table->setWordWrap(false);

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

    table->setItem(0, 0, new QTableWidgetItem("Restaurant"));
    table->setItem(0, 1, new QTableWidgetItem("Food Items"));
    table->setItem(0, 2, new QTableWidgetItem("Food Price"));

    table->setColumnWidth(1,200);
    table->setColumnWidth(2,70);

    for(int i= 0; i < rowCount;i++)
    {
        table->setRowHeight(i,15);
    }


    table->setShowGrid(false);

    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);

    int col = 0;
    int row = 1;
    double price = 0.0;
    double grandTotal = 0.0;

    //QFont x;
    //x.setBold(true);

    for(unsigned int i = 0; i < boughtList.size(); i++)
    {
      //  table->item(row,col)->setFont(x);
        table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name));

        for(unsigned int j = 0; j < boughtList.at(i).food.size(); j++)
        {
            col++;
            table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).food.at(j) + ".........................................................................."));
            col++;
            table->setItem(row, col, new QTableWidgetItem("$" + QString::number(boughtList.at(i).price.at(j),'f',2)));
            price += boughtList.at(i).price.at(j);
            col=0;
            row++;
        }
        col++;
        //table->item(row,col)->setFont(x);
        table->setItem(row, col, new QTableWidgetItem(boughtList.at(i).name + " total:"));

        col++;
        table->setItem(row, col, new QTableWidgetItem("$"+ QString::number(price,'f',2)));
        grandTotal += price;
        price = 0.0;
        col = 0;
        row++;
        row++;
    }
    //table->item(row,col)->setFont(bold);
    table->setItem(row, 1, new QTableWidgetItem("Grand Total:"));

    table->setItem(row, 2, new QTableWidgetItem("$" + QString::number(grandTotal,'f',2)));
    ui->scrollArea->setWidget(table);

}


receipt::~receipt()
{
    delete ui;
}
