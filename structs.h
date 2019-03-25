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

/**
 * @brief AddingRestaurants c
 * @param checked - checks
 * @param DB - pointer to the data base
 */
void AddingRestaurants(bool checked, Database * DB);
/**
 * @brief AddingRestaurantsPath
 * @param path - the path of the input file
 * @param DB - pointer to data base
 */
void AddingRestaurantsPath(QString path, Database * DB);


#endif // FUNCTIONS_H
