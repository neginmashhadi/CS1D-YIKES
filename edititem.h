#ifndef EDITITEM_H
#define EDITITEM_H

#include <QDialog>
#include <Restaurant.h>
#include <QString>
#include <QRadioButton>

namespace Ui {
class EditItem;
}

class EditItem : public QDialog
{
    Q_OBJECT

public:
    explicit EditItem(QWidget *parent = nullptr);
    void fillCheckBoxes(vector<Restaurant> restaurant);
    QString getOldName();
    double  getOldPrice();
    QString getNewName();
    double  getNewPrice();
    int     getRestaurantID();
    int     getEditRestaurantID();
    bool    getExit();
    ~EditItem();

private slots:
    void on_next_button_clicked();

    void on_submit_button_clicked();

    void on_buttonBox_rejected();

private:
    Ui::EditItem *ui;
    int restaurantID;
    int editRestaurantID;

    QString oldName;
    double  oldPrice;

    QString newName;
    double  newPrice;

    int     next{0};

    bool exit{false};

    vector<Restaurant> restaurantList;
    vector<QRadioButton*> buttonList;
    vector<QRadioButton*> checkButtonList;
};

#endif // EDITITEM_H
