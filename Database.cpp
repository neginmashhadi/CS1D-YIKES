#include "Database.h"

Database::Database()
{
    rDatabase = QSqlDatabase::addDatabase("QSQLITE");
    rDatabase.setDatabaseName("Restaurants.db");

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
                              "SADDLEBACK_DISTANCE float,"
                              "MENU_SIZE integer,"
                              "NUMBER_OF_DESTINATIONS integer);";

    QString menuQuery = "CREATE TABLE MenuInfo ("
                        "RESTAURANT_ID QString,"
                        "MENU_ITEM QString,"
                        "PRICE float);";

    QString distanceQuery = "CREATE TABLE DistanceInfo ("
                            "FROM_ID integer,"
                            "TO_ID integer,"
                            "DISTANCE float);";

    if(query.exec(restaurantQuery))
    {
        qDebug() << "Resturant Data Table Successfully Created!";
    }
    else
    {
        qDebug() << "Write failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    if(query.exec(menuQuery))
    {
        qDebug() << "Menu Data Table Successfully Created!";
    }
    else
    {
        qDebug() << "Write failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    if(query.exec(distanceQuery))
    {
        qDebug() << "Distance Data Table Successfully Created!";
    }
    else
    {
        qDebug() << "Write failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }


    while(!in.atEnd())
    {
        QStringList text = in.readLine().split(": ");
        restaurantName = text[1];

        qDebug() << "Name read as: " << restaurantName;

        text = in.readLine().split("number ");
        ID = text[1];

        qDebug() << "ID read as: " << ID;

        text = in.readLine().split("- ");
        QString countDestinations = text[1];

        bool isOk;
        int count = countDestinations.toInt(&isOk, 10);

        qDebug() << "Count read as: " << count;

        for(int i = 0; i < count; i++)
        {
            text = in.readLine().split(" ");
            destination = text[0];
            distanceInMiles = text[1];

            qDebug() << "destination ID read as: " << destination;
            qDebug() << "distance in miles read as: " << distanceInMiles;

            query.prepare("INSERT INTO DistanceInfo (FROM_ID, TO_ID, DISTANCE) "
                          "VALUES(:FROM, :TO, :DISTANCE)");
            query.bindValue(":FROM", destination);
            query.bindValue(":TO", ID);
            query.bindValue(":DISTANCE", distanceInMiles);

            if(query.exec())
            {
                qDebug() << "Data Saved To Distance Data Table Successfully!";
            }
            else
            {
                qDebug() << "Write failed...";
                qDebug() << query.lastError();
                qDebug() << query.executedQuery();
            }
        }

        text = in.readLine().split(" ");
        saddlebackDistance = text[0];

        qDebug() << "Distance to saddleback read as: " << saddlebackDistance;

        text = in.readLine().split(" ");
        countOfMenuItems = text[0];
        int numOfItems = countOfMenuItems.toInt(&isOk, 10);

        for(int i = 0; i < numOfItems; i++)
        {
            itemName = in.readLine();
            itemPrice = in.readLine();

            qDebug() << "item name read as: " << itemName;
            qDebug() << "price read as: " << itemPrice;

            query.prepare("INSERT INTO MenuInfo (RESTAURANT_ID, MENU_ITEM, PRICE) "
                          "VALUES(:REST_ID, :ITEM, :COST)");
            query.bindValue(":REST_ID", ID);
            query.bindValue(":ITEM", itemName);
            query.bindValue(":COST", itemPrice);

            if(query.exec())
            {
                qDebug() << "Data Saved To MenuInfo Data Table Successfully!";
            }
            else
            {
                qDebug() << "Write failed...";
                qDebug() << query.lastError();
                qDebug() << query.executedQuery();
            }
        }

        query.prepare("INSERT INTO RestaurantInfo (NAME, ID, SADDLEBACK_DISTANCE, MENU_SIZE, NUMBER_OF_DESTINATIONS) "
                      "VALUES(:NAME, :REST_ID, :DIST_TO_SC, :MENU_SIZE, :NUM_OF_DEST)");
        query.bindValue(":NAME", restaurantName);
        query.bindValue(":REST_ID", ID);
        query.bindValue(":DIST_TO_SC", saddlebackDistance);
        query.bindValue(":MENU_SIZE", countOfMenuItems);
        query.bindValue(":NUM_OF_DEST", countDestinations);

        if(query.exec())
        {
            qDebug() << "Data Saved To RestaurantInfo Data Table Successfully!";
        }
        else
        {
            qDebug() << "Write failed...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }

        in.readLine();

    }

    inFile.flush();
    inFile.close();

}

void Database::DatabaseToRestaurants()
{
    QSqlQuery restaurantQuery;
    QSqlQuery distanceQuery;
    QSqlQuery menuQuery;

    restaurantQuery.prepare("SELECT * FROM RestaurantInfo");
    if(!restaurantQuery.exec())
    {
        qDebug() << "Unable to execute query";
        qDebug() << restaurantQuery.lastError();
        qDebug() << restaurantQuery.executedQuery();
    }

    distanceQuery.prepare("SELECT * FROM DistanceInfo");
    if(!distanceQuery.exec())
    {
        qDebug() << "Unable to execute query";
        qDebug() << distanceQuery.lastError();
        qDebug() << distanceQuery.executedQuery();
    }

    menuQuery.prepare("SELECT * FROM MenuInfo");
    if(!menuQuery.exec())
    {
        qDebug() << "Unable to execute query";
        qDebug() << menuQuery.lastError();
        qDebug() << menuQuery.executedQuery();
    }

    while(restaurantQuery.next())
    {
        Restaurant restaurant;

        restaurant.SetName(restaurantQuery.value(0).toString());
        restaurant.SetID(restaurantQuery.value(1).toInt());
        restaurant.SetSaddlebackDistance(restaurantQuery.value(2).toString().toDouble());
        restaurant.SetSize(restaurantQuery.value(3).toInt());
        restaurant.SetTotalDistance(restaurantQuery.value(4).toInt());

        int count = 0;
        while(count < restaurant.GetTotalDistance())
        {
            distanceQuery.next();
            Distance distance;
            distance.SetMiles(distanceQuery.value(2).toFloat());
            distance.SetCurrentRestaurantID(restaurant.GetID());
            distance.SetNextID(distanceQuery.value(1).toInt());
            restaurant.StoreDistancesToRestaurants(distance);
            count++;
        }

        count = 0;
        while(count < restaurant.GetSize())
        {
            menuQuery.next();
            MenuItem menuItem;
            menuItem.SetItemName(menuQuery.value(1).toString());
            menuItem.SetRestaurantID(menuQuery.value(0).toInt());
            menuItem.SetPrice(menuQuery.value(2).toFloat());
            restaurant.StoreMenuItemsOfRestaurant(menuItem);
            count++;
        }
        restaurantList.push_back(restaurant);
    }
}


void Database::testDatabase()
{
    for(unsigned int i = 0; i < restaurantList.size(); i++)
    {
        qDebug() << restaurantList.at(i).GetName();
        qDebug() << "Restaurant ID: " << restaurantList.at(i).GetID();
        qDebug() << "Distances to other restaurants: " << restaurantList.at(i).GetTotalDistance();

        int totalDistances = restaurantList.at(i).GetTotalDistance();
        for(unsigned int j = 0; j < totalDistances; j++)
        {
            qDebug() << restaurantList.at(i).GetDistancesToRestaurants().at(j).GetNextID() << " " << restaurantList.at(i).GetDistancesToRestaurants().at(j).GetMiles();
        }

        qDebug() << "Distance from saddleback: " << restaurantList.at(i).GetSaddlebackDistance();

        int menuSize = restaurantList.at(i).GetSize();
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

void Database::DeleteFromDatabase(QString name)
{
    QSqlQuery query;

    query.prepare("DELETE FROM RestaurantInfo Where NAME = :RESTAURANT");

    query.bindValue(":RESTAURANT", name);

    query.exec();
    qDebug() << query.lastError();
    qDebug() << query.executedQuery();

    std::vector<Restaurant>::iterator it;
    for(it = restaurantList.begin(); it != restaurantList.end(); it++)
    {
        if(it->GetName() == name)
        {
            restaurantList.erase(it);
            break;
        }
    }
}

vector<Restaurant> Database::GetRestuarantList()
{
    return restaurantList;
}
