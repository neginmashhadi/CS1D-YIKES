#include "Restaurant.h"

Restaurant::Restaurant()
{
    name               = "";
    id                 = 0;
    saddlebackDistance = 0;
    size               = 0;
    totalDistance      = 0;

}

Restaurant::Restaurant(QString rName, int rID, double rSaddlebackDistance, int rSize, int rTotalDistance)
{
    name               = rName;
    id                 = rID;
    saddlebackDistance = rSaddlebackDistance;
    size               = rSize;
    totalDistance      = rTotalDistance;

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
    this->totalDistance = rTotalDistance;
}

int Restaurant::GetTotalDistance()
{
    return totalDistance;
}

void Restaurant::SetTotalAmountSpent(float amount)
{
    this->totalSpent = amount;
}

float Restaurant::GetTotalAmountSpent()
{
    return totalSpent;
}

void Restaurant::SetVisitedLocation(bool rVisitedLocation)
{
    this->visitedLocation = rVisitedLocation;
}

bool Restaurant::GetVistedLocation()
{
    return this->visitedLocation;
}

void Restaurant::StoreDistancesToRestaurants(Distance distance)
{
    distanceList.push_back(distance);
}

vector<Distance> Restaurant::GetDistancesToRestaurants()
{
    return distanceList;
}

float Restaurant::GetMilesFromRestaurantList(int index)
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

