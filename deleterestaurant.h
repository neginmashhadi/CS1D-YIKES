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
    File: deleterestaurant.h
    Class for the user interface of deleting a restaurant
*/

#ifndef DELETERESTAURANT_H
#define DELETERESTAURANT_H

#include <QHeaderView>
#include <QDialog>
#include "Restaurant.h"


namespace Ui {
class deleteRestaurant;
}

/**
@brief used to delete restaurants from the set of restaurants
*/
class deleteRestaurant : public QDialog
{
    Q_OBJECT

public:
    /** Default constructor
    @param vector<Restaurant> restaurants - a vector of type Restaurant saving restaurant info
    */
    explicit deleteRestaurant(vector<Restaurant> restaurants, QWidget *parent = nullptr);

    /** Populates the table with needed vectors of restaurants info
    */
    void fillTable();

    /** Gets the ID of the restaurant
    */
    int getRestaurantID();

    /** Destructor
    */
    ~deleteRestaurant();

private slots:
    /** Handles button when clicked
    */
    void on_pushButton_clicked();

private:
    Ui::deleteRestaurant    *ui;                /**<Handles the UI for deleteRestaurant class*/
    int                     restaurantID{-1};   /**<Saves the ID of the restaurant*/
    vector<Restaurant>      restaurantList;     /**<Saves the restaurant list*/
};

#endif // DELETERESTAURANT_H
