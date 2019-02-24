#ifndef CUSTOMTRIPMENU_H
#define CUSTOMTRIPMENU_H

#include <QDialog>
#include <vector>
#include <string>
#include "mainwindow.h"

using namespace std;

namespace Ui {
class CustomTripMenu;
}

class CustomTripMenu : public QDialog//, public MainWindow
{
    Q_OBJECT

public:
    explicit CustomTripMenu(QWidget *parent);
    bool returnBack();
    ~CustomTripMenu();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::CustomTripMenu *CTui;
    bool back {false};
    vector<string> restaurants;
};

#endif // CUSTOMTRIPMENU_H
