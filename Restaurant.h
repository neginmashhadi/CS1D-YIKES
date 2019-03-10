#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "MenuItem.h"
#include "Distance.h"
#include <QString>
#include <vector>
#include <string>
using namespace std;


class Restaurant
{
public:
    Restaurant();

    Restaurant(QString rName, int rID, double rSaddlebackDistance, int rSize, int rTotalDistance);

    void SetName(QString rName);

    QString GetName();

    void SetID(int rID);

    int GetID();

    void SetSaddlebackDistance(double rSaddlebackDistance);

    double GetSaddlebackDistance();

    void SetSize(int rSize);

    int GetSize();

    void SetTotalDistance(int rTotalDistance);

    int GetTotalDistance();

    void SetTotalAmountSpent(float amount);

    float GetTotalAmountSpent();

    void SetVisitedLocation(bool rVisitedLocation);

    bool GetVistedLocation();

    void StoreDistancesToRestaurants(Distance distance);

    vector<Distance> GetDistancesToRestaurants();

    float GetMilesFromRestaurantList(int index);

    void StoreMenuItemsOfRestaurant(MenuItem menuItem);

    vector<MenuItem> GetMenuItemsOfRestaurant();

private:
    QString  name;
    int      id;
    double   saddlebackDistance;
    int      size;
    int      totalDistance;

    float    totalSpent;
    bool     visitedLocation;

    vector<Distance> distanceList;
    vector<MenuItem> menuItemList;

};

#endif // RESTAURANT_H
