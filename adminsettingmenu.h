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
    ~AdminSettingMenu();

private slots:
     void on_buttonBox_rejected();

     void on_buttonBox_accepted();

private:
    Ui::AdminSettingMenu *ui;
    bool back {false};
    int next;

};

#endif // ADMINSETTINGMENU_H
