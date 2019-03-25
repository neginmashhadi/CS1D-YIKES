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
    File: ShortestTrip.h
    Class that handles the user interface for shortest trip
*/

#ifndef SHORTESTTRIP_H
#define SHORTESTTRIP_H
#include "structs.h"
#include "Restaurant.h"
#include <QDialog>

namespace Ui {
class shortesttrip;
}
/**
 * @brief The shortesttrip class, control
 */
class shortesttrip : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief shortesttrip -
     */
    explicit shortesttrip(vector<Restaurant> restaurants,QWidget *parent = nullptr);

    /**
    * @brief destructor
    */
    ~shortesttrip();

    vector<int> ReturnIDsChosenRestaurants();

    /**
     * @brief returnBack - returns the private data memeber back
     * @return back
     */
    bool returnBack();

    /**
     * @brief returnTotalDistance - calculates the total distance foodie needs to travel
     * @return the total distance
     */
    double returnTotalDistance();

private slots:
    /**
     * @brief on_buttonBox_accepted - runs the shortest distance
     */
    void on_buttonBox_accepted();
    /**
     * @brief on_buttonBox_rejected - goes back to the MainWindow
     */
    void on_buttonBox_rejected();

private:
    Ui::shortesttrip *ui;  /**<UI for shortestTrip*/
    vector<Restaurant> restaurantList;  /**<Vector for all restaurants*/
    vector<int> IDsChosenRestaurants;  /**<Vector for the IDs that were chosen*/
    bool back {false};  /**<Boolean for cancel button*/
    bool notSelected;  /*<Boolean for a restaurant not selected*/
    double totalDistance;  /**<the total distance traveled*/

};

#endif // SHORTESTTRIP_H
