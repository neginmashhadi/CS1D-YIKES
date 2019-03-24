#ifndef ADMINSETTINGMENU_H
#define ADMINSETTINGMENU_H

#include <QDialog>

namespace Ui {
class AdminSettingMenu;
}

class AdminSettingMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminSettingMenu(QWidget *parent = nullptr);
    bool returnBack();
    int returnNext();
    bool returnNotSelected();

    ~AdminSettingMenu();

private slots:
     void on_buttonBox_rejected();

     void on_buttonBox_accepted();

     void on_RestaurantButton_clicked();

     void on_ItemButton_clicked();

private:
    Ui::AdminSettingMenu *ui;
    bool back {false};
    bool notSelected;
    int next;

};

#endif // ADMINSETTINGMENU_H
