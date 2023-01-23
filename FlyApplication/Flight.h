/**

@file Flight.h
@brief This file contains the declaration of the Flight class.
*/

#pragma once

#include <iostream>
#include <fstream>
#include <QPushButton>

using namespace std;

/**
*@class Flight
*@brief The Flight class represents a flight and contains all information about a flight.
*/
class Flight{

    QString ID;
    QString Status;
    QString ArrivalPlace;
    QString DeparturePlace;
    int DepartureDateDay;
    int DepartureDateMonth;
    int DepartureDateYear;
    int DepartureTimeHour;
    int DepartureTimeMinute;
    int ArrivalTimeHour;
    int ArrivalTimeMinute;
    int SeatsAvailabe;

public:
    /**
    *@brief Constructs an empty Flight object.
    */
    Flight();

    /**
    *@brief Constructs a Flight object with the given flight information.
    *@param ID The flight ID.
    *@param Status The flight status.
    *@param ArrivalPlace The flight arrival place.
    *@param DeparturePlace The flight departure place.
    *@param DepartureDateDay The day of the flight departure date.
    *@param DepartureDateMonth The month of the flight departure date.
    *@param DepartureDateYear The year of the flight departure date.
    *@param DepartureTimeHour The hour of the flight departure time.
    *@param DepartureTimeMinute The minute of the flight departure time.
    *@param ArrivalTimeHour The hour of the flight arrival time.
    *@param ArrivalTimeMinute The minute of the flight arrival time.
    *@param SeatsAvailabe The number of seats available on the flight.
    */
    Flight(QString ID, QString Status, QString ArrivalPlace, QString DeparturePlace,
           int DepartureDateDay, int DepartureDateMonth, int DepartureDateYear,
           int DepartureTimeHour, int DepartureTimeMinute, int ArrivalTimeHour,
           int ArrivalTimeMinute, int SeatsAvailabe);

    /**
    *@brief Saves the flight information to a binary file.
    *@param ofstream& A reference to the output file stream.
    */
    void saveToBinary(std::ofstream &);

    /**
    *@brief Read the flight information from a binary file.
    *@param ifstream& A reference to the input file stream.
    */
    void readFromBinary(std::ifstream &);
    /**
    *@brief Getter - returning flight ID
    *@return QString flight ID
    */
    QString getID();
    /**
    *@brief Setter - updates, sets new flight ID
    *@param ID New flight ID to set
    */
    void setID(QString ID);
    /**
    *@brief Getter - returning flight Status
    *@return QString flight Status
    */
    QString getStatus();
    /**
    *@brief Setter - updates, sets new flight Status
    *@param Status New flight Status to set
    */
    void setStatus(QString Status);
    /**
    *@brief Getter - returning flight Arrival Place
    *@return QString flight Arrival Place
    */
    QString getArrivalPlace();
    /**
    *@brief Setter - updates, sets new flight Arrival Place
    *@param ArrivalPlace New flight Arrival Place to set
    */
    void setArrivalPlace(QString ArrivalPlace);
    /**
    *@brief Getter - returning flight Departure Place
    *@return QString flight Departure Place
    */
    QString getDeparturePlace();
    /**
    *@brief Setter - updates, sets new flight Departure Place
    *@param DeparturePlace New flight Departure Place to set
    */
    void setDeparturePlace(QString DeparturePlace);
    /**
    *@brief Getter - returning flight Departure Date Day
    *@return QString flight Departure Date Day
    */
    int getDepartureDateDay();
    /**
    *@brief Setter - updates, sets new flight Departure Date Day
    *@param DepartureDateDay New flight Departure Date Day to set
    */
    void setDepartureDateDay(int DepartureDateDay);
    /**
    *@brief Getter - returning flight Departure Date Month
    *@return QString flight Departure Date Month
    */
    int getDepartureDateMonth();
    /**
    *@brief Setter - updates, sets new flight Departure Date Day
    *@param DepartureDateDay New flight Departure Date Day to set
    */
    void setDepartureDateMonth(int DepartureDateMonth);
    /**
    *@brief Getter - returning flight Departure Date Year
    *@return QString flight Departure Date Year
    */
    int getDepartureDateYear();
    /**
    *@brief Setter - updates, sets new flight Departure Date Year
    *@param DepartureDateYear New flight Departure Date Year to set
    */
    void setDepartureDateYear(int DepartureDateYear);
    /**
    *@brief Getter - returning flight Departure Time Hour
    *@return QString flight Departure Time Hour
    */
    int getDepartureTimeHour();
    /**
    *@brief Setter - updates, sets new flight Departure Time Hour
    *@param DepartureTimeHour New flight Departure Time Hour to set
    */
    void setDepartureTimeHour(int DepartureTimeHour);
    /**
    *@brief Getter - returning flight Departure Time Minute
    *@return QString flight Departure Time Minute
    */
    int getDepartureTimeMinute();
    /**
    *@brief Setter - updates, sets new flight Departure Time Minute
    *@param DepartureTimeMinute New flight Departure Time Minute to set
    */
    void setDepartureTimeMinute(int DepartureTimeMinute);
    /**
    *@brief Getter - returning flight Arrival Time Hour
    *@return QString flight Arrival Time Hour
    */
    int getArrivalTimeHour();
    /**
    *@brief Setter - updates, sets new flight Arrival Time Hour
    *@param ArrivalTimeHour New flight Arrival Time Hour to set
    */
    void setArrivalTimeHour(int ArrivalTimeHour);
    /**
    *@brief Getter - returning flight Arrival Time Minute
    *@return QString flight Arrival Time Minute
    */
    int getArrivalTimeMinute();
    /**
    *@brief Setter - updates, sets new flight Arrival Time Minute
    *@param ArrivalTimeMinute New flight Arrival Time Minute to set
    */
    void setArrivalTimeMinute(int ArrivalTimeMinute);
    /**
    *@brief Getter - returning flight Seats Available
    *@return QString flight Seats Available
    */
    int getSeatsAvailable();
    /**
    *@brief Setter - updates, sets new flight Seats Available
    *@param SeatsAvailable New flight Seats Available to set
    */
    void setSeatsAvailable(int SeatsAvailable);
    /**
    *@brief Operator overload -= which reduces the number of free seats by the value given in the argument
    *@param rhs The value by which we will reduce the number of free places
    */
    Flight& operator-=(int rhs);
    /**
    *@brief Operator overload += which upgrades the number of free seats by the value given in the argument
    *@param rhs The value by which we will upgrade the number of free places
    */
    Flight & operator+=(int rhs);

};
