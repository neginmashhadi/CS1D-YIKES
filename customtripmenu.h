#ifndef CUSTOMTRIPMENU_H
#define CUSTOMTRIPMENU_H

#include <QDialog>
#include <vector>
#include <string>
#include "mainwindow.h"
#include "Restaurant.h"

using namespace std;

namespace Ui {
class CustomTripMenu;
}

class CustomTripMenu : public QDialog//, public MainWindow
{
    Q_OBJECT

public:
    explicit CustomTripMenu(vector<Restaurant> restaurant, QWidget *parent);
    bool returnBack();
    void fillCheckBoxes();
    ~CustomTripMenu();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::CustomTripMenu *CTui;
    bool back {false};
    vector<Restaurant> restaurantList;
};

#endif // CUSTOMTRIPMENU_H
