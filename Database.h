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
    File: Database.h
    Class for the back end of the application,
    stores the information in an SQL database
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <string>

#include "Restaurant.h"

using namespace std;

/**
@brief Database header used to hold all information from input files
*/
class Database
{
    public:
    /** Default Constructor
    */
        Database();

    /** Constructor
    @param path - path to open input file
    */
        Database(const QString& path);

    /** Destructor
    */
        ~Database();

    /** Returns true if the database is open
    @return isOpen - returns true if database is open
    */
        bool isOpen() const;

    /** Function that creates the tables to store all information
    */
        void CreateTables();

    /** Function that prints all the restaurants
    */
        void PrintAllRestaurants() const;

    /** Boolean adds restaurant to the query
    @param restaurantName - string of the name of the restaurant
    @param ID - int of the ID of the restaurant
    @param saddlebackDistance - double of the distance from saddleback
    @param countOfMenuItems - the number of menu items for that restaurant
    @param countDestination - the number of destinations
    @return success - returns successful if added correctly
    */
        bool AddRestaurant(QString restaurantName, int ID, double saddlebackDistance, int countOfMenuItems, int countDestinations);

    /** Boolean adds restaurant to the query
    @param namein - string of the name of the restaurant
    @param distance - distance to saddleback
    @param size - size of the menu items
    @return success - returns successful if added correctly
    */
        bool AddRestaurant(const QString &namein, QString distance, QString size);

    /** Boolean adds menu items to a specific restaurant
    @param ID - int of the ID of the restaurant
    @param itemName - name of the item
    @param price - price of the item
    @return success - returns successful if added correctly
    */
        bool AddMenuItem(int ID, QString itemName, double price);

    /** Booleans add the distance from one restaurant to another
    @param fromID - starting restaurant
    @param toID - nextRestaurant
    @param distance - totalDistance
    @return success - returns successful if added correctly
    */
        bool AddDistance(int fromID, int toID, double distance);

    /** Booleans add the distance from one restaurant to another
    @param fromID - starting restaurant
    @param toID - nextRestaurant
    @param distance - totalDistance
    @return success - returns successful if added correctly
    */
        bool AddDistance(QString fromID, QString toID, QString miles);

    /** Boolean deletes a restaurant
    @param ID - the ID of the restaurant
    @return success - returns successful if added correctly
    */
        bool DeleteRestaurant(int ID);

    /** Boolean deletes a menu item
    @param ID - ID of the restaurant
    @param itemName - vector of ItemNames
    @param price - vector of prices
    @return success - returns successful if added correctly
    */
        bool DeleteMenuItem(int ID, vector<QString> itemName, vector<double> price);

    /** Boolean removes a restaurant
    @param ID - id of the restaurant
    @return success - returns successful if added correctly
    */
        bool RemoveRestaurant(int id);

    /** Boolean removes a restaurant
    @param name - name of the restaurant
    @return success - returns successful if added correctly
    */
        bool RemoveRestaurant(QString name);

    /** Boolean removes a menu item
    @param id - ID of the restaurant
    @return success - returns successful if added correctly
    */
        bool RemoveMenuItem(int id);

    /** Boolean removes a menu item
    @param name - name of the restaurant menu Item
    @return success - returns successful if added correctly
    */
        bool RemoveMenuItem(QString name);

    /** Boolean removes a distance (when restaurant is deleted
    @param id - id of the restaurant
    @return success - returns successful if added correctly
    */
        bool RemoveDistance(int id);

    /** Boolean removes a distance (when restaurant is deleted
    @param fromID - starting restaurant
    @param toID - the restaurant ID it is going to
    @return success - returns successful if added correctly
    */
        bool RemoveDistance(int fromID, int toID);

    /** Boolean checks if the restaurant exists
    @param id - id of the restaurant that will be checked
    @return exists - returns true if the restaurant exists
    */
        bool RestaurantExists(int id) const;

    /** Boolean checks if the restaurant exists
    @param name - name of the restaurant
    @return exists - returns true if the restaurant exists
    */
        bool RestaurantExists(QString name) const;

    /** Boolean checks if the restaurant has the menu item
    @param id - id of the restaurant
    @return exists - returns true if the restaurant has menu items
    */
        bool MenuItemExists(int id) const;

    /** Boolean checks if the menu item exists
    @param name - name of the restaurant
    @return exists - returns true if the restaurant has the menu item
    */
        bool MenuItemExists(QString name) const;

    /** Boolean checks if the distance exists
    @param id - ID of the restaurant
    @return exists - returns true if the distance exists
    */
        bool DistanceExists(int id) const;

    /** Boolena checks if distance exists
    @param fromID - starting restaurant ID
    @param toID - the other restaurant ID
    @return exists - returns true if the distance exists
    */
        bool DistanceExists(int fromID, int toID) const;

    /** Boolean edits the restaurant
    @param restaurantName - name of the restaurant
    @param ID - restaurant ID
    @param saddlebackDistance - distance to saddleback
    @param countOfMenuItems - amount of menu items in the restaurant
    @param countDestinations - amount of destinations available
    @return success - returns successful if edited correctly
    */
        bool EditRestaurant(QString restaurantName, int ID, double saddlebackDistance, int countOfMenuItems, int countDestinations);

    /** Function edits the total distances
    @param ID - id of the restaurant
    @param total - new total distances
    */
        void EditTotalDistances(int ID, int total);

    /** Function sets the restaurant name
    @param name - new Restaurant name
    @param id - restaurant ID
    */
        void SetRestaurantName(const QString &name, int id) const;

    /** Function sets the restaurant name
    @param oldName - old Restaurant name
    @param newName - new Restaurant name
    */
        void SetRestaurantName(QString oldName, QString newName);

    /** Function sets the Restaurant Distance
    @param distance - new distance
    @param id - Restaurant ID
    */
        void SetRestaurantDistance(double distance, int id) const;

    /** Function sets Restaurant Distance
    @param name - name of the restaurant
    @param distance - new distance
    */
        void SetRestaurantDistance(QString name, double distance);

    /** Function sets menu size
    @param size - new size of menu
    @param id - id of the restaurant
    */
        void SetMenuSize(int size, int id) const;

    /** Boolean edits a specific menu item
    @param ID - ID of the restaurant
    @param oldItemName - the old name of the menu item
    @param itemName - the new name of the menu item
    @param price - the new price of the menu item
    @return success - returns successfull if edited correctly
    */
        bool EditMenuItem(int ID,QString oldItemName, QString itemName, double price);

    /** Function sets the item name
    @param id - id of the restaurant
    @param newName - new name of the item
    */
        void SetItemName(int id, QString newName);

    /** Function sets the item name
    @param oldName - old name of the item
    @param newName - new name of the item
    */
        void SetItemName(QString oldName, QString newName);

    /** Function sets the item price
    @param id - id of the restaurant
    @param price - price of the new item
    */
        void SetItemPrice(int id, double price);

    /** Function sets the item price
    @param name - name of the item
    @param price - new price
    */
        void SetItemPrice(QString name, double price);

    /** Function sets the item ID
    @param name - name of the item
    @param newID - the new ID for the item
    */
        void SetItemID(QString name, int newID);

    /** Function sets the item ID
    @param oldID - the old ID of the item
    @param newID - new ID of the item
    */
        void SetItemID(int oldID, int newID);

    /** Function sets from the ID
    @param fromID - the first ID
    @param toID - the second ID
    @param newFromID - the new from ID
    */
        void SetFromID(int fromID, int toID, int newFromID);

    /** Function sets to the ID
    @param fromID - the first ID
    @param toID - the second ID
    @param newToID - the new To ID
    */
        void SetToID(int fromID, int toID, int newToID);

    /** Function sets the distance in miles
    @param fromID - the ID of the restaurant
    @param miles - distance in miles
    */
        void SetDistanceMiles(int fromID, double miles);

    /** Function sets the distance in miles
    @param fromID - the first ID
    @param toID - the second ID
    @param miles - the distance in miles
    */
        void SetDistanceMiles(int fromID, int toID, double miles);

    /** Function returns the restaurant name
    @param id - the restaurants ID
    @return name - the restaurants name
    */
        QString GetRestaurantName(int id);

    /** Function returns the restaurant distance to Saddleback
    @param id - the restaurants ID
    @return distance - returns the restaurants distance
    */
        double GetRestaurantDistance(int id);

    /** Function returns a specified restaurants menu size
    @param id - the restaurants ID
    @return size - returns the restaurants menu size
    */
        int GetRestaurantMenuSize(int id);

    /** Function reads from input file and stores data in database
    @param path - path of the input file
    */
        void InputFileToDatabase(const QString& path);

    /** Function returns a vector of the new restaurant list after reading from input file
    @param path - path to the new input file
    @return restaurantList - returns new restaurant list with added restaurants
    */
        vector<Restaurant>* InputNewFileToDatabase(const QString& path);

    /** Function reads database and inputs into restaurant vectors
    */
        void DatabaseToRestaurants();

    /** Function returns a vector of restaurants
    @return restaurantList - vector of restaurants
    */
        vector<Restaurant> GetRestuarantList();

    /** Function clears the restaurant list entirely
    */
        void ClearRestaurantList();

    /** Function returns the Sql Database with information stored
    @return database - database containing restaurant information
    */
        QSqlDatabase GetDatabase();

    /** Function tests the database to make sure it all works
    */
        void testDatabase();

    private:
        QSqlDatabase       rDatabase;   /**<Sql Database that holds all information*/
        vector<Restaurant> restaurantList;  /**<Creates a vector of type restaurant to hold all restaurants*/

};

#endif // DATABASE_H
