#include "shortesttrip.h"
#include "ui_shortesttrip.h"
#include "Restaurant.h"
#include "structs.h"
#include <qmessagebox.h>

shortesttrip::shortesttrip(vector<Restaurant> restaurants,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shortesttrip)
{
    totalDistance = 0;

    ui->setupUi(this);
    for(unsigned int i = 0; i < restaurants.size(); i++)
    {
        restaurantList.push_back(restaurants.at(i));
    }

    ui->spinBox->setMaximum(restaurantList.size() - 1);
}

vector<int> shortesttrip::ReturnIDsChosenRestaurants()
{
    return IDsChosenRestaurants;
}

double shortesttrip::returnTotalDistance()
{
    return totalDistance;
}

shortesttrip::~shortesttrip()
{
    delete ui;
}

void shortesttrip::on_buttonBox_accepted()
{
    int index;
    bool found = false;
    int counter = 0;

    while(!found && counter < restaurantList.size())
    {
        qDebug() << restaurantList.at(counter).GetName() << endl;
        if(restaurantList.at(counter).GetName() == "Domino’s Pizza")
        {
            found = true;
        }
        else
        {
            counter++;
        }

       qDebug() << counter << endl;
    }//end while

    IDsChosenRestaurants.push_back(restaurantList.at(counter).getLocationID() );

    index = counter;


    if(ui->spinBox->value() > 0)
    {
        int spot;
        double smallest;
        bool check;
        double current ;

        for(unsigned int k = 0; k < ui->spinBox->value(); k++ )
        {
            smallest = 100;

            for(unsigned int j = 0; j < restaurantList.size(); j++)
            {
                check = true;

                current = restaurantList.at(j).GetMilesFromRestaurantList(index);

               // CHECK FOR REPETITION

                for(unsigned int i = 0; i < IDsChosenRestaurants.size() && check; i++)
                {
                    //if(restaurantList.at(j).GetID() - 1 == IDsChosenRestaurants.at(i))
                    if(restaurantList.at(j).getLocationID() == IDsChosenRestaurants.at(i))
                    {
                        check = false;
                    }
                }

                // CHECK FOR SMALLEST
                if(current != 0.0 && current < smallest && check)
                {
                    smallest = current;
                    //spot = restaurantList.at(j).GetID() - 1;
                    spot = restaurantList.at(j).getLocationID();
                }

            } // for(int j = 0; j < selectedRestaurant.size(); j++)

            totalDistance += smallest;

            IDsChosenRestaurants.push_back(spot);

            index = spot;

        } // for(int k = 0; k < selectedRestaurant.size() - 1; k++ )

    }//END IF

    if(restaurantList.size() != 0)
    {
        notSelected = true;
        for(unsigned int i = 0; i < IDsChosenRestaurants.size(); i++ )
        {
            qDebug() << IDsChosenRestaurants.at(i) << endl;
            qDebug() << restaurantList.at(IDsChosenRestaurants.at(i)).GetName() << endl;
            qDebug() << "**********\n";
        }
    }
    else
    {
        notSelected = false;
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No restaurants Selected");

    }
}

void shortesttrip::on_buttonBox_rejected()
{
    back = true;
}

bool shortesttrip::returnBack()
{
    return back;
}
