/**
*@file EditFlightModal.h
*@brief This file contains the declaration of the EditFlightModal class.
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
#include <QTimeEdit>
#include <QSpinBox>
#include <QDateEdit>
#include <QTime>
#include <QDate>

#include <Flight.h>

/**
*@class EditFlightModal
*@brief The EditFlightModal class is a dialog box for editing a flight.
*/

class EditFlightModal : public QDialog
{
    Q_OBJECT
public:
    /*
    *@brief Constructs an EditFlightModal object with a given flight.
    *Creates edit flight window with inputs to update information about given Flight after click "Ok" button.
    *@param flight A pointer to the flight information to be edited.
    */
    EditFlightModal(Flight*);
    /**
    *@brief Destroys the EditFlightModal object.
    */
    ~EditFlightModal();

private:
    /**
    *@brief The main layout of the dialog box.
    */
    QVBoxLayout *vbox;
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
    QLabel *departureDateLabel;
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
    *@brief The input field for the number of seats available on the flight.
    */
    QSpinBox *seatsAvailableInput;
    /**
    *@brief The label for the number of seats available input field.
    */
    QLabel* seatsAvailableLabel;
};
