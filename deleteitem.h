#ifndef DELETEITEM_H
#define DELETEITEM_H

#include "Restaurant.h"
#include <QDialog>
#include <QRadioButton>
#include <QCheckBox>

namespace Ui {
class DeleteItem;
}

class DeleteItem : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteItem(QWidget *parent = nullptr);

    void fillCheckBoxes(vector<Restaurant> restaurant);
    int getRestaurantID();
    int getDeletedID();
    vector<QString> getDeletedItems();
    vector<double> getDeletedPrices();
    ~DeleteItem();

private slots:
    void on_buttonBox_accepted();

    void on_next_button_clicked();

    void on_submit_button_clicked();

private:
    Ui::DeleteItem *ui;
    int restaurantID;
    int deletedID;
    vector<QString> deletedItems;
    vector<double>  deletedPrices;
    vector<Restaurant> restaurantList;
    vector<QRadioButton*> buttonList;
    vector<QCheckBox*>    checkButtonList;
};

#endif // DELETEITEM_H
