#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "MenuItem.h"
#include "Distance.h"
#include <QString>
#include <vector>
#include <string>
#include <list>
using namespace std;


class Restaurant
{
public:
    Restaurant();

    Restaurant(QString rName, int rID, double rSaddlebackDistance, int rSize, int rTotalDistances);

    void SetName(QString rName);

    QString GetName();

    void SetID(int rID);

    int GetID();

    void SetSaddlebackDistance(double rSaddlebackDistance);

    double GetSaddlebackDistance();

    void SetSize(int rSize);

    int GetSize();

    void SetTotalDistance(int rTotalDistances);

    int GetTotalDistance();

    void SetTotalAmountSpent(double amount);

    double GetTotalAmountSpent();

    void SetVisitedLocation(bool rVisitedLocation);

    bool GetVistedLocation();

    void StoreDistancesToRestaurants(Distance distance);

    vector<Distance> GetDistancesToRestaurants();

    double GetMilesFromRestaurantList(int index);

    void StoreMenuItemsOfRestaurant(MenuItem menuItem);

    vector<MenuItem> GetMenuItemsOfRestaurant();

    void AddMenuItem(MenuItem menuItem);

    void AddDistance(Distance distance);

    void setLocationID(int location);

    int getLocationID();

private:
    QString  name;
    int      id;
    int      locationID;
    double   saddlebackDistance;
    int      size;
    int      totalDistances;
    double   totalSpent;
    vector<Distance> distanceList;
    vector<MenuItem> menuItemList;

};

#endif // RESTAURANT_H
