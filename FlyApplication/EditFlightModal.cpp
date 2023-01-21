#include <EditFlightModal.h>

EditFlightModal::EditFlightModal(Flight* flight) {

    this->vbox = new QVBoxLayout();

    this->statusLabel = new QLabel("Insert fly status");
    this->statusInput = new QLineEdit(flight->getStatus());

    this->departurePlaceLabel = new QLabel("Insert fly departure place");
    this->departurePlaceInput = new QLineEdit(flight->getDeparturePlace());

    this->departureTimeLabel = new QLabel("Insert fly departure time");
    this->departureTimeInput = new QLineEdit(QString::number(flight->getDepartureTime()));

    this->arrivalPlaceLabel = new QLabel("Insert fly arrival place");
    this->arrivalPlaceInput = new QLineEdit(flight->getArrivalPlace());

    this->arrivalTimeLabel = new QLabel("Insert fly arrival time");
    this->arrivalTimeInput = new QLineEdit(QString::number(flight->getArrivalTime()));

    this->seatsAvailableLabel = new QLabel("Insert fly seats available");
    this->seatsAvailableInput = new QLineEdit(QString::number(flight->getSeatsAvailable()));


    QPushButton* okButton = new QPushButton("OK");

    connect(okButton, &QPushButton::clicked, [=]() {
        //this->onOkPress();
        flight->setStatus(this->statusInput->text());
        flight->setDeparturePlace(this->departurePlaceInput->text());
        flight->setDepartureTime(this->departureTimeInput->text().toInt());
        flight->setArrivalPlace(this->arrivalPlaceInput->text());
        flight->setArrivalTime(this->arrivalTimeInput->text().toInt());
        flight->setSeatsAvailable(this->seatsAvailableInput->text().toInt());

        this->close();
        this->deleteLater();
    });

    vbox->addWidget(statusLabel);
    vbox->addWidget(statusInput);

    vbox->addWidget(departurePlaceLabel);
    vbox->addWidget(departurePlaceInput);

    vbox->addWidget(departureTimeLabel);
    vbox->addWidget(departureTimeInput);

    vbox->addWidget(arrivalPlaceLabel);
    vbox->addWidget(arrivalPlaceInput);

    vbox->addWidget(arrivalTimeLabel);
    vbox->addWidget(arrivalTimeInput);

    vbox->addWidget(seatsAvailableLabel);
    vbox->addWidget(seatsAvailableInput);

    vbox->addWidget(okButton);
    vbox->addStretch(1);
    this->setLayout(vbox);
}

EditFlightModal::~EditFlightModal(){
    delete this->vbox;

    delete this->statusLabel;
    delete this->statusInput;

    delete this->departurePlaceLabel;
    delete this->departurePlaceInput;

    delete this->departureTimeLabel;
    delete this->departureTimeInput;

    delete this->arrivalPlaceLabel;
    delete this->arrivalPlaceInput;

    delete this->arrivalTimeLabel;
    delete this->arrivalTimeInput;

    delete this->seatsAvailableLabel;
    delete this->seatsAvailableInput;
}
