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
    File: additem.h
    Class for the user interface of adding an item
    to any restaurant
*/

#ifndef ADDITEM_H
#define ADDITEM_H

#include "Restaurant.h"
#include <QRadioButton>
#include <QDialog>
#include <QString>

namespace Ui {
class AddItem;
}

/**
@brief used to add items to any given restaurant
*/
class AddItem : public QDialog
{
    Q_OBJECT

    public:
    /** Default constructor
    */
        explicit AddItem(QWidget *parent = nullptr);

    /** Fills the Checkboxes
    @param restaurant - Vector of restaurants
    */
        void     fillCheckBoxes(vector<Restaurant> restaurant);

    /** Gets the Restaurant ID
    @return Restaurant ID
    */
        int      getRestaurantID();

    /** Gets the other ID
    @return other ID
    */
        int      getOtherID();

    /** Gets the food name
    @return Food Name
    */
        QString  getFoodName();

    /** Gets the food price
    @return Food Price
    */
        double   getFoodPrice();


        ~AddItem();

    private slots:
    /** Handles ButtonBox accepted
    */
        void on_buttonBox_accepted();

    /** Handles Next_Button clicked
    */
        void on_Next_Button_clicked();

    /** Handles Submit Button clicked
    */
        void on_Submit_clicked();

    private:
        Ui::AddItem *ui; /**<UI for AddItem*/
        int restaurantID; /**<Used to keep track of Restaurant ID*/
        QString foodName; /**<Used to hold the food name*/
        double  foodPrice; /**<Used to hold the food price*/
        int otherID;  /**<Used to hold other ID*/
        vector<Restaurant> restaurantList;  /**<Used to hold the first restaurant list*/
        vector<Restaurant> restaurantList2;  /**<Used to hold the second restaurant list*/
        vector<QRadioButton*> buttonList;   /**<Used to hold the keys for the buttons*/
};

#endif // ADDITEM_H
