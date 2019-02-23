#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Restaurants.db");

    if(!db.open())
        qDebug() << "Not connected to DB.";
    else if(db.open())
        qDebug() << "Connected to DB.";
}

/**
 * @brief database::TestDatabase
 *  Outputs the restaurants to the console to test the database
 */
void database::TestDatabase()
{
    QVector <QString> names;    //OUT - name of restaurants
    QVector <QString> dist;     //OUT - distance of restaurant
    QVector <QString> num;      //OUT - number of restaurant
    QSqlQuery query;            //OUT - query variable

    //PROCESSING - gets all entries from restaurants table
    query.prepare("SELECT * FROM Restaurants");

    /************************************************
     * Executes query and outputs data to console
     ************************************************/
    if(query.exec())
    {
        while(query.next())
        {
            //PROCESSING - sets values to vectors
            names.push_back(query.value(0).toString());
            num.push_back(query.value(1).toString());
            dist.push_back(query.value(2).toString());
        }
    }
}

/**
 * @brief database::GetRestaurantsName
 * @return
 */
QVector<QString> database::GetRestaurantsName()
{
    QSqlQuery        query; //CALC - query variable
    QVector<QString> list;  //OUT  - list of names
    QString          name;  //OUT  - name of restaurant


    //PROCESSING - sql statement that gets a names of
    //             all the restaurants in the table
    query.prepare("SELECT Name FROM Restaurants");
    if(query.exec())
    {
        while(query.next())
        {
            //PROCESSING - stores names from query
            name = query.value(0).toString();
            list.push_back(name);
        }
    }
    return list;
}

/**
 * @brief database::SearchForName
 * @param key
 * @return
 */
bool database::SearchForName(QString key)
{
    QSqlQuery query;        //CALC - sql variable
    bool      found = false;//CALC - determines if name is found

    //PROCESSING - Sql statments that gets names from restaurant
    query.prepare("SELECT name FROM Restaurants");

    if(query.exec())
    {
        //PROCESSING - loops through query until name is found or
        //              end of list
        while(query.next() && !found)
        {
            if(query.value(0) == key)
            {
                found = true;
            }//end - ifif(query.value(0) == key)
        }//end - while(!found)

    }//end - if(query.exec())

    return found;
}

/**
 * @brief database::SearchForNumber
 * @param key
 * @return
 */
bool database::SearchForNumber(int key)
{
    QSqlQuery query;        //CALC - sql variable
    bool      found = false;//CALC - determines if num is found

    //PROCESSING - sql statement that gets all numbers from table
    query.prepare("SELECT number FROM Restaurants");

    //PROCESSING - Executes query
    if(query.exec())
    {
        //PROCESSING - searches query until key is found or end of list
        while(query.next() && !found)
        {
            if(query.value(0) == key)
            {
                found = true;
            }//end - ifif(query.value(0) == key)
        }//end - while(!found)

    }//end - if(query.exec())

    return found;
}

/**
 * @brief database::GetAllRestaurants
 * @param names
 * @param distances
 */
void database::GetAllRestaurants(QVector<QString> &names,
                                 QVector<float>& distances)
{
   QSqlQuery query;

   //PROCESSING - gets all entries from restaurants table
   query.prepare("SELECT * FROM Restaurants");
   if(query.exec())
   {
       //PROCESSING - stores names and distances to vectors
       while(query.next())
       {
           names.push_back(query.value(0).toString());
           distances.push_back(query.value(2).toFloat(0));
       }
   }
}
/**
 * @brief database::AllRestaurants
 * @return
 */
QVector<Restaurant> database::AllRestaurantInfo()
{
    QSqlQuery           query;      //CALC - sql query variable
    QVector<Restaurant> restCopy;   //CALC - stores copy of restaruant
    QVector<Restaurant> restFinal;  //CALC - final restaurant data
    Restaurant          res;        //CALC - sets varibles of restaurant

    //PROCESSING - gets all entries from restaurants table
    query.prepare("SELECT * FROM Restaurants");
    if(query.exec())
    {
        //PROCESSING - stores all data from restaurants table to res variable
        while(query.next())
        {
            res.SetName(query.value(0).toString());
            res.SetNum(query.value(1).toInt(0));
            res.SetDistanceSB(query.value(2).toFloat(0));
            //qDebug() << query.value(0).toString();
            //qDebug() << query.value(1).toInt(0);
            //qDebug() << query.value(2).toFloat(0);

            //PROCESSING - pushes restaurant to copy
            restCopy.push_back(res);
        }
    }

    //PROCESSING - finds and stores menu items to res variable
    for(int i = 0; i < restCopy.size(); i++)
    {
        //PROCESSING - returns all menu item and prices from
        //             restaurant number
        query.prepare("SELECT Item,Price FROM Menu WHERE Number=:num");
        query.bindValue(":num", restCopy[i].GetNum());

        //PROCESSING - executes query
        if(query.exec())
        {
            //PROCESSING - sets distance restaurant info to res variable
            res.SetName(restCopy[i].GetName());
            res.SetNum(restCopy[i].GetNum());
            res.SetDistanceSB(restCopy[i].GetDistanceSB());

            //PROCESSING - loops through query and stores menu items to res
            while(query.next())
            {
                res.SetMenu(query.value(0).toString(),
                            query.value(1).toFloat(0));
                //qDebug() << query.value(0).toString();
                //qDebug() << query.value(1).toFloat(0);
            }
        }

        //PROCESSING - gets restaurant distance from database
        query.prepare("SELECT Restaurant2,Distance FROM Distances WHERE Restaurant1=:rest1");
        query.bindValue(":rest1",restCopy[i].GetNum() );

        if(query.exec())
        {
            //PROCESSING - stores distances to res variable
            while(query.next())
            {
                res.setDistanceFrom(query.value(0).toInt(0),query.value(1).toDouble(0));
                //qDebug() << query.value(0).toInt(0) << "\t" << query.value(1).toDouble(0);
            }
        }

        //PROCESSING - pushes restaurant to vector and clears the res variable
        //             menu and distances
        restFinal.push_back(res);
        res.ClearMenu();
        res.ClearDistances();
    }
    return restFinal;
}

/**
 * @brief database::GetRestaurant
 * @param name
 * @return
 */
Restaurant database::GetRestaurant(QString name)
{
    QSqlQuery  query; //CALC - variable to acces database
    Restaurant res;   //CALC - stores restaurant info

    //PROCESSING - gets restaurant number and distance from name passed in
    query.prepare("SELECT number, distanceSB FROM Restaurants WHERE name = :rName");
    query.bindValue(":rName", name);

    //PROCESSING - executes query
    if(query.exec())
    {
        //PROCESSING - stores num and distance from saddleback into res variable
        while(query.next())
        {
            res.SetNum(query.value(0).toInt(0));
            res.SetDistanceSB(query.value(1).toFloat(0));
        }
    }

    //PROCESSING - gets menu from name passed in from database
    query.prepare("SELECT Item, Price FROM Menu WHERE Number = :rNum");
    query.bindValue(":rNum", res.GetNum());

    //PROCESSING - executes query
    if(query.exec())
    {
        //PROCESSING - stores menu to res variable
        while(query.next())
        {
            res.SetMenu(query.value(0).toString(), query.value(1).toFloat(0));
        }
    }
    return res;
}

/**
 * @brief database::AddMenuItem
 * -adds menu item to restaurant table
 * @param item
 * @param price
 * @param name
 * @return
 */
bool database::AddMenuItem(QString item, float price, QString name)
{
    QSqlQuery query;    //CALC - variable to acces database
    int       number;   //CALC - number of restaurant to access

    //PROCESSING - gets number from restaurant name passed in and stores it
    query.prepare("SELECT number FROM Restaurants WHERE name = :name");
    query.bindValue(":name", name);
    if(query.exec())
    {
        while(query.next())
        {
            number = query.value(0).toInt(0);
        }
    }

    //PROCESSING - inserts new menu item and price to menu table with corresponding restaurant
    //              number
    query.prepare("INSERT INTO Menu (Number, Item, Price) VALUES (:num, :item, :price)");
    query.bindValue(":num", number);
    query.bindValue(":item", item);
    query.bindValue(":price", price);
    if(query.exec())
    {
        qDebug() << "inserted";
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief database::DelteMenuItem
 * deletes menu item from database
 * @param item
 * @param name
 * @return
 */
bool database::DelteMenuItem(QString item, QString name)
{
    QSqlQuery query;    //CALC - variable to acces database
    int       number;   //CALC - number of restaurant to access

    //PROCESSING - gets menu number from name passed in
    query.prepare("SELECT number FROM Restaurants WHERE name = :name");
    query.bindValue(":name", name);
    if(query.exec())
    {
        while(query.next())
        {
            number = query.value(0).toInt(0);
        }
    }

    //PROCESSING - deletes row in menu table where item and number passed in are located
    query.prepare("DELETE FROM Menu WHERE Item = :item AND Number = :num");
    query.bindValue(":item",item);
    query.bindValue(":num",number);

    if(query.exec())
    {
        return true;
    }
}

bool database::CheckMenuItem(QString name)
{
    QSqlQuery query;
    query.prepare("SELECT * from Menu");

    if(query.exec())
    {
        while(query.next())
        {
            if(query.value(1).toString() == name)
            {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief database::ChangePrice
 * changes item price of item passed in with new price passed in
 * @param itemName
 * @param newPrice
 * @return
 */
bool database::ChangePrice(QString itemName, float newPrice)
{
    QSqlQuery query;
    query.prepare("UPDATE Menu SET Price = :newPrice WHERE Item = :itemName");
    query.bindValue(":itemName", itemName);
    query.bindValue(":newPrice", newPrice);

    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief database::AddRestaurant
 * - Adds new restaurant to database
 * @param add - Restaurant to add
 * @return
 */

bool database::AddRestaurant(Restaurant add)
{
    QSqlQuery query;    //CALC - query to access database
    bool valid = false; //CALC - holds whether datacase was executed

    int count = 0;
    query.prepare("SELECT COUNT(*) FROM Restaurants");
    if(query.exec())
    {
        while(query.next())
        {
            count = query.value(0).toInt(0);
            //qDebug() << "COUNT - " << count ;
            valid =  true;
        }
    }
    else
    {
        valid = false;
    }

    //PROCESSING - Adds new restaurant to the Restaurants table
    query.prepare("INSERT INTO restaurants (name, number, distanceSB) VALUES (:name, :num, :distanceSB)");
    query.bindValue(":name", add.GetName());
    query.bindValue(":num", add.GetNum());
    query.bindValue(":distanceSB", add.GetDistanceSB());

    //PROCESSING - Executes query.
    if(query.exec())
    {
        valid =  true;
        TestDatabase();
    }
    else
    {
        valid = false;
    }

    //PROCESSING - Enters the restaurants distance to other restaurants to
    //              Distances table
    for(int i = 0; i < count + 1; i++)
    {
        //PROCESSING - sets both restaurant columns to the same restaurant so the
        //              distance between them is zero
        if(i == count)
        {
            query.prepare("INSERT INTO Distances (Restaurant1, Restaurant2, Distance) "
                          "VALUES (:res1, :res2, :dist)");
            query.bindValue(":res1", add.GetNum());
            query.bindValue(":res2", add.GetNum());
            query.bindValue(":dist", add.GetDistances()[i]);
        }
        else
        {
            query.prepare("INSERT INTO Distances (Restaurant1, Restaurant2, Distance) "
                          "VALUES (:res1, :res2, :dist)");
            query.bindValue(":res1", add.GetNum());
            query.bindValue(":res2", i + 1);
            query.bindValue(":dist", add.GetDistances()[i]);
        }

        //PROCESSING - Executes query
        if(query.exec())
        {
            valid = true;
            //qDebug() << "index:  " << i;
        }
        else
        {
            valid = false;
        }
    }

    //PROCESSING - Enters previously added restaurants distance from new restaurant
    //              to Distances table
    for(int i = 0; i < count; i++)
    {
        query.prepare("INSERT INTO  Distances (Restaurant1, Restaurant2, Distance) "
                      "VALUES (:res1, :res2, :dist)");
        query.bindValue(":res1", i + 1);
        query.bindValue(":res2", add.GetNum());
        query.bindValue(":dist", add.GetDistances()[i]);

        //PROCESSING - Executes query
        if(query.exec())
        {
            valid = true;
            //qDebug() << "update distances index: " << i;
        }
    }

    //PROCESSING - Enters new restaurants menu item and price
    //              to Menu table
    for(int i = 0; i < add.GetItems().size(); i++)
    {
        query.prepare("INSERT INTO Menu (Number, Item, Price) "
                      "VALUES (:num, :item, :price)");
        query.bindValue(":num", add.GetNum());
        query.bindValue(":item", add.GetItems()[i]);
        query.bindValue(":price", add.GetPrices()[i]);

        if(query.exec())
        {
            valid = true;
           // qDebug() << "added " << add.GetItems()[i];
        }
    }

    qDebug() << "Added all restaurants";
    return valid;
}
