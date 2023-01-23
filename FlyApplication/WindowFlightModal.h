/**

@file WindowFlightModal.h
@brief This file contains the declaration of the WindowFlightModal class.
*/

#pragma once

#include <functional>

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QPushButton>
#include <vector>
#include <QDialog>

#include <Flight.h>

/**
*@class WindowFlightModal
*@brief The WindowFlightModal class is an abstract class that provides a basic layout for displaying flight information in a modal window.
*/

class WindowFlightModal : public QDialog
{
    Q_OBJECT
public:
    /*
    *@brief Constructs a WindowFlightModal object for a given flight. Create a window which displays information about given Flight
    *@param flight A pointer to the flight to be displayed.
    */
    WindowFlightModal(Flight*);
    /**
    *@brief Destroys the WindowFlightModal object.
    */
    ~WindowFlightModal();

protected:
    QVBoxLayout *vbox;

    QListWidget *FlightsInformation;

    QListWidgetItem *itemID;
    QListWidgetItem *itemStatus;
    QListWidgetItem *itemDepartureDate;
    QListWidgetItem *itemArrivalPlace;
    QListWidgetItem *itemDeparturePlace;
    QListWidgetItem *itemDepartureTime;
    QListWidgetItem *itemArrivalTime;
    QListWidgetItem *itemSeatsAvailabe;

    bool isEdit = false;

    /**
    *@brief A pure virtual function that print to console information about closed specific window
    */
    virtual void writeInfo() = 0;

signals:
    /**
    *@brief A signal that is emitted when the window is closed.
    *@param isEdit A boolean that indicates whether the window was in edit mode.
    */
    void windowClosed(bool isEdit);

};

