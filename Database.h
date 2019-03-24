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

class Database
{
public:
    Database();
    Database(const QString& path);
    ~Database();

    bool isOpen() const;

    void CreateTables();

    void PrintAllRestaurants() const;

    bool AddRestaurant(QString restaurantName, int ID, double saddlebackDistance, int countOfMenuItems, int countDestinations);
    bool AddRestaurant(const QString &namein, QString distance, QString size);

    bool AddMenuItem(int ID, QString itemName, double price);

    bool AddDistance(int fromID, int toID, double distance);
    bool AddDistance(QString fromID, QString toID, QString miles);

    bool DeleteRestaurant(int ID);

    bool DeleteMenuItem(int ID, vector<QString> itemName, vector<double> price);

    bool RemoveRestaurant(int id);
    bool RemoveRestaurant(QString name);

    bool RemoveMenuItem(int id);
    bool RemoveMenuItem(QString name);

    bool RemoveDistance(int id);
    bool RemoveDistance(int fromID, int toID);

    bool RestaurantExists(int id) const;
    bool RestaurantExists(QString name) const;

    bool MenuItemExists(int id) const;
    bool MenuItemExists(QString name) const;

    bool DistanceExists(int id) const;
    bool DistanceExists(int fromID, int toID) const;

    bool EditRestaurant(QString restaurantName, int ID, double saddlebackDistance, int countOfMenuItems, int countDestinations);
    void EditTotalDistances(int ID, int total);
    void SetRestaurantName(const QString &name, int id) const;
    void SetRestaurantName(QString oldName, QString newName);
    void SetRestaurantDistance(double distance, int id) const;
    void SetRestaurantDistance(QString name, double distance);
    void SetMenuSize(int size, int id) const;

    bool EditMenuItem(int ID,QString oldItemName, QString itemName, double price);
    void SetItemName(int id, QString newName);
    void SetItemName(QString oldName, QString newName);
    void SetItemPrice(int id, double price);
    void SetItemPrice(QString name, double price);
    void SetItemID(QString name, int newID);
    void SetItemID(int oldID, int newID);

    void SetFromID(int fromID, int toID, int newFromID);
    void SetToID(int fromID, int toID, int newToID);
    void SetDistanceMiles(int fromID, double miles);
    void SetDistanceMiles(int fromID, int toID, double miles);

    QString GetRestaurantName(int id);
    double GetRestaurantDistance(int id);
    int GetRestaurantMenuSize(int id);

    void InputFileToDatabase(const QString& path);
    vector<Restaurant>* InputNewFileToDatabase(const QString& path);
    void DatabaseToRestaurants();

    vector<Restaurant> GetRestuarantList();
    void ClearRestaurantList();
    QSqlDatabase GetDatabase();

    void testDatabase();

private:
    QSqlDatabase       rDatabase;
    vector<Restaurant> restaurantList;

};

#endif // DATABASE_H
