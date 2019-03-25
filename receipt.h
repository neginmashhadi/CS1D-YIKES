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
    File: receipt.h
    Class for managin the output and creation of the receipt
*/

#ifndef RECEIPT_H
#define RECEIPT_H

#include <QDialog>
#include "structs.h"

namespace Ui {
class receipt;
}
/**
 * @brief The receipt class - prints the recipts
 */
class receipt : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief receipt - constructor
     * @param foodList - the food item and prices
     * @param totalDistance - total distance foodie needs to travel
     * @param parent - QWidget pointer
     */
    explicit receipt(vector<foodAndPrice> foodList, double totalDistance, QWidget *parent = nullptr);

    /**
     * @brief printTable - prints a table with all the information about the selected items and restaurants
     */
    void printTable();

    /**
     * @brief printReceipt - prints the receipt for the foodie
     */
    void printReceipt();

    /**
    * @brief destructor
    */
    ~receipt();

private:
    Ui::receipt          *ui;  /**<UI for receipt*/
    vector<foodAndPrice> boughtList;  /**<vector of list of items bought*/
    double               totalDistance;  /**<total distance traveled*/
    int                  rowCount;  /**<the number of rows*/
    int                  colCount;  /**<the number of columns*/
};

#endif // RECEIPT_H
