#include "Flight.h"

Flight::Flight(){
    ID = "";
    Status = "";
    ArrivalPlace = "";
    DeparturePlace = "";
    DepartureTime = 0;
    ArrivalTime = 0;
    SeatsAvailabe = 0;
}

Flight::Flight(QString ID, QString Status, QString ArrivalPlace, QString DeparturePlace, int DepartureTime, int ArrivalTime, int SeatsAvailabe) :
    QPushButton(ID) , ID(ID), Status(Status), ArrivalPlace(ArrivalPlace), DeparturePlace(DeparturePlace), DepartureTime(DepartureTime) , ArrivalTime(ArrivalTime), SeatsAvailabe(SeatsAvailabe) {

}

void Flight::saveToBinary(std::ofstream & file){
    int sizeID = ID.size();
    int sizeStatus = Status.size();
    int sizeArrivalPlace = ArrivalPlace.size();
    int sizeDeparturePlace = DeparturePlace.size();

    file.write(reinterpret_cast<char*>(&sizeID), sizeof(sizeID));
    file.write(&ID.toStdString()[0], sizeID);

    file.write(reinterpret_cast<char*>(&sizeStatus), sizeof(sizeStatus));
    file.write(&Status.toStdString()[0], sizeStatus);

    file.write(reinterpret_cast<char*>(&sizeArrivalPlace), sizeof(sizeArrivalPlace));
    file.write(&ArrivalPlace.toStdString()[0], sizeArrivalPlace);

    file.write(reinterpret_cast<char*>(&sizeDeparturePlace), sizeof(sizeDeparturePlace));
    file.write(&DeparturePlace.toStdString()[0], sizeDeparturePlace);

    file.write(reinterpret_cast<char*>(&DepartureTime), sizeof(DepartureTime));
    file.write(reinterpret_cast<char*>(&ArrivalTime), sizeof(ArrivalTime));
    file.write(reinterpret_cast<char*>(&SeatsAvailabe), sizeof(SeatsAvailabe));

}

void Flight::readFromBinary(std::ifstream & file){
    int sizeID;
    int sizeStatus;
    int sizeArrivalPlace;
    int sizeDeparturePlace;

    std::string stringID;
    std::string stringStatus;
    std::string stringArrivalPlace;
    std::string stringDeparturePlace;


    file.read(reinterpret_cast<char*>(&sizeID), sizeof(sizeID));
    stringID.resize(sizeID);
    file.read(&stringID[0], sizeID);

    file.read(reinterpret_cast<char*>(&sizeStatus), sizeof(sizeStatus));
    stringStatus.resize(sizeStatus);
    file.read(&stringStatus[0], sizeStatus);

    file.read(reinterpret_cast<char*>(&sizeArrivalPlace), sizeof(sizeArrivalPlace));
    stringArrivalPlace.resize(sizeArrivalPlace);
    file.read(&stringArrivalPlace[0], sizeArrivalPlace);

    file.read(reinterpret_cast<char*>(&sizeDeparturePlace), sizeof(sizeDeparturePlace));
    stringDeparturePlace.resize(sizeDeparturePlace);
    file.read(&stringDeparturePlace[0], sizeDeparturePlace);

    file.read(reinterpret_cast<char*>(&DepartureTime), sizeof(DepartureTime));
    file.read(reinterpret_cast<char*>(&ArrivalTime), sizeof(ArrivalTime));
    file.read(reinterpret_cast<char*>(&SeatsAvailabe), sizeof(SeatsAvailabe));

    ID = QString::fromStdString(stringID);
    Status = QString::fromStdString(stringStatus);
    ArrivalPlace = QString::fromStdString(stringArrivalPlace);
    DeparturePlace = QString::fromStdString(stringDeparturePlace);

    qDebug() << ID << ", " << Status << ", " << ArrivalPlace << ", " << DeparturePlace
             << ", " << DepartureTime << ", " << ArrivalTime << ", " << SeatsAvailabe;
}

QString Flight::getID(){
    return ID;
}

void Flight::setID(QString ID){
    this->ID = ID;
}

QString Flight::getStatus(){
    return Status;
}

void Flight::setStatus(QString Status){
    this->Status = Status;
}

QString Flight::getArrivalPlace(){
    return ArrivalPlace;
}

void Flight::setArrivalPlace(QString ArrivalPlace){
    this->ArrivalPlace = ArrivalPlace;
}

QString Flight::getDeparturePlace(){
    return DeparturePlace;
}

void Flight::setDeparturePlace(QString DeparturePlace){
    this->DeparturePlace = DeparturePlace;
}

int Flight::getDepartureTime(){
    return DepartureTime;
}

void Flight::setDepartureTime(int DepartureTime){
    this->DepartureTime = DepartureTime;
}

int Flight::getArrivalTime(){
    return ArrivalTime;
}

void Flight::setArrivalTime(int ArrivalTime){
    this->ArrivalTime = ArrivalTime;
}

int Flight::getSeatsAvailable(){
    return SeatsAvailabe;
}

void Flight::setSeatsAvailable(int SeatsAvailable){
    this->SeatsAvailabe = SeatsAvailable;
}

Flight& Flight::operator-=(int rhs){

    SeatsAvailabe = SeatsAvailabe - rhs;

    return *this;
}
