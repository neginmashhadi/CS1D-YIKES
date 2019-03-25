#include "structs.h"
#include <QDebug>


void AddingRestaurants(bool checked, Database * DB)
{
    if(checked)
    {
        vector<Restaurant> *list;

        list = DB->InputNewFileToDatabase(":/files/NewInput.txt");

        for(unsigned int j = 0; j < list->size(); j++)
        {
            for(unsigned int i = 0; i < (list->at(j).GetDistancesToRestaurants().size() - list->size()); i++)
            {
                if(DB->RestaurantExists(list->at(j).GetDistancesToRestaurants().at(i).GetNextID()))
                {
                    if(DB->AddDistance(list->at(j).GetDistancesToRestaurants().at(i).GetNextID(),
                                    list->at(j).GetDistancesToRestaurants().at(i).GetCurrentRestaurantID(),
                                    list->at(j).GetDistancesToRestaurants().at(i).GetMiles()))
                                                                                                                                     {

                        qDebug() << list->at(j).GetDistancesToRestaurants().at(i).GetCurrentRestaurantID();
                        qDebug() <<list->at(j).GetDistancesToRestaurants().at(i).GetNextID();
                        qDebug() <<list->at(j).GetDistancesToRestaurants().at(i).GetMiles();
                        qDebug() << "Add distance Successful";
                    }
                    else
                    {
                        qDebug() << "IT FAILED";
                    }
                }
            }

            qDebug() << list->at(j).GetID() << " ID ************";

            qDebug() << DB->GetRestuarantList().size() << " + " << list->size() << " size ************";

            DB->EditTotalDistances(list->at(j).GetID(), DB->GetRestuarantList().size() + list->size());
        }

        for(unsigned int i = 0; i < DB->GetRestuarantList().size(); i++)
        {
            DB->EditTotalDistances(DB->GetRestuarantList().at(i).GetID(), DB->GetRestuarantList().size() + list->size());
        }

        DB->ClearRestaurantList();
        DB->DatabaseToRestaurants();
        DB->testDatabase();

        list->clear();

    }
}


void AddingRestaurantsPath(QString path, Database * DB)
{
    vector<Restaurant> *list;

    list = DB->InputNewFileToDatabase(path);

    for(unsigned int j = 0; j < list->size(); j++)
    {
        for(unsigned int i = 0; i < (list->at(j).GetDistancesToRestaurants().size() - list->size()); i++)
        {
            if(DB->RestaurantExists(list->at(j).GetDistancesToRestaurants().at(i).GetNextID()))
            {
                if(DB->AddDistance(list->at(j).GetDistancesToRestaurants().at(i).GetNextID(),
                                list->at(j).GetDistancesToRestaurants().at(i).GetCurrentRestaurantID(),
                                list->at(j).GetDistancesToRestaurants().at(i).GetMiles()))
                {

                    qDebug() << list->at(j).GetDistancesToRestaurants().at(i).GetCurrentRestaurantID();
                    qDebug() <<list->at(j).GetDistancesToRestaurants().at(i).GetNextID();
                    qDebug() <<list->at(j).GetDistancesToRestaurants().at(i).GetMiles();
                    qDebug() << "Add distance Successful";
                }
                else
                {
                    qDebug() << "IT FAILED";
                }
            }
        }

        qDebug() << list->at(j).GetID() << " ID";

        qDebug() << DB->GetRestuarantList().size() + list->size() << " size";

        DB->EditTotalDistances(list->at(j).GetID(), DB->GetRestuarantList().size() + list->size());


    }

    for(unsigned int i = 0; i < DB->GetRestuarantList().size(); i++)
    {
        DB->EditTotalDistances(DB->GetRestuarantList().at(i).GetID(), DB->GetRestuarantList().size() + list->size());
    }

    DB->ClearRestaurantList();
    DB->DatabaseToRestaurants();
    DB->testDatabase();
    list->clear();

}
