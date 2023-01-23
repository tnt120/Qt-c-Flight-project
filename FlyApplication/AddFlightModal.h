/**

@file AddFlightModal.h
@brief This file contains the declaration of the AddFlightModal class.
*/

#pragma once

#include <functional>

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QDialog>
#include <QSpinBox>
#include <QTimeEdit>
#include <QDateEdit>
#include <QDate>

/**

*@class AddFlightModal

*@brief The AddFlightModal class is a dialog box for adding a new flight.
*/

class AddFlightModal : public QDialog
{
    Q_OBJECT
public:
    /**
    *@brief Constructs an AddFlightModal object with a given callback function.
    *Creates add flight window with inputs create new Flight object and add it to map with Flights after click button "Add"
    *@param callback A function that takes in the flight information as arguments and is called when the "Add" button is pressed.
    */
    AddFlightModal(std::function<void (QString, QString, QString, QString, int, int, int, int, int, int, int, int)>);

    /**

    *@brief Destroys the AddFlightModal object.
    */
    ~AddFlightModal();

private:
    /**
    *@brief The main layout of the dialog box.
    */
    QVBoxLayout *vbox;

    /**
    *@brief The input field for the flight ID.
    */
    QLineEdit *idInput;
    /**
    *@brief The label for the flight ID input field.
    */
    QLabel* idLabel;
    /**
    *@brief The input field for the flight status.
    */
    QLineEdit *statusInput;
    /**
    *@brief The label for the flight status input field.
    */
    QLabel* statusLabel;
    /**
    *@brief The input field for the flight arrival place.
    */
    QLineEdit *arrivalPlaceInput;
    /**
    *@brief The label for the flight arrival place input field.
    */
    QLabel* arrivalPlaceLabel;

    /**
    *@brief The input field for the flight departure place.
    */
    QLineEdit *departurePlaceInput;
    /**
    *@brief The label for the flight departure place input field.
    */
    QLabel* departurePlaceLabel;
    /**
    *@brief The input field for the flight departure date.
    */
    QDateEdit *departureDateInput;
    /**
    *@brief The label for the flight departure date input field.
    */
    QLabel* departureDateLabel;
    /**
    *@brief The input field for the flight departure time.
    */
    QTimeEdit *departureTimeInput;
    /**
    *@brief The label for the flight departure time input field.
    */
    QLabel* departureTimeLabel;
    /**
    *@brief The input field for the flight arrival time.
    */
    QTimeEdit *arrivalTimeInput;
    /**
    *@brief The label for the flight arrival time input field.
    */
    QLabel* arrivalTimeLabel;
    /**
    *@brief The input field for the flight seats available.
    */
    QSpinBox *seatsAvailableInput;
    /**
    *@brief The label for the flight arrival time input field.
    */
    QLabel* seatsAvailableLabel;
};
