#ifndef MENUITEM_H
#define MENUITEM_H

#include <QString>

class MenuItem
{
public:
    MenuItem();

    MenuItem(QString itemName, int rID, float itemPrice);

    void SetItemName(QString itemName);

    QString GetItemName();

    void SetRestaurantID(int rID);

    int GetRestaurantID();

    void SetPrice(float itemPrice);

    float GetItemPrice();

private:
    QString name;
    int     id;
    float   price;


};

#endif // MENUITEM_H
