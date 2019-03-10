#ifndef CUSTOMTRIPMENU_H
#define CUSTOMTRIPMENU_H

#include <QDialog>
#include <vector>
#include <string>
#include "Restaurant.h"
#include <qcheckbox.h>

using namespace std;

namespace Ui {
class CustomTripMenu;
}

class CustomTripMenu : public QDialog//, public MainWindow
{
    Q_OBJECT

public:
    explicit CustomTripMenu(QWidget *parent);
    bool returnBack();
    void fillCheckBoxes(vector<Restaurant> restaurant);
    vector<Restaurant> ReturnSelectedRestaurant();
    vector<int> ReturnIDsChosenRestaurants();
    bool returnNotSelected();
    float returnTotalDistance();

    ~CustomTripMenu();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::CustomTripMenu *CTui;
    bool back {false};
    bool notSelected;
    float totalDistance;
    vector<Restaurant> restaurantList;
    vector<QCheckBox*> checkBoxList;
    vector<Restaurant> selectedRestaurant;
    vector<int> IDsChosenRestaurants;
};

#endif // CUSTOMTRIPMENU_H
