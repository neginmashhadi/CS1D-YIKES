#ifndef RECEIPT_H
#define RECEIPT_H

#include <QDialog>
#include "structs.h"

namespace Ui {
class receipt;
}

class receipt : public QDialog
{
    Q_OBJECT

public:
    explicit receipt(vector<foodAndPrice> foodList, double totalDistance, QWidget *parent = nullptr);
    void printTable();
    void printReceipt();

    ~receipt();

private:
    Ui::receipt          *ui;
    vector<foodAndPrice> boughtList;
    double               totalDistance;
    int                  rowCount;
    int                  colCount;
};

#endif // RECEIPT_H
