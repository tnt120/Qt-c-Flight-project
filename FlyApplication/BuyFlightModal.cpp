#include <BuyFlightModal.h>

BuyFlightModal::BuyFlightModal(Flight* flight, std::map<QString, int>* tickets)
    : WindowFlightModal(flight)
{

    this->BuyButton = new QPushButton("Buy");

    this->tickets = tickets;

    if(flight->getSeatsAvailable() > 0){
        connect(BuyButton, &QPushButton::clicked, [=](){

            qDebug() << "Buy bought ticket for plane: " + flight->getID();
            flight->setSeatsAvailable(flight->getSeatsAvailable() - 1);

            updateTickets(flight->getID(), tickets);

            this->close();
            this->deleteLater();
        });

        vbox->addWidget(BuyButton);
    }

}

BuyFlightModal::~BuyFlightModal(){

    delete this->BuyButton;

}

void BuyFlightModal::writeInfo(){

    qDebug() << "Finished buy";
}
