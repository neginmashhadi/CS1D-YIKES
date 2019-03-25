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
    File: Databasemanager.h
    Class for managing the database
*/

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "Database.h"


/**
@brief used to manage the Database
*/
class DatabaseManager
{
public:
    /** Default constructor of class DatabaseManager
    */
    DatabaseManager(QString path); // Constructor

private:
    Database* DB; /**<DB pointer to access the Database*/

};

#endif // DATABASEMANAGER_H
