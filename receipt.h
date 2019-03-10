#ifndef RECEIPT_H
#define RECEIPT_H

#include <QDialog>
#include "functions.h"

namespace Ui {
class receipt;
}

class receipt : public QDialog
{
    Q_OBJECT

public:
    explicit receipt(vector<foodAndPrice> foodList, float totalDistance, QWidget *parent = nullptr);

    void printReceipt();

    ~receipt();

private:
    Ui::receipt *ui;
    vector<foodAndPrice> boughtList;
    float totalDistance;
    int rowCount;
    int colCount;
};

#endif // RECEIPT_H
