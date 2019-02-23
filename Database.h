#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QVector>
#include <QString>
#include <QDebug>
#include "restaurant.h"

class database
{
public:
    database();
    
    bool AddRestaurant(Restaurant add);
    
    void TestDatabase();
    
    QVector<QString> GetRestaurantsName();
    
    bool SearchForName(QString key);
    
    bool SearchForNumber(int key);
    
    void GetAllRestaurants(QVector<QString>& names, QVector<float> &distances);
    
    QVector<Restaurant> AllRestaurantInfo();
    
    Restaurant GetRestaurant(QString name);
    
    bool AddMenuItem(QString item, float price, QString name);
    
    bool DelteMenuItem(QString item, QString name);
    
    bool CheckMenuItem(QString name);
    
    bool ChangePrice(QString itemName, float newPrice);

private:
    QSqlDatabase db;

};

#endif // DATABASE_H
