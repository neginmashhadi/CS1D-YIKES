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

#include "restaurant.h"

using namespace std;

class Database
{
public:  
    Database();

    void InputFileToDatabase(const QString& path);

private:
    QSqlDatabase rDatabase;

};

#endif // DATABASE_H
