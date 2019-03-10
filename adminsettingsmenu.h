#ifndef ADMINSETTINGSMENU_H
#define ADMINSETTINGSMENU_H

#include <QDialog>

namespace Ui {
class AdminSettingsMenu;
}

class AdminSettingsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminSettingsMenu(QWidget *parent = nullptr);
    ~AdminSettingsMenu();

    bool returnBack();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_4_clicked();

    void on_settingMenu_Cancel_clicked();

    void on_buttonBox_rejected();

private:
    Ui::AdminSettingsMenu *ui;

    bool back {false};
};

#endif // ADMINSETTINGSMENU_H
