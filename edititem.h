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
    File: edititem.h
    Class for the user interface of editing an item
*/

#ifndef EDITITEM_H
#define EDITITEM_H

#include <QDialog>
#include <Restaurant.h>
#include <QString>
#include <QRadioButton>

namespace Ui {
class EditItem;
}

/**
@brief used to Edit item information of the restaurant menu
*/
class EditItem : public QDialog
{
    Q_OBJECT

public:
    /** Default constructor
    */
    explicit EditItem(QWidget *parent = nullptr);

    /** Fills the check boxes as the user chooses
    @param vector<Restaurant> restaurant - a vector of type Restaurant saving restaurant info
    */
    void fillCheckBoxes(vector<Restaurant> restaurant);

    /** Gets the old name of the item
    @return the old name of the item
    */
    QString getOldName();

    /** Gets the old price of the item
    @return the old price of the item
    */
    double  getOldPrice();

    /** Gets the new name of the item
    @return the new name of the item
    */
    QString getNewName();

    /** Gets the new price of the item
    @return the new price of the item
    */
    double  getNewPrice();

    /** Gets the restaurant ID
    @return the restaurant ID
    */
    int     getRestaurantID();

    /** Gets the edit restaurant ID
    @return the edit restaurant ID
    */
    int     getEditRestaurantID();

    /** Gets if the user decides to exit
    @return boolean expression if the user exits
    */
    bool    getExit();

    /** Destructor
    */
    ~EditItem();

private slots:
    /** Handles Next button when clicked
    */
    void on_next_button_clicked();

    /** Handles Submit button when clicked
    */
    void on_submit_button_clicked();

    /** Handles Exit/Cancel button when clicked
    */
    void on_buttonBox_rejected();

private:
    Ui::EditItem            *ui;                /**<Handles the UI for EditItem class*/
    int                     restaurantID;       /**<Saves the actual ID of the restaurant*/
    int                     editRestaurantID;   /**<Saves the index location in the restaurant vector*/
    QString                 oldName;            /**<Saves the old name*/
    double                  oldPrice;           /**<Saves the old price*/
    QString                 newName;            /**<Saves the new name*/
    double                  newPrice;           /**<Saves the new price*/
    int                     next{0};            /**<Increment element for tracking purpose*/
    bool                    exit{false};        /**<Saves T/F statement if exit*/
    vector<Restaurant>      restaurantList;     /**<Saves the restaurant list*/
    vector<QRadioButton*>   buttonList;         /**<Saves the button list*/
    vector<QRadioButton*>   checkButtonList;    /**<Saves the check button list*/
};

#endif // EDITITEM_H
