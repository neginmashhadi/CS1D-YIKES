#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "Database.h"

class DatabaseManager
{
public:
    DatabaseManager(QString path); /// Constructor

private:
    Database* DB;

};

#endif // DATABASEMANAGER_H
