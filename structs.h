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
    File: structs.h
    Class for holding the structs used throughout the program
*/

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
