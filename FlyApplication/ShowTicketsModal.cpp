#include "ShowTicketsModal.h"

ShowTicketsModal::ShowTicketsModal(std::map<QString, Flight*>* flights, std::map<QString, int>* tickets){

    this->vbox = new QVBoxLayout;
    this->TicketListWidget = new QListWidget;
    this->tickets = tickets;



    printTickets(tickets);

    connect(TicketListWidget, &QListWidget::itemClicked, [=](){
        QString ID = TicketListWidget->currentItem()->text().split(" ")[0];
        tickets->operator[](ID)--;
        *flights->operator[](ID) += 1;
        if(tickets->operator[](ID) == 0){
            this->tickets->erase(ID);
        }

        TicketListWidget->clear();
        printTickets(tickets);
        qDebug() << tickets->size();
    });

    vbox->addWidget(TicketListWidget);

    this->setLayout(vbox);

}

ShowTicketsModal::~ShowTicketsModal(){

    delete this->vbox;

    delete this->TicketListWidget;

    delete this->tickets;
}

void ShowTicketsModal::printTickets(std::map<QString, int>* tickets){
    for(auto & item : *this->tickets){
        QListWidgetItem *ticket = new QListWidgetItem(item.first + " - " + QString::number(item.second));
        TicketListWidget->addItem(ticket);
        ticket->setTextAlignment(Qt::AlignCenter);
    }
}
