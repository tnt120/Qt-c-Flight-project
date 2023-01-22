#pragma once

#include <iostream>
#include <fstream>
#include <QPushButton>

using namespace std;

class Flight: public QPushButton{

    QString ID;
    QString Status;
    QString ArrivalPlace;
    QString DeparturePlace;
    int DepartureTime;
    int ArrivalTime;
    int SeatsAvailabe;

public:

    Flight();

    Flight(QString ID, QString Status, QString ArrivalPlace, QString DeparturePlace, int DepartureTime, int ArrivalTime, int SeatsAvailabe);

    void saveToBinary(std::ofstream &);

    void readFromBinary(std::ifstream &);

    QString getID();
    void setID(QString ID);

    QString getStatus();
    void setStatus(QString Status);

    QString getArrivalPlace();
    void setArrivalPlace(QString ArrivalPlace);

    QString getDeparturePlace();
    void setDeparturePlace(QString DeparturePlace);

    int getDepartureTime();
    void setDepartureTime(int DepartureTime);

    int getArrivalTime();
    void setArrivalTime(int ArrivalTime);

    int getSeatsAvailable();
    void setSeatsAvailable(int SeatsAvailable);

    Flight& operator-=(int rhs);

};
