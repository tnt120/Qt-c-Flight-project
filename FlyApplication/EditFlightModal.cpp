#include <EditFlightModal.h>

EditFlightModal::EditFlightModal(Flight* flight) {

    this->vbox = new QVBoxLayout();

    this->statusLabel = new QLabel("Edit fly status");
    this->statusInput = new QLineEdit(flight->getStatus());

    this->departureDateLabel = new QLabel("Edit fly date");
    this->departureDateInput = new QDateEdit(QDate(flight->getDepartureDateYear(), flight->getDepartureDateMonth(), flight->getDepartureDateDay()));

    this->departurePlaceLabel = new QLabel("Edit fly departure place");
    this->departurePlaceInput = new QLineEdit(flight->getDeparturePlace());

    this->departureTimeLabel = new QLabel("Edit fly departure time");
    this->departureTimeInput = new QTimeEdit(QTime(flight->getDepartureTimeHour(), flight->getDepartureTimeMinute()));

    this->arrivalPlaceLabel = new QLabel("Edit fly arrival place");
    this->arrivalPlaceInput = new QLineEdit(flight->getArrivalPlace());

    this->arrivalTimeLabel = new QLabel("Edit fly arrival time");
    this->arrivalTimeInput = new QTimeEdit(QTime(flight->getArrivalTimeHour(), flight->getArrivalTimeMinute()));

    this->seatsAvailableLabel = new QLabel("Edit fly seats available");
    this->seatsAvailableInput = new QSpinBox();
    this->seatsAvailableInput->setRange(0, 200);

    QPushButton* okButton = new QPushButton("OK");

    connect(okButton, &QPushButton::clicked, [=]() {
        //this->onOkPress();
        flight->setStatus(this->statusInput->text());
        flight->setDepartureDateDay(this->departureDateInput->date().day());
        flight->setDepartureDateMonth(this->departureDateInput->date().month());
        flight->setDepartureDateYear(this->departureDateInput->date().year());
        flight->setDeparturePlace(this->departurePlaceInput->text());
        flight->setDepartureTimeHour(this->departureTimeInput->time().hour());
        flight->setDepartureTimeMinute(this->departureTimeInput->time().minute());
        flight->setArrivalPlace(this->arrivalPlaceInput->text());
        flight->setArrivalTimeHour(this->arrivalTimeInput->time().hour());
        flight->setArrivalTimeMinute(this->arrivalTimeInput->time().minute());
        flight->setSeatsAvailable(this->seatsAvailableInput->text().toInt());

        this->close();
        this->deleteLater();
    });

    vbox->addWidget(statusLabel);
    vbox->addWidget(statusInput);

    vbox->addWidget(departureDateLabel);
    vbox->addWidget(departureDateInput);

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
