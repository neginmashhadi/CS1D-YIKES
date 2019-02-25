#include "menuitem.h"

MenuItem::MenuItem()
{
    name  = "";
    id    = 0;
    price = 0;
}

MenuItem::MenuItem(QString itemName, int rID, float itemPrice)
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

void MenuItem::SetPrice(float itemPrice)
{
    this->price = itemPrice;
}

float MenuItem::GetItemPrice()
{
    return price;
}
