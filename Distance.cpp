#include "distance.h"

Distance::Distance()
{
    miles               = 0;
    currentRestaurantID = 0;
    nextRestaurantID    = 0;
}

Distance::Distance(float dMiles, int currentID, int nextID)
{
    miles               = dMiles;
    currentRestaurantID = currentID;
    nextRestaurantID    = nextID;
}

void Distance::SetMiles(float dMiles)
{
    this->miles = dMiles;
}

float Distance::GetMiles()
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
