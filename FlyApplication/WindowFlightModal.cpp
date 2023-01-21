#include "WindowFlightModal.h"

WindowFlightModal::WindowFlightModal(Flight* flight){

    connect(this, &QDialog::finished, this, [this]{
       emit windowClosed(isEdit);
    });


    this->vbox = new QVBoxLayout();

    this->FlightsInformation = new QListWidget;

    this->itemID = new QListWidgetItem("ID: " + flight->getID());
    this->itemStatus = new QListWidgetItem("Status: " + flight->getStatus());
    this->itemArrivalPlace = new QListWidgetItem("Arrival place: " + flight->getArrivalPlace());
    this->itemDeparturePlace = new QListWidgetItem("Departure place: " + flight->getDeparturePlace());
    this->itemDepartureTime = new QListWidgetItem("Departure time: " + QString::number(flight->getDepartureTime()));
    this->itemArrivalTime = new QListWidgetItem("Arrival time: " + QString::number(flight->getArrivalTime()));
    this->itemSeatsAvailabe = new QListWidgetItem("Seats Availabe: " + QString::number(flight->getSeatsAvailable()));

    FlightsInformation->addItem(itemID);
    FlightsInformation->addItem(itemStatus);
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
