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
    File: reinitializefirstten.h
    Class for rewriting to the database the original 10 restaurants
*/

#ifndef REINITIALIZEFIRSTTEN_H
#define REINITIALIZEFIRSTTEN_H

#include <QDialog>

namespace Ui {
class ReinitializeFirstTen;
}
/**
 * @brief The ReinitializeFirstTen class - re-initializes back to the first 10 restaurants
 */
class ReinitializeFirstTen : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief ReinitializeFirstTen - constructor
     * @param parent - QWidget pointer
     */
    explicit ReinitializeFirstTen(QWidget *parent = nullptr);
    /**
     * @brief getClicked - returns the data member clicked
     * @return clicked
     */
    bool getClicked();
    /**
    * @brief destructor
    */
    ~ReinitializeFirstTen();

private slots:
    /**
     * @brief on_pushButton_clicked - when clicked re-initializes the restaurants
     */
    void on_pushButton_clicked();

private:
    Ui::ReinitializeFirstTen *ui;  /**<UI for ReinitializeFirstTen*/
    bool clicked{false};
};

#endif // REINITIALIZEFIRSTTEN_H
