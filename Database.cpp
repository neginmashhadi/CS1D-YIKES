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
    QString restaurantName;
    QString ID;
    QString destination;
    QString distanceInMiles;
    QString saddlebackDistance;
    QString countOfMenuItems;
    QString itemName;
    QString itemPrice;

    QFile inFile(path);

    if(!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open the file for writing to database...";
        return;
    }

    QSqlQuery query(rDatabase);
    QTextStream in(&inFile);
    QString restaurantQuery = "CREATE TABLE RestaurantInfo ("
                              "NAME QString,"
                              "ID integer,"
                              "SADDLEBACK DISTANCE double,"
                              "MENU SIZE integer,"
                              "NUMBER OF DESTINATIONS integer);";

    QString menuQuery = "CREATE TABLE MenuInfo ("
                        "NAME QString,"
                        "ID integer,"
                        "MENU ITEM double,"
                        "PRICE double);";

    QString distanceQuery = "CREATE TABLE DistanceInfo ("
                            "FROM QString,"
                            "ID integer,"
                            "DISTANCE TO double,"
                            "ID integer);";






    if(query.exec(restaurantQuery))
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

void Database::testDatabase()
{
    for(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        qDebug() << restaurantList.at(i).GetName();
        qDebug() << "Restaurant ID: " << restaurantList.at(i).GetID();
        qDebug() << "Distances to other restaurants: " << restaurantList.at(i).GetTotalDistance();

        unsigned int totalDistances = restaurantList.at(i).GetTotalDistance();
        for(unsigned int j = 0; j < totalDistances; j++)
        {
            qDebug() << restaurantList.at(i).GetDistancesToRestaurants().at(j).GetNextID() << " " << restaurantList.at(i).GetDistancesToRestaurants().at(j).GetMiles();
        }

        qDebug() << "Distance from saddleback: " << restaurantList.at(i).GetSaddlebackDistance();

        unsigned int menuSize = restaurantList.at(i).GetSize();
        qDebug() << "Menu size: " << menuSize;
        for(unsigned int k = 0; k < menuSize; k++)
        {
            qDebug() << restaurantList.at(i).GetMenuItemsOfRestaurant().at(k).GetRestaurantID()
                     << " " << restaurantList.at(i).GetMenuItemsOfRestaurant().at(k).GetItemName()
                     << " " << restaurantList.at(i).GetMenuItemsOfRestaurant().at(k).GetItemPrice();
        }
        qDebug() << "";
    }
}

