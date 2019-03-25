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
    File: adminsettingmenu.h
    Class for the user interface of custom trip
    menu.
*/

#ifndef CUSTOMTRIPMENU_H
#define CUSTOMTRIPMENU_H

#include <QDialog>
#include <vector>
#include <string>
#include "Restaurant.h"
#include <qcheckbox.h>
#include <QButtonGroup>

using namespace std;

namespace Ui {
class CustomTripMenu;
}

/**
@brief used to allow foodie to plan a custom trip
*/
class CustomTripMenu : public QDialog
{
    Q_OBJECT

public:
/** Default Constructor
*/
    explicit CustomTripMenu(QWidget *parent);

/** Returns boolean for back
@return back
*/
    bool returnBack();

/** adds checkboxes for each restaurant currently in the database
@param restaurant - Vector of restaurants currently in the database
*/
    void fillCheckBoxes(vector<Restaurant> restaurant);

/** Returns the vector of selected Restaurants
@return selectedRestaurants - Vector of selected restaurants
*/
    vector<Restaurant> ReturnSelectedRestaurant();

/** Returns the vector of IDs chosen
@param - IDRestaurants - Vector of Chosen Restaurants
*/
    vector<int> ReturnIDsChosenRestaurants();

/** Returns boolean Not Selected
@return notSelected - boolean to check if a checkbox is selected
*/
    bool returnNotSelected();

/** Returns the total distance
@return totalDistance - the total distance traveled
*/
    double returnTotalDistance();

/** Destructor
*/
    ~CustomTripMenu();

private slots:
/** SetOnAction buttonBox rejected
*/
    void on_buttonBox_rejected();
/** SetOnAction buttonBox accepted
*/
    void on_buttonBox_accepted();
/** SetOnAction pushbutton clicked
*/
    void on_pushButton_clicked();

private:
    Ui::CustomTripMenu *CTui; /**<UI for the admin settings menu*/
    bool back {false}; /**<boolean for when back is pressed*/
    bool notSelected; /**<boolean for if a checkbox is not selected*/
    double totalDistance; /**<double for the total distance*/
    int first; /**<int for ID of starting restaurant*/
    QButtonGroup group; /**<Groups buttons together*/
    vector<Restaurant> restaurantList; /**<vector for Restaurant List*/
    vector<QCheckBox*> checkBoxList; /**<Vector for the checkboxes*/
    vector<Restaurant> selectedRestaurant; /**<Vector for the selected restaurants*/
    vector<int> IDsChosenRestaurants; /**<Vector for the IDs of all the restaurants foodie would like to attend*/
};

#endif // CUSTOMTRIPMENU_H
