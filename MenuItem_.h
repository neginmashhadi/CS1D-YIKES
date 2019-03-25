#ifndef MENUITEM_H
#define MENUITEM_H
#include <QString>

/**
@brief used to handle menu items information of the restaurant menu
*/
class MenuItem
{
public:
    /** Constructor
    */
    MenuItem();

    /** Alternative constructor - Gets menu item information
    @param itemName - name of the item
    @param rID - ID of the restaurant
    @param itemPrice - price of the item
    */
    MenuItem(QString itemName, int rID, double itemPrice);

    /** Set the name of the item
    @param itemName - name of the item to set
    */
    void SetItemName(QString itemName);

    /** Set the ID of the restaurant
    @param rID - ID of the restaurant to set
    */
    void SetRestaurantID(int rID);

    /** Set the price of the item
    @param itemPrice - price of the item to set
    */
    void SetPrice(double itemPrice);

    /** Get the name of the item
    @return name of the item
    */
    QString GetItemName();

    /** Get the ID of the restaurant
    @return ID of the restaurant
    */
    int GetRestaurantID();    

    /** Get the price of the item
    @return price of the item
    */
    double GetItemPrice();

private:
    int     id;     /**<Saves the ID of the restaurant*/
    QString name;   /**<Saves the name of the item*/
    double  price;  /**<Saves the price of the item*/
};

#endif // MENUITEM_H
