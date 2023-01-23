#include "MainWindow.h"

#include <QApplication>

#include <iostream>
#include <fstream>
#include <Flight.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool isAdminMode = false;

    try {
        if(argc != 2){
            throw std::invalid_argument("Invalid number of arguments");
        }

        std::string param = argv[1];

        if(param == "admin"){
            isAdminMode = true;
        }
        else if(param != "user"){
            throw std::invalid_argument("Invalid argument");
        }
    } catch (std::exception &e) {
        qDebug() << e.what();
        exit(-1);
    }

    MainWindow w(isAdminMode);

    return a.exec();
}
