#ifndef CUSTOMTRIPMENU_H
#define CUSTOMTRIPMENU_H

#include <QDialog>
#include <vector>
#include <string>
#include "Restaurant.h"
#include <qcheckbox.h>
#include <QButtonGroup>

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
    double returnTotalDistance();

    ~CustomTripMenu();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::CustomTripMenu *CTui;
    bool back {false};
    bool notSelected;
    double totalDistance;
    int first;
    QButtonGroup group;
    vector<Restaurant> restaurantList;
    vector<QCheckBox*> checkBoxList;
    vector<Restaurant> selectedRestaurant;
    vector<int> IDsChosenRestaurants;
};

#endif // CUSTOMTRIPMENU_H
