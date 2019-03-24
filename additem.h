#ifndef ADDITEM_H
#define ADDITEM_H

#include "Restaurant.h"
#include <QRadioButton>
#include <QDialog>
#include <QString>

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = nullptr);
    void     fillCheckBoxes(vector<Restaurant> restaurant);
    int      getRestaurantID();
    int      getOtherID();
    QString  getFoodName();
    double   getFoodPrice();


    ~AddItem();

private slots:
    void on_buttonBox_accepted();

    void on_Next_Button_clicked();

    void on_Submit_clicked();

private:
    Ui::AddItem *ui;
    int restaurantID;
    QString foodName;
    double  foodPrice;
    int otherID;
    vector<Restaurant> restaurantList;
    vector<Restaurant> restaurantList2;
    vector<QRadioButton*> buttonList;
};

#endif // ADDITEM_H
