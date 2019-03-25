/*
 *  Fast Food Project
 *  Spring 2019
 *
 *  Oscar Lopez <olopez23@saddleback.edu>
 *  Jeff Adams <jadams62@saddleback.edu>
 *  Isaac Estrada <iestrada5@saddleback.edu>
 *  Caroline Ta <tta24@saddleback.edu>
 *  Negin Mashhadi <nmashhadi0@ivc.edu>
 *
 *  Descr: Fast Food Project for Spring 2019 CS1D
 *  Professor: Jerry Lebowitz
 *
 *  This program is an application in which a foodie
 *  at Saddleback College can plan various trips to
 *  fast food restaurants.
 *
 **/
/*
    File: Restaurant.h
    Class for storing variables for each specific restaurant
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "MenuItem.h"
#include "Distance.h"
#include <QString>
#include <vector>
#include <string>
#include <list>
using namespace std;

/**
 * @brief The Restaurant class - sets the data based on the restaurant
 */
class Restaurant
{
public:
    /**
     * @brief Restaurant - default constructor
     */
    Restaurant();
    /**
     * @brief Restaurant - constructor
     * @param rName      - name of restaurant
     * @param rID        - restaurant ID
     * @param rSaddlebackDistance - distance of restaurant from saddleback
     * @param rSize      - number of resturants
     * @param rTotalDistances - total distance foodie needs to travel for all the restaurants
     */
    Restaurant(QString rName, int rID, double rSaddlebackDistance, int rSize, int rTotalDistances);
    /**
     * @brief SetName - sets the name of the restaurant
     * @param rName   - name of the restaurant
     */
    void SetName(QString rName);
    /**
     * @brief GetName - returns the name of the restaurant
     * @return rName
     */
    QString GetName();
    /**
     * @brief SetID - sets the ID of the restaurant
     * @param rID   - restaurant ID
     */
    void SetID(int rID);
    /**
     * @brief GetID - retursn the ID of the restaurant
     * @return rID
     */
    int GetID();
    /**
     * @brief SetSaddlebackDistance - set the distance of the restaurant from saddleback
     * @param rSaddlebackDistance - the restaurant distance from saddleback
     */
    void SetSaddlebackDistance(double rSaddlebackDistance);
    /**
     * @brief GetSaddlebackDistance - gets the distance of the restaurant from saddleback
     * @return rSaddlebackDistance
     */
    double GetSaddlebackDistance();
    /**
     * @brief SetSize - sets the size of the restaurants
     * @param rSize   - number of restaurants
     */
    void SetSize(int rSize);
    /**
     * @brief GetSize - gets the size of the restaurants
     * @return rSize
     */
    int GetSize();
    /**
     * @brief SetTotalDistance - sets the total distance
     * @param rTotalDistances  - the total distances of the restaurants
     */
    void SetTotalDistance(int rTotalDistances);
    /**
     * @brief GetTotalDistance - returns the total distance
     * @return rTotalDistances
     */
    int GetTotalDistance();
    /**
     * @brief SetTotalAmountSpent - set the total amount of money spent
     * @param amount              - total amount of money
     */
    void SetTotalAmountSpent(double amount);
    /**
     * @brief GetTotalAmountSpent - returns the total amount of money spent
     * @return amount
     */
    double GetTotalAmountSpent();
    /**
     * @brief SetVisitedLocation - sets the locations foodies visited
     * @param rVisitedLocation   - checks if location has been visited
     */
    void SetVisitedLocation(bool rVisitedLocation);
    /**
     * @brief GetVistedLocation - returns if foodies has visited the location
     * @return rVisitedLocation
     */
    bool GetVistedLocation();
    /**
     * @brief StoreDistancesToRestaurants - stores the distances to resturants
     * @param distance - distnace to the restaurant
     */
    void StoreDistancesToRestaurants(Distance distance);

    vector<Distance> GetDistancesToRestaurants();
    /**
     * @brief GetMilesFromRestaurantList - returns the distance in miles
     * @param index - the ID
     * @return the mile of the selected ID
     */
    double GetMilesFromRestaurantList(int index);
    /**
     * @brief StoreMenuItemsOfRestaurant - stores all the menu items
     * @param menuItem - the item of the restaurant
     */
    void StoreMenuItemsOfRestaurant(MenuItem menuItem);

    vector<MenuItem> GetMenuItemsOfRestaurant();
    /**
     * @brief AddMenuItem   - adds an Item to the list of items in restaurant
     * @param menuItem      - the menu item
     */
    void AddMenuItem(MenuItem menuItem);
    /**
     * @brief AddDistance - adds a distance to the list of distances
     * @param distance    - distance of restaurant
     */
    void AddDistance(Distance distance);
    /**
     * @brief setLocationID - sets the location of the ID
     * @param location      - location of restaurant
     */
    void setLocationID(int location);
    /**
     * @brief getLocationID - returns the location of the ID
     * @return location
     */
    int getLocationID();

private:
    QString  name;  /**<name of the restaurant*/
    int      id;  /**<id of the restaurant*/
    int      locationID;  /**<location ID of the restaurant*/
    double   saddlebackDistance; /**<the distance to saddleback*/
    int      size;  /**<size of the menu items*/
    int      totalDistances; /**<total distances of each restaurant*/
    double   totalSpent; /**<total amount spent*/
    vector<Distance> distanceList;  /**<vector of distances*/
    vector<MenuItem> menuItemList;  /**<vector of menu items*/

};

#endif // RESTAURANT_H
