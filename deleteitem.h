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
    File: deleteitem.h
    Class for the user interface of deleting an item
*/

#ifndef DELETEITEM_H
#define DELETEITEM_H

#include "Restaurant.h"
#include <QDialog>
#include <QRadioButton>
#include <QCheckBox>

namespace Ui {
class DeleteItem;
}

/**
@brief used to delete items from the restaurants
*/
class DeleteItem : public QDialog
{
    Q_OBJECT

public:
    /** Default constructor
    */
    explicit DeleteItem(QWidget *parent = nullptr);

    /** Fills the check boxes as the user chooses
    @param vector<Restaurant> restaurant - a vector of type Restaurant saving restaurant info
    */
    void fillCheckBoxes(vector<Restaurant> restaurant);

    /** Gets ID of the restaurant
    @return ID of the restaurant
    */
    int getRestaurantID();

    /** Gets ID of the deleted restaurant
    @return ID of the deleted restaurant
    */
    int getDeletedID();

    /** Gets name of the deleted restaurant
    @return name of the restaurant
    */
    vector<QString> getDeletedItems();

    /** Gets price of the restaurant
    @return price of the restaurant
    */
    vector<double> getDeletedPrices();

    /** Destructor
    */
    ~DeleteItem();

private slots:
    /** Handles OK button when clicked
    */
    void on_buttonBox_accepted();

    /** Handles Next button when clicked
    */
    void on_next_button_clicked();

    /** Handles Submit button when clicked
    */
    void on_submit_button_clicked();

private:
    Ui::DeleteItem          *ui;             /**<Handles the UI for DeleteItem class*/
    int                     restaurantID;    /**<Saves actual ID of the deleted restaurant*/
    int                     deletedID;       /**<Saves the index location of the deleted restaurant*/
    vector<QString>         deletedItems;    /**<Saves name of deleted item*/
    vector<double>          deletedPrices;   /**<Saves price of deleted item*/
    vector<Restaurant>      restaurantList;  /**<Saves the restaurant list*/
    vector<QRadioButton*>   buttonList;      /**<Saves the button list*/
    vector<QCheckBox*>      checkButtonList; /**<Saves the check button list*/
};

#endif // DELETEITEM_H
