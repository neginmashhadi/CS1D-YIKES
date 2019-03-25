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
    File: adminlogin.h
    Class for the user interface of the login window
*/

#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>

namespace Ui {
class AdminLogin;
}

/**
@brief used to allow admins to login
*/
class AdminLogin : public QDialog
{
    Q_OBJECT

    public:
    /** Default constructor
    */
        explicit AdminLogin(QWidget *parent = nullptr);

    /** Checks to see if Admin Priveledges are enabled
    @return admin priveledges
    */
        bool GetAdminPriv();

    /** Destructor
    */
        ~AdminLogin();

    private slots:
    /** SetOnAction button accepted
    */
        void on_buttonBox_accepted();

    /** SetOnAction button rejected
    */
        void on_buttonBox_rejected();

    private:
        Ui::AdminLogin *ui;    /**<UI for adminlogin*/
        bool adminPrivA {false}; /**<Boolean for checking if admin has logged in*/
};

#endif // ADMINLOGIN_H
