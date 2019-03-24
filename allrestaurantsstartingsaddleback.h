#ifndef ALLRESTAURANTSSTARTINGSADDLEBACK_H
#define ALLRESTAURANTSSTARTINGSADDLEBACK_H

#include <QDialog>

namespace Ui {
class allRestaurantsStartingSaddleback;
}

class allRestaurantsStartingSaddleback : public QDialog
{
    Q_OBJECT

public:
    explicit allRestaurantsStartingSaddleback(QWidget *parent = nullptr);
    ~allRestaurantsStartingSaddleback();

private:
    Ui::allRestaurantsStartingSaddleback *ui;
};

#endif // ALLRESTAURANTSSTARTINGSADDLEBACK_H
