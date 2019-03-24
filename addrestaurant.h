#ifndef ADDRESTAURANT_H
#define ADDRESTAURANT_H

#include <QDialog>

namespace Ui {
class addRestaurant;
}

class addRestaurant : public QDialog
{
    Q_OBJECT

public:
    explicit addRestaurant(QWidget *parent = nullptr);
    bool returnClicked();
    bool getPathBool();
    QString getPath();
    ~addRestaurant();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addRestaurant *ui;
    QString newFile;
    QString path;
    bool clicked;
    bool pathBool{false};
};

#endif // ADDRESTAURANT_H
