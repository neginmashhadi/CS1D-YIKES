#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Restaurants restaurants;

    QApplication a(argc, argv);
    
    Database myDatabase;
    myDatabase.InputFileToDatabase(":/resources/Input.txt.txt");
    
    MainWindow w;
    w.show();

    return a.exec();
}
