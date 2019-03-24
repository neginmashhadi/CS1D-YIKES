#include "Database.h"
#include <QMessageBox>

Database::Database(const QString& path)
{
    rDatabase = QSqlDatabase::addDatabase("QSQLITE");
    rDatabase.setDatabaseName(path);

    if(!rDatabase.open())
    {
        qDebug() << "Not connected to DB.";
    }
    else
    {
        qDebug() << "Connected to DB.";
    }
}

Database::Database()
{
}


Database::~Database()
{
    if(rDatabase.isOpen())
    {
        rDatabase.close();
        rDatabase.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

bool Database::isOpen() const
{
    return rDatabase.isOpen();
}

void Database::CreateTables()
{
    QSqlQuery query;

    QString restaurantQuery = "CREATE TABLE RestaurantInfo (NAME QString, ID integer, SADDLEBACK_DISTANCE float, MENU_SIZE integer, NUMBER_OF_DESTINATIONS integer);";

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

    QString menuQuery = "CREATE TABLE MenuInfo (RESTAURANT_ID QString, MENU_ITEM QString, PRICE float);";

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

    QString distanceQuery = "CREATE TABLE DistanceInfo (FROM_ID integer, TO_ID integer, DISTANCE float);";

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
}

void Database::PrintAllRestaurants() const
{
    qDebug() << "Restaurants in db:";

    QSqlQuery query("SELECT * FROM RestaurantInfo");

    while(query.next())
    {
        QString temp="";
        int idName = query.record().indexOf("ID");
        temp+=query.value(idName).toString();

        idName = query.record().indexOf("NAME");
        temp+=": " + query.value(idName).toString();

        idName = query.record().indexOf("SADDLEBACK_DISTANCE");
        temp+=" - Distance From Saddleback : " + query.value(idName).toString();

        qDebug() << temp;
    }
}

bool Database::AddRestaurant(QString restaurantName, int ID, double saddlebackDistance, int countOfMenuItems, int countDestinations)
{
    bool success = false;

    QSqlQuery query;

    query.prepare("INSERT INTO RestaurantInfo (NAME, ID, SADDLEBACK_DISTANCE, MENU_SIZE, NUMBER_OF_DESTINATIONS) "
                  "VALUES(:NAME, :REST_ID, :DIST_TO_SC, :MENU_SIZE, :NUM_OF_DEST)");
    query.bindValue(":NAME", restaurantName);
    query.bindValue(":REST_ID", ID);
    query.bindValue(":DIST_TO_SC", saddlebackDistance);
    query.bindValue(":MENU_SIZE", countOfMenuItems);
    query.bindValue(":NUM_OF_DEST", countDestinations);

    if(query.exec())
    {
        qDebug() << "Data Saved To RestaurantInfo Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Add Restaurant failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    return success;
}

bool Database::AddRestaurant(const QString &namein, QString dist, QString size)
{
    bool success = false;

    QSqlQuery query;

    query.prepare("INSERT INTO RestaurantInfo (NAME, SADDLEBACK_DISTANCE, MENU_SIZE) "
                  "VALUES(:NAME, :DIST_TO_SC, :MENU_SIZE");
    query.bindValue(":NAME", namein);
    query.bindValue(":DIST_TO_SC", dist);
    query.bindValue(":MENU_SIZE", size);

    if(query.exec())
    {
        qDebug() << "Data Saved To RestaurantInfo Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Add Restaurant failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();

    }
    return success;
}

bool Database::AddMenuItem(int ID, QString itemName, double price)
{
    bool success = false;

    QSqlQuery query;

    query.prepare("INSERT INTO MenuInfo (RESTAURANT_ID, MENU_ITEM, PRICE) "
                  "VALUES(:REST_ID, :ITEM, :COST)");
    query.bindValue(":REST_ID", ID);
    query.bindValue(":ITEM", itemName);
    query.bindValue(":COST", price);

    if(query.exec())
    {
        qDebug() << "Data Saved To MenuInfo Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Add MenuItem failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    return success;
}

bool Database::AddDistance(int fromID, int toID, double distance)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO DistanceInfo (FROM_ID, TO_ID, DISTANCE) "
                  "VALUES(:FROM, :TO, :DISTANCE)");
    query.bindValue(":FROM", fromID);
    query.bindValue(":TO", toID);
    query.bindValue(":DISTANCE", distance);

    if(query.exec())
    {
        qDebug() << "Data Saved To DistanceInfo Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Add Distance failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    return success;
}

bool Database::AddDistance(QString fromID, QString toID, QString miles)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO DistanceInfo (FROM_ID, TO_ID, DISTANCE) "
                  "VALUES(:FROM, :TO, :DISTANCE)");
    query.bindValue(":FROM", fromID);
    query.bindValue(":TO", toID);
    query.bindValue(":DISTANCE", miles);

    if(query.exec())
    {
        qDebug() << "Data Saved To DistanceInfo Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Add Distance failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();
    }

    return success;
}

bool Database::DeleteRestaurant(int ID)
{
    bool success = false;

    QSqlQuery queryRInfo;
    QSqlQuery queryMInfo;
    QSqlQuery queryDInfo1;
    QSqlQuery queryDInfo2;

    queryRInfo.prepare("DELETE FROM RestaurantInfo WHERE ID = (:REST_ID)");
    queryRInfo.bindValue(":REST_ID" , ID);

    queryMInfo.prepare("DELETE FROM MenuInfo WHERE RESTAURANT_ID = (:REST_ID)");
    queryMInfo.bindValue(":REST_ID" , ID);

    queryDInfo1.prepare("DELETE FROM DistanceInfo WHERE FROM_ID = (:FROM)");
    queryDInfo1.bindValue(":FROM" , ID);

    queryDInfo2.prepare("DELETE FROM DistanceInfo WHERE TO_ID = (:TO)");
    queryDInfo2.bindValue(":TO" , ID);

    queryMInfo.exec();
    queryDInfo1.exec();
    queryDInfo2.exec();

    if(queryRInfo.exec())
    {
        qDebug() << "Data Deleted From RestaurantInfo, MenuInfo, & DistanceInfo Tables Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Delete restaurant failed...";
    }

    return success;
}

bool Database::DeleteMenuItem(int ID, vector<QString> itemName, vector<double> price)
{
    bool success = false;

    QSqlQuery query;

    for(unsigned int i = 0; i < itemName.size(); i++)
    {
        query.prepare("DELETE FROM MenuInfo WHERE RESTAURANT_ID =(:REST_ID) AND MENU_ITEM =(:ITEM) AND PRICE =(:COST)");
        query.bindValue(":REST_ID", ID);
        query.bindValue(":ITEM", itemName.at(i));
        query.bindValue(":COST", price.at(i));

        if(query.exec())
        {
            qDebug() << "Data Deleted From MenuInfo Table Successfully!";
            success = true;
        }
        else
        {
            qDebug() << "Delete MenuItem failed...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();

        }

        query.clear();
    }

    return success;
}

bool Database::RemoveRestaurant(int id)
{
    bool success = false;

    if(RestaurantExists(id))
    {
        QSqlQuery query;

        query.prepare("DELETE FROM RestaurantInfo WHERE ID = (:REST_ID)");
        query.bindValue(":REST_ID",id);
        success = query.exec();

        if(!success)
        {
            qDebug() << "Remove Restaurant error...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }
    }
    else
    {
        qDebug() << "Remove Restaurant failed, Restaurant doesn't exist!";

    }

    return success;
}

bool Database::RemoveRestaurant(QString name)
{
    bool success = false;

    if(RestaurantExists(name))
    {
        QSqlQuery query;

        query.prepare("DELETE FROM RestaurantInfo WHERE NAME = (:NAME)");
        query.bindValue(":NAME", name);
        success = query.exec();

        if(!success)
        {
            qDebug() << "Remove Restaurant error...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }
    }
    else
    {
        qDebug() << "Remove Restaurant failed, Restaurant doesn't exist!";

    }

    return success;
}

bool Database::RemoveMenuItem(int id)
{
    bool success = false;

    if(MenuItemExists(id))
    {
        QSqlQuery query;

        query.prepare("DELETE FROM MenuInfo WHERE RESTAURANT_ID = (:REST_ID)");
        query.bindValue(":REST_ID",id);
        success = query.exec();

        if(!success)
        {
            qDebug() << "Remove MenuItem error...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }
    }
    else
    {
        qDebug() << "Remove MenuItem failed, MenuItem doesn't exist!";

    }

    return success;
}

bool Database::RemoveMenuItem(QString name)
{
    bool success = false;

    if(MenuItemExists(name))
    {
        QSqlQuery query;

        query.prepare("DELETE FROM MenuInfo WHERE MENU_ITEM = (:ITEM)");
        query.bindValue(":ITEM", name);
        success = query.exec();

        if(!success)
        {
            qDebug() << "Remove MenuItem error...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }
    }
    else
    {
        qDebug() << "Remove MenuItem failed, MenuItem doesn't exist!";

    }

    return success;
}

bool Database::RemoveDistance(int id)
{
    bool success = false;

    if(DistanceExists(id))
    {
        QSqlQuery query;

        query.prepare("DELETE FROM DistanceInfo WHERE FROM_ID = (:FROM)");
        query.bindValue(":FROM",id);
        success = query.exec();

        if(!success)
        {
            qDebug() << "Remove MenuItem error...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }
    }
    else
    {
        qDebug() << "Remove MenuItem failed, MenuItem doesn't exist!";

    }

    return success;
}

bool Database::RemoveDistance(int fromID, int toID)
{
    bool success = false;

    if(DistanceExists(fromID, toID))
    {
        QSqlQuery query;

        query.prepare("DELETE FROM DistanceInfo WHERE FROM_ID = (:FROM) AND TO_ID = (:TO)");
        query.bindValue(":FROM", fromID);
        query.bindValue(":TO", toID);
        success = query.exec();

        if(!success)
        {
            qDebug() << "Remove Distance error...";
            qDebug() << query.lastError();
            qDebug() << query.executedQuery();
        }
    }
    else
    {
        qDebug() << "Remove Distance failed, Distance doesn't exist!";

    }

    return success;
}

bool Database::RestaurantExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery;

    checkQuery.prepare("SELECT ID FROM RestaurantInfo WHERE ID = (:REST_ID)");
    checkQuery.bindValue(":REST_ID", id);
    if(checkQuery.exec())
    {
        if(checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Restaurant doesn't exist!";
    }
    return exists;
}
bool Database::RestaurantExists(QString name) const
{
    bool exists = false;

    QSqlQuery checkQuery;

    checkQuery.prepare("SELECT NAME FROM RestaurantInfo WHERE NAME = (:NAME)");
    checkQuery.bindValue(":NAME", name);
    if(checkQuery.exec())
    {
        if(checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Restaurant doesn't exist!";
    }
    return exists;
}
bool Database::MenuItemExists(int id) const
{
    bool exists = false;

    QSqlQuery query;

    query.prepare("SELECT RESTAURANT_ID FROM MenuInfo WHERE RESTAURANT_ID = (:REST_ID)");
    query.bindValue(":REST_ID",id);
    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Menu item doesn't exist!";
    }
    return exists;
}
bool Database::MenuItemExists(QString name) const
{
    bool exists = false;

    QSqlQuery query;

    query.prepare("SELECT MENU_ITEM FROM MenuInfo WHERE MENU_ITEM = (:ITEM)");
    query.bindValue(":ITEM", name);
    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Menu item doesn't exist!";
    }
    return exists;
}
bool Database::DistanceExists(int id) const
{
    bool exists = false;

    QSqlQuery query;

    query.prepare("SELECT FROM_ID FROM DistanceInfo WHERE FROM_ID = (:FROM)");
    query.bindValue(":FROM",id);
    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Distance doesn't exist!";
    }
    return exists;
}
bool Database::DistanceExists(int fromID, int toID) const
{
    bool exists = false;

    QSqlQuery query;

    query.prepare("SELECT FROM_ID, TO_ID FROM DistanceInfo WHERE FROM_ID = (:FROM) AND TO_ID = (:TO)");
    query.bindValue(":FROM",fromID);
    query.bindValue(":TO",toID);
    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Distance doesn't exist!";
    }
    return exists;
}



bool Database::EditRestaurant(QString restaurantName, int ID, double saddlebackDistance, int countOfMenuItems, int countDestinations)
{
    bool success = false;

    QSqlQuery query;

    query.prepare("UPDATE RestaurantInfo SET (NAME, ID, SADDLEBACK_DISTANCE, MENU_SIZE, NUMBER_OF_DESTINATIONS) "
                  "VALUES(:NAME, :REST_ID, :DIST_TO_SC, :MENU_SIZE, :NUM_OF_DEST)");
    query.bindValue(":NAME", restaurantName);
    query.bindValue(":REST_ID", ID);
    query.bindValue(":DIST_TO_SC", saddlebackDistance);
    query.bindValue(":MENU_SIZE", countOfMenuItems);
    query.bindValue(":NUM_OF_DEST", countDestinations);

    if(query.exec())
    {
        qDebug() << "Data Updated to RestaurantInfo Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Edit Restaurant failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();

    }

    return success;
}


void Database::EditTotalDistances(int ID, int total)
{
    QSqlQuery query;

    if(RestaurantExists(ID))
    {
        query.prepare("UPDATE RestaurantInfo SET NUMBER_OF_DESTINATIONS = (:NUM_OF_DEST) WHERE ID = (:REST_ID)");
        query.bindValue(":REST_ID", ID);
        query.bindValue(":NUM_OF_DEST", total);
        query.exec();
    }
}

void Database::SetRestaurantName(const QString &name, int id) const
{
    QSqlQuery query;

    if(RestaurantExists(id))
    {
        query.prepare("UPDATE RestaurantInfo SET NAME = (:NAME) WHERE ID = (:REST_ID)");
        query.bindValue(":REST_ID", id);
        query.bindValue(":NAME", name);
        query.exec();
    }

}

void Database::SetRestaurantName(QString oldName, QString newName)
{
    QSqlQuery query;

    if(RestaurantExists(oldName))
    {
        query.prepare("UPDATE RestaurantInfo SET NAME = (:NEW_NAME) WHERE NAME = (:OLD_NAME)");
        query.bindValue(":OLD_NAME",oldName);
        query.bindValue(":NEW_NAME",newName);
        query.exec();
    }
}

void Database::SetRestaurantDistance(double distance, int id) const
{
    if(RestaurantExists(id))
    {
        QSqlQuery query;

        query.prepare("UPDATE RestaurantInfo SET SADDLEBACK_DISTANCE = (:DIST_TO_SC) WHERE ID = (:REST_ID)");
        query.bindValue(":REST_ID", id);
        query.bindValue(":DIST_TO_SC", distance);
        query.exec();
    }
}

void Database::SetRestaurantDistance(QString name, double distance)
{
    if(RestaurantExists(name))
    {
        QSqlQuery query;

        query.prepare("UPDATE RestaurantInfo SET SADDLEBACK_DISTANCE = (:DIST_TO_SC) WHERE NAME = (:NAME)");
        query.bindValue(":NAME", name);
        query.bindValue(":DIST_TO_SC", distance);
        query.exec();
    }
}

void Database::SetMenuSize(int size, int id) const
{
    if(RestaurantExists(id))
    {
        QSqlQuery query;

        query.prepare("UPDATE RestaurantInfo SET MENU_SIZE = (:MENU_SIZE) WHERE ID = (:REST_ID)");
        query.bindValue(":REST_ID", id);
        query.bindValue(":MENU_SIZE", size);
        query.exec();
    }
}

bool Database::EditMenuItem(int ID, QString oldItemName, QString itemName, double price)
{
    bool success = false;

    QSqlQuery query;

    query.prepare("UPDATE MenuInfo SET RESTAURANT_ID = (:REST_ID), MENU_ITEM = (:NEW_ITEM) , PRICE = (:COST)"
                  " WHERE MENU_ITEM = (:ITEM) AND RESTAURANT_ID = (:REST_ID)");
    query.bindValue(":REST_ID", ID);
    query.bindValue(":ITEM", oldItemName);
    query.bindValue(":NEW_ITEM", itemName);
    query.bindValue(":COST", price);

    if(query.exec())
    {
        qDebug() << "Data Updated to MenuItem Table Successfully!";
        success = true;
    }
    else
    {
        qDebug() << "Edit MenuItem failed...";
        qDebug() << query.lastError();
        qDebug() << query.executedQuery();

    }

    return success;
}

void Database::SetItemName(int id, QString newName)
{
    if(MenuItemExists(id))
    {
        QSqlQuery query;

        query.prepare("UPDATE MenuInfo SET MENU_ITEM = (:NEW_NAME) WHERE RESTAURANT_ID = (:REST_ID)");
        query.bindValue(":NEW_NAME", newName);
        query.bindValue(":REST_ID", id);
        query.exec();
    }
}

void Database::SetItemName(QString oldName, QString newName)
{
    if(MenuItemExists(oldName))
    {
        QSqlQuery query;

        query.prepare("UPDATE MenuInfo SET MENU_ITEM = (:NEW_NAME) WHERE MENU_ITEM = (:OLD_NAME)");
        query.bindValue(":OLD_NAME", oldName);
        query.bindValue(":NEW_NAME", newName);
        query.exec();
    }
}

void Database::SetItemPrice(int id, double price)
{
    if(MenuItemExists(id))
    {
        QSqlQuery query;

        query.prepare("UPDATE MenuInfo SET PRICE = (:COST) WHERE RESTAURANT_ID = (:REST_ID)");
        query.bindValue(":REST_ID", id);
        query.bindValue(":COST", price);
        query.exec();
    }
}

void Database::SetItemPrice(QString name, double price)
{
    if(MenuItemExists(name))
    {
        QSqlQuery query;

        query.prepare("UPDATE MenuInfo SET PRICE = (:COST) WHERE MENU_ITEM = (:MENU_ITEM)");
        query.bindValue(":MENU_ITEM", name);
        query.bindValue(":COST", price);
        query.exec();
    }
}

void Database::SetItemID(QString name, int newID)
{
    if(MenuItemExists(name))
    {
        QSqlQuery query;

        query.prepare("UPDATE MenuInfo SET RESTAURANT_ID = (:NEW_ID) WHERE MENU_ITEM = (:MENU_ITEM)");
        query.bindValue(":MENU_ITEM", name);
        query.bindValue(":NEW_ID", newID);
        query.exec();
    }

}

void Database::SetItemID(int oldID, int newID)
{
    if(MenuItemExists(oldID))
    {
        QSqlQuery query;

        query.prepare("UPDATE MenuInfo SET RESTAURANT_ID = (:NEW_ID) WHERE RESTAURANT_ID = (:REST_ID)");
        query.bindValue(":REST_ID", oldID);
        query.bindValue(":NEW_ID", newID);
        query.exec();
    }
}

void Database::SetFromID(int fromID, int toID, int newFromID)
{
    if(DistanceExists(fromID, toID))
    {
        QSqlQuery query;

        query.prepare("UPDATE DistanceInfo SET FROM_ID = (:NEW_FROM) WHERE FROM_ID = (:FROM) AND TO_ID = (:TO)");
        query.bindValue(":FROM", fromID);
        query.bindValue(":TO", toID);
        query.bindValue(":NEW_FROM", newFromID);
        query.exec();
    }
}

void Database::SetToID(int fromID, int toID, int newToID)
{
    if(DistanceExists(fromID, toID))
    {
        QSqlQuery query;

        query.prepare("UPDATE DistanceInfo SET TO_ID = (:NEW_TO) WHERE FROM_ID = (:FROM) AND TO_ID = (:TO)");
        query.bindValue(":FROM", fromID);
        query.bindValue(":TO", toID);
        query.bindValue(":NEW_TO", newToID);
        query.exec();
    }
}

void Database::SetDistanceMiles(int fromID, double miles)
{
    if(DistanceExists(fromID))
    {
        QSqlQuery query;

        query.prepare("UPDATE DistanceInfo SET DISTANCE = (:DISTANCE) WHERE FROM_ID = (:FROM)");
        query.bindValue(":DISTANCE", miles);
        query.bindValue(":FROM", fromID);
        query.exec();
    }
}

void Database::SetDistanceMiles(int fromID, int toID, double miles)
{
    if(DistanceExists(fromID, toID))
    {
        QSqlQuery query;

        query.prepare("UPDATE DistanceInfo SET DISTANCE = (:DISTANCE) WHERE FROM_ID = (:FROM) AND TO_ID = (:TO)");
        query.bindValue(":FROM", fromID);
        query.bindValue(":TO", toID);
        query.bindValue(":DISTANCE", miles);
        query.exec();
    }
}

QString Database::GetRestaurantName(int id)
{
    QSqlQuery query;
    QString name = "";

    query.prepare("SELECT NAME FROM RestaurantInfo WHERE ID = (:REST_ID)");
    query.bindValue(":REST_ID", id);
    query.exec();
    query.next();
    int index = query.record().indexOf("NAME");
    name += query.value(index).toString();

    return name;
}

double Database::GetRestaurantDistance(int id)
{
    double distance;
    QSqlQuery query;

    query.prepare("SELECT SADDLEBACK_DISTANCE FROM RestaurantInfo WHERE ID = (:REST_ID)");
    query.bindValue(":REST_ID",id);
    query.exec();
    query.next();
    int index = query.record().indexOf("SADDLEBACK_DISTANCE");
    distance = query.value(index).toDouble();
    return distance;
}

int Database::GetRestaurantMenuSize(int id)
{
    int size;
    QSqlQuery query;

    query.prepare("SELECT MENU_SIZE FROM restaurant WHERE ID = (:REST_ID)");
    query.bindValue(":ID",id);
    query.exec();
    query.next();
    int index = query.record().indexOf("MENU_SIZE");
    size = query.value(index).toInt();
    return size;
}

int  GetNumberOfRows()
{
    int size;
    QSqlQuery query;

    query.prepare("COUNT(*) FROM RestaurantInfo");
    query.exec();

    size = query.value(0).toInt();

    return size;
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
            query.bindValue(":FROM", ID);
            query.bindValue(":TO", destination);
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

vector<Restaurant>* Database::InputNewFileToDatabase(const QString& path)
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
    vector<Restaurant> *restaurantList2 = new vector<Restaurant>;

    if(!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open the file for writing to database...";
    }

    QSqlQuery query(rDatabase);
    QTextStream in(&inFile);

    unsigned int index = 0;

    while(!in.atEnd())
    {
        Restaurant NewObject;

        QStringList text = in.readLine().split(": ");
        restaurantName = text[1];

        qDebug() << "Name read as: " << restaurantName;

        bool adding = true;

        for(unsigned int i = 0; i < restaurantList.size(); i++)
        {
            if(restaurantName == restaurantList.at(i).GetName())
            {
                adding = false;
            }
        }

        if(adding)
        {
            qDebug() << "Name read as: " << restaurantName;

            text = in.readLine().split("number ");
            ID = text[1];

            qDebug() << "ID read as: " << ID;

            NewObject.SetID(ID.toInt());

            text = in.readLine().split("- ");
            QString countDestinations = text[1];

            bool isOk;
            int count = countDestinations.toInt(&isOk, 10);

            qDebug() << "Count read as: " << count;

            for(unsigned int i = 0; i < count; i++)
            {

                Distance thisDistance;
                text = in.readLine().split(" ");
                destination = text[0];
                distanceInMiles = text[1];

    //            Distance *thisObject = new Distance;

    //             thisObject->SetCurrentRestaurantID(ID.toInt());
    //             thisObject->SetMiles(distanceInMiles.toDouble());
    //             thisObject->SetNextID(destination.toInt());

                qDebug() << "destination ID read as: " << destination;
                qDebug() << "distance in miles read as: " << distanceInMiles;

                //restaurantList->at(index)->GetDistancesToRestaurants().push_back(*thisObject);
    //            restaurantList->at(index).GetDistancesToRestaurants().at(i).SetCurrentRestaurantID(ID.toInt());
    //            restaurantList->at(index).GetDistancesToRestaurants().at(i).SetMiles(distanceInMiles.toDouble());
    //            restaurantList->at(index).GetDistancesToRestaurants().at(i).SetNextID(destination.toInt());

                thisDistance.SetCurrentRestaurantID(ID.toInt());
                thisDistance.SetMiles(distanceInMiles.toDouble());
                thisDistance.SetNextID(destination.toInt());

                NewObject.StoreDistancesToRestaurants(thisDistance);

                query.prepare("INSERT INTO DistanceInfo (FROM_ID, TO_ID, DISTANCE) "
                              "VALUES(:FROM, :TO, :DISTANCE)");
                query.bindValue(":FROM", ID);
                query.bindValue(":TO", destination);
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

            restaurantList2->push_back(NewObject);

            index++;
        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error", restaurantName + " already exists");

            qDebug() << "CAN'T ADD " << restaurantName;

            text = in.readLine().split("number ");
            ID = text[1];

            qDebug() << "ID read as: " << ID;

            text = in.readLine().split("- ");
            QString countDestinations = text[1];

            bool isOk;
            int count = countDestinations.toInt(&isOk, 10);

            qDebug() << "Count read as: " << count;

            for(unsigned int i = 0; i < count; i++)
            {

                Distance thisDistance;
                text = in.readLine().split(" ");
                destination = text[0];
                distanceInMiles = text[1];

                qDebug() << "destination ID read as: " << destination;
                qDebug() << "distance in miles read as: " << distanceInMiles;

                thisDistance.SetCurrentRestaurantID(ID.toInt());
                thisDistance.SetMiles(distanceInMiles.toDouble());
                thisDistance.SetNextID(destination.toInt());

                NewObject.StoreDistancesToRestaurants(thisDistance);

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
            }

            in.readLine();

            index++;
        }

    }

    inFile.flush();
    inFile.close();

    return restaurantList2;

}

void Database::DatabaseToRestaurants()
{
    QSqlQuery restaurantQuery;
    QSqlQuery distanceQuery;
    QSqlQuery menuQuery;

    restaurantQuery.prepare("SELECT * FROM RestaurantInfo ORDER BY ID ASC");
    if(!restaurantQuery.exec())
    {
        qDebug() << "Unable to execute query";
        qDebug() << restaurantQuery.lastError();
        qDebug() << restaurantQuery.executedQuery();
    }

    distanceQuery.prepare("SELECT * FROM DistanceInfo ORDER BY FROM_ID ASC");
    if(!distanceQuery.exec())
    {
        qDebug() << "Unable to execute query";
        qDebug() << distanceQuery.lastError();
        qDebug() << distanceQuery.executedQuery();
    }

    menuQuery.prepare("SELECT * FROM MenuInfo ORDER BY RESTAURANT_ID ASC");
    if(!menuQuery.exec())
    {
        qDebug() << "Unable to execute query";
        qDebug() << menuQuery.lastError();
        qDebug() << menuQuery.executedQuery();
    }

    int location = 0;

    while(restaurantQuery.next())
    {
        Restaurant restaurant;

        restaurant.setLocationID(location);
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

            distance.SetCurrentRestaurantID(distanceQuery.value(0).toInt());
            distance.SetNextID(distanceQuery.value(1).toInt());
            distance.SetMiles(distanceQuery.value(2).toDouble());
            restaurant.StoreDistancesToRestaurants(distance);

            count++;
        }

        count = 0;
        while(count < restaurant.GetSize())
        {
            menuQuery.next();
            MenuItem menuItem;
            menuItem.SetRestaurantID(menuQuery.value(0).toInt());
            menuItem.SetItemName(menuQuery.value(1).toString());
            menuItem.SetPrice(menuQuery.value(2).toDouble());
            restaurant.StoreMenuItemsOfRestaurant(menuItem);

            count++;
        }

        location++;

        restaurantList.push_back(restaurant);
    }
}

vector<Restaurant> Database::GetRestuarantList()
{
    return restaurantList;
}

void Database::ClearRestaurantList()
{
    restaurantList.clear();
}

QSqlDatabase Database::GetDatabase()
{
    return rDatabase;
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
            qDebug() << j+1 << " " << restaurantList.at(i).GetDistancesToRestaurants().at(j).GetMiles(); //restaurantList.at(i).at(j).GetNextID()
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
