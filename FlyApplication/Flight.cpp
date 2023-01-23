#include "Flight.h"

Flight::Flight(){
    ID = "";
    Status = "";
    ArrivalPlace = "";
    DeparturePlace = "";
    DepartureDateDay = 0;
    DepartureDateMonth = 0;
    DepartureDateYear = 0;
    DepartureTimeHour = 0;
    DepartureTimeMinute = 0;
    ArrivalTimeHour = 0;
    ArrivalTimeMinute = 0;
    SeatsAvailabe = 0;
}

Flight::Flight(QString ID, QString Status, QString ArrivalPlace, QString DeparturePlace,
               int DepartureDateDay, int DepartureDateMonth, int DepartureDateYear,
               int DepartureTimeHour, int DepartureTimeMinute, int ArrivalTimeHour,
               int ArrivalTimeMinute, int SeatsAvailabe) :
    ID(ID), Status(Status), ArrivalPlace(ArrivalPlace), DeparturePlace(DeparturePlace),
    DepartureDateDay(DepartureDateDay) , DepartureDateMonth(DepartureDateMonth), DepartureDateYear(DepartureDateYear),
    DepartureTimeHour(DepartureTimeHour), DepartureTimeMinute(DepartureTimeMinute), ArrivalTimeHour(ArrivalTimeHour),
    ArrivalTimeMinute(ArrivalTimeMinute), SeatsAvailabe(SeatsAvailabe) {

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

    file.write(reinterpret_cast<char*>(&DepartureDateDay), sizeof(DepartureDateDay));
    file.write(reinterpret_cast<char*>(&DepartureDateMonth), sizeof(DepartureDateMonth));
    file.write(reinterpret_cast<char*>(&DepartureDateYear), sizeof(DepartureDateYear));
    file.write(reinterpret_cast<char*>(&DepartureTimeHour), sizeof(DepartureTimeHour));
    file.write(reinterpret_cast<char*>(&DepartureTimeMinute), sizeof(DepartureTimeMinute));
    file.write(reinterpret_cast<char*>(&ArrivalTimeHour), sizeof(ArrivalTimeHour));
    file.write(reinterpret_cast<char*>(&ArrivalTimeMinute), sizeof(ArrivalTimeMinute));
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

    file.read(reinterpret_cast<char*>(&DepartureDateDay), sizeof(DepartureDateDay));
    file.read(reinterpret_cast<char*>(&DepartureDateMonth), sizeof(DepartureDateMonth));
    file.read(reinterpret_cast<char*>(&DepartureDateYear), sizeof(DepartureDateYear));
    file.read(reinterpret_cast<char*>(&DepartureTimeHour), sizeof(DepartureTimeHour));
    file.read(reinterpret_cast<char*>(&DepartureTimeMinute), sizeof(DepartureTimeMinute));
    file.read(reinterpret_cast<char*>(&ArrivalTimeHour), sizeof(ArrivalTimeHour));
    file.read(reinterpret_cast<char*>(&ArrivalTimeMinute), sizeof(ArrivalTimeMinute));
    file.read(reinterpret_cast<char*>(&SeatsAvailabe), sizeof(SeatsAvailabe));

    ID = QString::fromStdString(stringID);
    Status = QString::fromStdString(stringStatus);
    ArrivalPlace = QString::fromStdString(stringArrivalPlace);
    DeparturePlace = QString::fromStdString(stringDeparturePlace);

    qDebug() << ID << ", " << Status << ", " << ArrivalPlace << ", " << DeparturePlace
             << ", " << DepartureDateDay << "." << DepartureDateMonth << "." << DepartureDateYear
             << ", " << DepartureTimeHour << ":" << DepartureTimeMinute << ", " << ArrivalTimeHour
             << ":" << ArrivalTimeMinute << ", " << SeatsAvailabe;
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

int Flight::getDepartureDateDay(){
    return DepartureDateDay;
}

void Flight::setDepartureDateDay(int DepartureDateDay){
    this->DepartureDateDay = DepartureDateDay;
}

int Flight::getDepartureDateMonth(){
    return DepartureDateMonth;
}

void Flight::setDepartureDateMonth(int DepartureDateMonth){
    this->DepartureDateMonth = DepartureDateMonth;
}

int Flight::getDepartureDateYear(){
    return DepartureDateYear;
}

void Flight::setDepartureDateYear(int DepartureDateYear){
    this->DepartureDateYear = DepartureDateYear;
}

int Flight::getDepartureTimeHour(){
    return DepartureTimeHour;
}

void Flight::setDepartureTimeHour(int DepartureTimeHour){
    this->DepartureTimeHour = DepartureTimeHour;
}

int Flight::getDepartureTimeMinute(){
    return DepartureTimeMinute;
}

void Flight::setDepartureTimeMinute(int DepartureTimeMinute){
    this->DepartureTimeMinute = DepartureTimeMinute;
}

int Flight::getArrivalTimeHour(){
    return ArrivalTimeHour;
}

void Flight::setArrivalTimeHour(int ArrivalTimeHour){
    this->ArrivalTimeHour = ArrivalTimeHour;
}

int Flight::getArrivalTimeMinute(){
    return ArrivalTimeMinute;
}

void Flight::setArrivalTimeMinute(int ArrivalTimeMinute){
    this->ArrivalTimeMinute = ArrivalTimeMinute;
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

Flight& Flight::operator+=(int rhs){
    SeatsAvailabe = SeatsAvailabe + rhs;

    return *this;
}
