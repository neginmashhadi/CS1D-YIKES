#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Restaurants restaurants;

    QApplication a(argc, argv);
    
//    Database myDatabase;
//    myDatabase.InputFileToDatabase(":/files/Input.txt");

//    myDatabase.DatabaseToRestaurants();
//    myDatabase.testDatabase();
    
    MainWindow w;
    w.show();

    return a.exec();
}
