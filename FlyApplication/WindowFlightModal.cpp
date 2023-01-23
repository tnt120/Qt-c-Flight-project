#include "WindowFlightModal.h"

WindowFlightModal::WindowFlightModal(Flight* flight){

    connect(this, &QDialog::finished, this, [this]{
       emit windowClosed(isEdit);
    });


    this->vbox = new QVBoxLayout();

    this->FlightsInformation = new QListWidget;

    this->itemID = new QListWidgetItem("ID: " + flight->getID());
    this->itemStatus = new QListWidgetItem("Status: " + flight->getStatus());
    this->itemDepartureDate = new QListWidgetItem("Date: " + QString::number(flight->getDepartureDateDay()) + "."
                                                  + QString::number(flight->getDepartureDateMonth()) + "."
                                                  + QString::number(flight->getDepartureDateYear()));
    this->itemArrivalPlace = new QListWidgetItem("Arrival place: " + flight->getArrivalPlace());
    this->itemDeparturePlace = new QListWidgetItem("Departure place: " + flight->getDeparturePlace());
    if(flight->getDepartureTimeMinute() == 0){
        this->itemDepartureTime = new QListWidgetItem("Departure time: " + QString::number(flight->getDepartureTimeHour()) + ":" + QString::number(flight->getDepartureTimeMinute()) + "0");
    }
    else{
        this->itemDepartureTime = new QListWidgetItem("Departure time: " + QString::number(flight->getDepartureTimeHour()) + ":" + QString::number(flight->getDepartureTimeMinute()));
    }
    if(flight->getArrivalTimeMinute() == 0){
        this->itemArrivalTime = new QListWidgetItem("Arrival time: " + QString::number(flight->getArrivalTimeHour()) + ":" + QString::number(flight->getArrivalTimeMinute()) + "0");
    }
    else{
        this->itemArrivalTime = new QListWidgetItem("Arrival time: " + QString::number(flight->getArrivalTimeHour()) + ":" + QString::number(flight->getArrivalTimeMinute()));
    }
    this->itemSeatsAvailabe = new QListWidgetItem("Seats Availabe: " + QString::number(flight->getSeatsAvailable()));

    FlightsInformation->addItem(itemID);
    FlightsInformation->addItem(itemStatus);
    FlightsInformation->addItem(itemDepartureDate);
    FlightsInformation->addItem(itemArrivalPlace);
    FlightsInformation->addItem(itemDeparturePlace);
    FlightsInformation->addItem(itemDepartureTime);
    FlightsInformation->addItem(itemArrivalTime);
    FlightsInformation->addItem(itemSeatsAvailabe);

    vbox->addWidget(FlightsInformation);

    this->setLayout(vbox);

}

WindowFlightModal::~WindowFlightModal(){
    delete this->vbox;

    delete this->FlightsInformation;
}
