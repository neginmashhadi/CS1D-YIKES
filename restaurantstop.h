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
    File: restaurantstop.h
    Class used to deal with the user interface for each
    stop at every restaurant
*/

#ifndef RESTAURANTSTOP_H
#define RESTAURANTSTOP_H

#include "structs.h"

#include <vector>
#include <string>
#include "Restaurant.h"
#include <qcheckbox.h>
#include <QSpinBox>

namespace Ui
{
class restaurantStop;
}

/**
 * @brief The restaurantStop class
 */
class restaurantStop : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief restaurantStop - The constructor
     * @param restaurant     - vector of restaurants
     * @param keyList        - vector of  keys
     * @param parent
     */
    explicit restaurantStop(vector<Restaurant> restaurant, vector<int> keyList, QWidget *parent = nullptr);
    /**
     * @brief fillCheckBoxes - checks if checkboxes have been selected and
     *  will execute the selected checkboxes
     */
    void fillCheckBoxes();

    vector<foodAndPrice> returnEachRestantFood();
    /**
     * @brief returnNotExit - returns the notExit private data member
     * @return notExit
     */

    bool returnNotExit();
    /**
    * @brief destructor
    */
    ~restaurantStop();

private slots:
    /**
     * @brief on_buttonBox_accepted - begins reading the selected restaurants by foodie
     */
    void on_buttonBox_accepted();
    /**
     * @brief on_buttonBox_rejected - goes back to the MainWindow
     */
    void on_buttonBox_rejected();
    /**
     * @brief on_Next_Button_clicked - moves on to the next selected restaurant
     */
    void on_Next_Button_clicked();
    /**
     * @brief on_Submit_Button_clicked - submits all the selected detailes made by foodie
     */
    void on_Submit_Button_clicked();

private:
    Ui::restaurantStop *ui;  /**<UI for RestaurantStop*/
    vector<Restaurant> restaurantList;  /**<Vector of restaurants*/
    vector<QCheckBox*> checkBoxList; /**<List of all the checkboxes*/
    vector<QSpinBox*> spinBoxList; /**<List for the spinboxes*/
    vector<MenuItem> selectedFood;  /**<Vector for the food items selected*/
    vector<foodAndPrice> eachRestantFood; /**<Vector for each Restaurant Food item*/
    vector<int> stopKey;  /**<Vector for all the stops using restaurant ID*/
    bool notExit;  /**<Boolean for the cancel button*/
    int counter;   /**<counter used for loops within class*/
};

#endif // RESTAURANTSTOP_H
