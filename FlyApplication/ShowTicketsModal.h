/**
@file ShowTicketsModal.h
@brief The ShowTicketsModal class is a QDialog derived class that displays a list of tickets for a flight.
*/

#pragma once

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include <QDialog>
#include <WindowFlightModal.h>
#include <Flight.h>

/**
*@class ShowTicketsModal
*@brief The ShowTicketsModal class is a QDialog derived class that displays a list of tickets for a flight.
*/

class ShowTicketsModal : public QDialog
{
    Q_OBJECT
public:
    /*
    *@brief Constructs a ShowTicketsModal object. Creates a window that displays the purchased lots and their quantity.
    *It includes the onClick function that allows you to sell the purchased ticket.
    *@param flights A pointer to a map of flight objects
    *@param tickets A pointer to a map of ticket counts
    */
    ShowTicketsModal(std::map<QString, Flight*>*, std::map<QString, int>*);
    /**
    *@brief Destructs a ShowTicketsModal object
    */
    ~ShowTicketsModal();
    /**
    *@brief Prints the tickets from map to the window
    *@param tickets A pointer to a map of ticket counts
    */
    void printTickets(std::map<QString, int>*);

private:
    /**
    @brief A pointer to a QVBoxLayout object
    */
    QVBoxLayout *vbox;
    /**<
    *@brief A pointer to a QListWidget object
    */
    QListWidget *TicketListWidget;
    /**
    *@brief A pointer to a map of ticket counts
    */
    std::map<QString, int>* tickets;
};
