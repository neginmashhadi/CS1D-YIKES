#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QCloseEvent>
#include <QDialog>
#include <vector>
#include <string>
using namespace std;

struct foodAndPrice
{
    QString name;
    vector<QString> food;
    vector<float> price;
};

#endif // FUNCTIONS_H
