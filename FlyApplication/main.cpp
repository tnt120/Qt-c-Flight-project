#include "MainWindow.h"

#include <QApplication>

#include <iostream>
#include <fstream>
#include <Flight.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc != 2){
        throw std::invalid_argument("Invalid number of arguments");
    }

    std::string param = argv[1];

    bool isAdminMode = false;

    if(param == "admin"){
        isAdminMode = true;
    }
    else if(param != "user"){
        throw std::invalid_argument("Invalid argument");
    }

    MainWindow w(isAdminMode);
    //w.show();

    return a.exec();
}
