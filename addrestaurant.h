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
    File: addrestaurant.h
    Class for the user interface of adding a restaurant
*/

#ifndef ADDRESTAURANT_H
#define ADDRESTAURANT_H

#include <QDialog>

namespace Ui {
class addRestaurant;
}

/**
@brief used to add restaurants
*/
class addRestaurant : public QDialog
{
    Q_OBJECT

    public:
    /** Default constructor
    */
        explicit addRestaurant(QWidget *parent = nullptr);

    /** Returns if the add button was clicked
    @return clicked boolean
    */
        bool returnClicked();

    /** Returns if the path exists
    @return path boolean
    */
        bool getPathBool();

    /** Gets the path string
    @return path
    */
        QString getPath();

    /** Destructor
    */
        ~addRestaurant();

    private slots:
    /** OnActionClicked - pushbutton1
    */
        void on_pushButton_clicked();

    /** OnActionClicked - pushbutton1
    */
        void on_pushButton_2_clicked();

    private:
        Ui::addRestaurant *ui;  /**<UI for addRestaurant*/
        QString newFile;  /**<QString for the new input file*/
        QString path; /**<holds the path*/
        bool clicked; /**<Set true if button is clicked*/
        bool pathBool{false}; /**<Set true if path is valid*/
};

#endif // ADDRESTAURANT_H
