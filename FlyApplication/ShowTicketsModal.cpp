#include "ShowTicketsModal.h"

ShowTicketsModal::ShowTicketsModal(std::map<QString, int>* tickets){

    this->vbox = new QVBoxLayout;
    this->TicketListWidget = new QListWidget;
    this->tickets = tickets;

    qDebug() << tickets->size();

    for(auto & item : *this->tickets){
        QListWidgetItem *ticket = new QListWidgetItem(item.first + " - " + QString::number(item.second));
        TicketListWidget->addItem(ticket);
        ticket->setTextAlignment(Qt::AlignCenter);
    }

    vbox->addWidget(TicketListWidget);

    this->setLayout(vbox);

}

ShowTicketsModal::~ShowTicketsModal(){

    delete this->vbox;

    delete this->TicketListWidget;

    delete this->tickets;
}
