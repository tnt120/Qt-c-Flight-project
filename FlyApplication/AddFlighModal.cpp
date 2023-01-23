#include <AddFlightModal.h>

AddFlightModal::AddFlightModal(std::function<void (QString, QString, QString, QString, int, int, int, int, int, int, int, int)> onOkPress) {

    this->vbox = new QVBoxLayout();

    this->idLabel = new QLabel("Insert fly ID");
    this->idInput = new QLineEdit();

    this->statusLabel = new QLabel("Insert fly status");
    this->statusInput = new QLineEdit();

    this->departureDateLabel = new QLabel("Insert fly date");
    this->departureDateInput = new QDateEdit(QDate(2023, 1, 23));

    this->departurePlaceLabel = new QLabel("Insert fly departure place");
    this->departurePlaceInput = new QLineEdit();

    this->departureTimeLabel = new QLabel("Insert fly departure time");
    this->departureTimeInput = new QTimeEdit();


    this->arrivalPlaceLabel = new QLabel("Insert fly arrival place");
    this->arrivalPlaceInput = new QLineEdit();

    this->arrivalTimeLabel = new QLabel("Insert fly arrival time");
    this->arrivalTimeInput = new QTimeEdit();


    this->seatsAvailableLabel = new QLabel("Insert fly seats available");
    this->seatsAvailableInput = new QSpinBox();
    this->seatsAvailableInput->setRange(0, 200);

    QPushButton* okButton = new QPushButton("OK");

    connect(okButton, &QPushButton::clicked, [=]() {
        //this->onOkPress();
        onOkPress(
            this->idInput->text(),
            this->statusInput->text(),
            this->arrivalPlaceInput->text(),
            this->departurePlaceInput->text(),
            this->departureDateInput->date().day(),
            this->departureDateInput->date().month(),
            this->departureDateInput->date().year(),
            this->departureTimeInput->time().hour(),
            this->departureTimeInput->time().minute(),
            this->arrivalTimeInput->time().hour(),
            this->arrivalTimeInput->time().minute(),
            this->seatsAvailableInput->text().toInt()
        );
        this->close();
        this->deleteLater();
    });

    vbox->addWidget(idLabel);
    vbox->addWidget(idInput);

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

AddFlightModal::~AddFlightModal() {
    delete this->vbox;

    delete this->idLabel;
    delete this->idInput;

    delete this->statusLabel;
    delete this->statusInput;

    delete this->departureDateLabel;
    delete this->departureDateInput;

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
