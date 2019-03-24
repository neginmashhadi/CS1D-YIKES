#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QCloseEvent>
#include <QDialog>
#include <vector>
#include <string>
#include <QDebug>
#include "Database.h"
using namespace std;

struct foodAndPrice
{
    QString name;
    double distance;
    vector<QString> food;
    vector<double> price;
};

void AddingRestaurants(bool checked, Database * DB);

void AddingRestaurantsPath(QString path, Database * DB);


#endif // FUNCTIONS_H
