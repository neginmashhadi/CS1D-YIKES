#ifndef SHORTESTTRIP_H
#define SHORTESTTRIP_H
#include "structs.h"
#include "Restaurant.h"
#include <QDialog>

namespace Ui {
class shortesttrip;
}

class shortesttrip : public QDialog
{
    Q_OBJECT

public:
    explicit shortesttrip(vector<Restaurant> restaurants,QWidget *parent = nullptr);
    ~shortesttrip();

    vector<int> ReturnIDsChosenRestaurants();

    bool returnBack();

    double returnTotalDistance();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::shortesttrip *ui;
    vector<Restaurant> restaurantList;
    vector<int> IDsChosenRestaurants;
    bool back {false};
    bool notSelected;
    double totalDistance;

};

#endif // SHORTESTTRIP_H
