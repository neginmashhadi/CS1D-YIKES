#ifndef RESTAURANTSTOP_H
#define RESTAURANTSTOP_H

#include "structs.h"

#include <vector>
#include <string>
#include "Restaurant.h"
#include <qcheckbox.h>
#include <QSpinBox>

//struct foodAndPrice
//{
//    QString name;
//    vector<QString> food;
//    vector<float> price;
//};

namespace Ui {
class restaurantStop;
}

class restaurantStop : public QDialog
{
    Q_OBJECT

public:
    explicit restaurantStop(vector<Restaurant> restaurant, vector<int> keyList, QWidget *parent = nullptr);
    bool returnBack();
    void fillCheckBoxes();

    vector<foodAndPrice> returnEachRestantFood();

    bool returnNotExit();

    ~restaurantStop();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_Next_Button_clicked();

    void on_Submit_Button_clicked();

private:
    Ui::restaurantStop *ui;
    vector<Restaurant> restaurantList;
    vector<QCheckBox*> checkBoxList;
    vector<QSpinBox*> spinBoxList;
    vector<MenuItem> selectedFood;
    vector<foodAndPrice> eachRestantFood;
    vector<int> stopKey;

    bool notExit;

    int counter;
};

#endif // RESTAURANTSTOP_H
