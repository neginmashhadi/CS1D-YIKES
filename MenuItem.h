#ifndef MENUITEM_H
#define MENUITEM_H

#include <QString>

class MenuItem
{
public:
    MenuItem();

    MenuItem(QString itemName, int rID, double itemPrice);

    void SetItemName(QString itemName);

    QString GetItemName();

    void SetRestaurantID(int rID);

    int GetRestaurantID();

    void SetPrice(double itemPrice);

    double GetItemPrice();

private:
    QString name;
    int     id;
    double  price;


};

#endif // MENUITEM_H
