/**
*@file BuyFlightModal.h
*@brief This file contains the declaration of the BuyFlightModal class.
*/

#pragma once

#include <WindowFlightModal.h>

/**
*@class BuyFlightModal
*@brief The BuyFlightModal class is a dialog box for buying a flight ticket.
*/

class BuyFlightModal : public WindowFlightModal
{
    Q_OBJECT
public:
    /*
    *@brief Constructs a BuyFlightModal object with a given flight and a pointer to a map of flight tickets.
    *Adds "Buy" button with function to buy a given flight.
    *@param flight A pointer to the flight information to be displayed in the dialog box.
    *@param tickets A pointer to a map containing the user's flight tickets.
    */
    BuyFlightModal(Flight* flight, std::map<QString, int>*);
    /**
    *@brief Destroys the BuyFlightModal object.
    */
    ~BuyFlightModal();
    /**
    *@brief Writes to console an announcement about closed window.
    */
    void writeInfo() override;
    /**
    *@brief Updates the number of bought tickets for a given flight in the map of tickets.
    *@tparam T The type of the value stored in the map.
    *@param ID The flight ID.
    *@param tickets A pointer to the map of tickets.
    */
    template<typename T>
    void updateTickets(QString ID, std::map<QString, T>* tickets){

        if(tickets->size() == 0){
            tickets->operator[](ID) = 1;
        }
        else{
            if(tickets->find(ID) == tickets->end()){
                tickets->operator[](ID) = 1;
            }
            else{
                tickets->operator[](ID)++;
            }
        }
    }

private:
    /**
    *@brief The "Buy" button.
    */
    QPushButton *BuyButton;
};
