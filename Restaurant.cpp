#include "Restaurant.h"

Restaurant::Restaurant()
{
    name               = "";
    id                 = 0;
    saddlebackDistance = 0;
    size               = 0;
    totalDistances     = 0;

}

Restaurant::Restaurant(QString rName, int rID, double rSaddlebackDistance, int rSize, int rTotalDistances)
{
    name               = rName;
    id                 = rID;
    saddlebackDistance = rSaddlebackDistance;
    size               = rSize;
    totalDistances     = rTotalDistances;

}

void Restaurant::SetName(QString rName)
{
    this->name = rName;
}

QString Restaurant::GetName()
{
    return name;
}

void Restaurant::SetID(int rID)
{
    this->id = rID;
}

int Restaurant::GetID()
{
    return id;
}

void Restaurant::SetSaddlebackDistance(double rSaddlebackDistance)
{
    this->saddlebackDistance = rSaddlebackDistance;
}

double Restaurant::GetSaddlebackDistance()
{
    return saddlebackDistance;
}

void Restaurant::SetSize(int rSize)
{
    this->size = rSize;
}

int Restaurant::GetSize()
{
    return size;
}

void Restaurant::SetTotalDistance(int rTotalDistance)
{
    this->totalDistances = rTotalDistance;
}

int Restaurant::GetTotalDistance()
{
    return totalDistances;
}

void Restaurant::SetTotalAmountSpent(double amount)
{
    this->totalSpent = amount;
}

double Restaurant::GetTotalAmountSpent()
{
    return totalSpent;
}

void Restaurant::StoreDistancesToRestaurants(Distance distance)
{
    distanceList.push_back(distance);
}

vector<Distance> Restaurant::GetDistancesToRestaurants()
{
    return distanceList;
}

double Restaurant::GetMilesFromRestaurantList(int index)
{
    return distanceList.at(index).GetMiles();
}

void Restaurant::StoreMenuItemsOfRestaurant(MenuItem menuItem)
{
    menuItemList.push_back(menuItem);
}

vector<MenuItem> Restaurant::GetMenuItemsOfRestaurant()
{
    return menuItemList;
}

void Restaurant::AddMenuItem(MenuItem menuItem)
{
    menuItemList.push_back(menuItem);
}

void Restaurant::AddDistance(Distance distance)
{
    distanceList.push_back(distance);
}

void Restaurant::setLocationID(int location)
{
    locationID = location;
}

int Restaurant::getLocationID()
{
    return locationID;
}
