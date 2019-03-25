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
    Class for the user interface of the admin settings
    menu.
*/


#ifndef ADMINSETTINGMENU_H
#define ADMINSETTINGMENU_H

#include <QDialog>

namespace Ui {
class AdminSettingMenu;
}

/**
@brief used to allow admins to access modification of database
*/
class AdminSettingMenu : public QDialog
{
    Q_OBJECT

    public:
    /** Default constructor
    */
        explicit AdminSettingMenu(QWidget *parent = nullptr);

    /** Returns the current condition of back button
    @return back
    */
        bool returnBack();

    /** Returns the integer for next
    @return next
    */
        int returnNext();

    /** Returns the current condition of not selected
    @return notSelected
    */
        bool returnNotSelected();

    /** Destructor
    */
        ~AdminSettingMenu();

    private slots:
        /** SetOnAction rejected pressed
        */
         void on_buttonBox_rejected();

         /** SetOnAction button pressed
         */
         void on_buttonBox_accepted();

         /** SetOnAction restaurant button clicked
         */
         void on_RestaurantButton_clicked();

         /** SetOnAction item button clicked
         */
         void on_ItemButton_clicked();

    private:
        Ui::AdminSettingMenu *ui; /**<UI for the admin settings menu*/
        bool back {false}; /**<boolean for back button*/
        bool notSelected; /**<boolean for not selected*/
        int next; /**<integer for the next*/

};

#endif // ADMINSETTINGMENU_H
