#ifndef BLOCKER_H
#define BLOCKER_H

#include <QWidget>

namespace Ui {
class Blocker;
}

class Blocker : public QWidget
{
    Q_OBJECT

public:
    explicit Blocker(QWidget *parent = nullptr);
    ~Blocker();

private:
    Ui::Blocker *ui;
};

#endif // BLOCKER_H
