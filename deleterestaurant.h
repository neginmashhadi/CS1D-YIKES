#ifndef DELETERESTAURANT_H
#define DELETERESTAURANT_H

#include <QHeaderView>
#include <QDialog>
#include "Restaurant.h"


namespace Ui {
class deleteRestaurant;
}

class deleteRestaurant : public QDialog
{
    Q_OBJECT

public:
    explicit deleteRestaurant(vector<Restaurant> restaurants, QWidget *parent = nullptr);
    void fillTable();
    int getRestaurantID();
    ~deleteRestaurant();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deleteRestaurant *ui;
    int restaurantID{-1};
    vector<Restaurant> restaurantList;
};

#endif // DELETERESTAURANT_H
