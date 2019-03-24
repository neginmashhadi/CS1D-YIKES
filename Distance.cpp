#include "Distance.h"

Distance::Distance()
{
    miles               = 0;
    currentRestaurantID = 0;
    nextRestaurantID    = 0;
}

Distance::Distance(double dMiles, int currentID, int nextID)
{
    miles               = dMiles;
    currentRestaurantID = currentID;
    nextRestaurantID    = nextID;
}

void Distance::SetMiles(double dMiles)
{
    this->miles = dMiles;
}

double Distance::GetMiles()
{
    return miles;
}

void Distance::SetCurrentRestaurantID(int currentID)
{
    this->currentRestaurantID = currentID;
}

int Distance::GetCurrentRestaurantID()
{
    return currentRestaurantID;
}

void Distance::SetNextID(int nextID)
{
    this->nextRestaurantID = nextID;
}

int Distance::GetNextID()
{
    return nextRestaurantID;
}
