#include "database.h"

Database::Database()
{
    rDatabase = QSqlDatabase::addDatabase("QSQLITE");
    rDatabase.setDatabaseName("C:/Users/Jeff/Desktop/db/Restaurants.db");

    if(!rDatabase.open())
    {
        qDebug() << "Not connected to DB.";
    }
    else
    {
        qDebug() << "Connected to DB.";
    }

}

void Database::InputFileToDatabase(const QString& path)
{
    QFile inFile(path);
    QString restaurantName;
    QString ID;

    if(!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open the file for writing to database...";
        return;
    }

    QSqlQuery query(rDatabase);
    QTextStream in(&inFile);
    QString testQuery = "CREATE TABLE RestaurantInfo ("
                        "NAME Qstring,"
                        "ID integer);";

    if(query.exec(testQuery))
    {
        qDebug() << "Data saved to table...";
    }
    else
    {
        qDebug() << "Write failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    QStringList text = in.readLine().split(": ");
    restaurantName = text[1];

    qDebug() << "Name read as: " << restaurantName;

    text = in.readLine().split("number ");
    ID = text[1];
    qDebug() << "ID read as: " << ID;

    query.prepare("INSERT INTO RestaurantInfo (NAME, ID) VALUES (:Name, :RestID)");
    query.bindValue(":Name", restaurantName);
    query.bindValue(":RestID", ID);

    if(query.exec())
    {
        qDebug() << "Data saved to Restaurant table...";
    }
    else
    {
        qDebug() << "Write failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }


    inFile.close();

}
