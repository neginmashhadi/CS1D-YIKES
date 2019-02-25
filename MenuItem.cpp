#include "menuitem.h"

MenuItem::MenuItem()
{
    name  = "";
    id    = 0;
    price = 0;
}

MenuItem::MenuItem(QString itemName, int rID, double itemPrice)
{
    name  = itemName;
    id    = rID;
    price = itemPrice;
}

void MenuItem::SetItemName(QString itemName)
{
    this->name = itemName;
}

QString MenuItem::GetItemName()
{
    return name;
}

void MenuItem::SetRestaurantID(int rID)
{
    this->id = rID;
}

int MenuItem::GetRestaurantID()
{
    return id;
}

void MenuItem::SetPrice(double itemPrice)
{
    this->price = itemPrice;
}

double MenuItem::GetItemPrice()
{
    return price;
}
