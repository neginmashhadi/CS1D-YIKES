#ifndef REINITIALIZEFIRSTTEN_H
#define REINITIALIZEFIRSTTEN_H

#include <QDialog>

namespace Ui {
class ReinitializeFirstTen;
}

class ReinitializeFirstTen : public QDialog
{
    Q_OBJECT

public:
    explicit ReinitializeFirstTen(QWidget *parent = nullptr);
    bool getClicked();
    ~ReinitializeFirstTen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ReinitializeFirstTen *ui;
    bool clicked{false};
};

#endif // REINITIALIZEFIRSTTEN_H
