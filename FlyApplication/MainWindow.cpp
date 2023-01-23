#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(bool isAdminMode, QWidget *parent)
    : QMainWindow(parent)
    , isAdminMode(isAdminMode)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    Login = new LoginWindow(isAdminMode);
    Login->show();

    connect(Login, &LoginWindow::login, this, &MainWindow::loginSuccess);

    try {
        readFromFile();
    } catch (std::exception &e) {
        qDebug() << e.what();
    }

    QPushButton *SearchButton = ui->SearchButton;

    QPushButton::connect(SearchButton, &QPushButton::clicked, [=](){
        searchFlights();
    });

    QPushButton *ShowTicketsButton = ui->ShowTicketsButton;
    QPushButton *AddFlightButton = ui->AddFlightButton;
    if(isAdminMode){
        ShowTicketsButton->setVisible(false);
        QPushButton::connect(AddFlightButton, &QPushButton::clicked, [=]() {
            addFlight();
        });
    }
    else{
        AddFlightButton->setVisible(false);
        QPushButton::connect(ShowTicketsButton, &QPushButton::clicked, [=]() {
            showTickets();
        });
    }


}

MainWindow::~MainWindow()
{

    saveToFile();

    delete ui;
    for (auto & item : flights) {
        delete item.second;
    }

    delete Login;

    flights.clear();

    // upewnic sie czy na pewno dobrze to zrobie
}

void MainWindow::searchFlights()
{
    QLineEdit *inputDeparture = ui->inputDepature;
    QLineEdit *inputArrival = ui->inputArrival;

    ui->listWidget->clear();

    if(!inputDeparture->text().isEmpty() && !inputArrival->text().isEmpty()){
        for(auto & item : flights){
            if(item.second->getDeparturePlace().toUpper() == inputDeparture->text().toUpper() && item.second->getArrivalPlace().toUpper() == inputArrival->text().toUpper()){
                QListWidgetItem *flight = new QListWidgetItem(item.first);
                ui->listWidget->addItem(flight);
                flight->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else if(!inputDeparture->text().isEmpty()){
        for(auto & item : flights){
            if(item.second->getDeparturePlace().toUpper() == inputDeparture->text().toUpper()){
                QListWidgetItem *flight = new QListWidgetItem(item.first);
                ui->listWidget->addItem(flight);
                flight->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else if(!inputArrival->text().isEmpty()){
        for(auto & item : flights){
            if(item.second->getArrivalPlace().toUpper() == inputArrival->text().toUpper()){
                QListWidgetItem *flight = new QListWidgetItem(item.first);
                ui->listWidget->addItem(flight);
                flight->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else{
        for(auto & item : flights){
            QListWidgetItem *flight = new QListWidgetItem(item.first);
            ui->listWidget->addItem(flight);
            flight->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void MainWindow::showTickets(){

    ShowTicketsModal *ticketWindow = new ShowTicketsModal(&flights, &tickets);
    ticketWindow->setMinimumSize(200, 200);
    ticketWindow->show();

}

void MainWindow::addFlight(){
    AddFlightModal *addWindow = new AddFlightModal([=](QString ID,
                                                   QString Status,
                                                   QString ArrivalPlace,
                                                   QString DeparturePlace,
                                                   int DepartureDateDay,
                                                   int DepartureDateMonth,
                                                   int DepartureDateYear,
                                                   int DepartureTimeHour,
                                                   int DepartureTimeMinute,
                                                   int ArrivalTimeHour,
                                                   int ArrivalTimeMinute,
                                                   int SeatsAvailabe) {

        try {
            if(flights.end() == flights.find(ID)){
                Flight *flightBtn = new Flight(ID,Status, ArrivalPlace, DeparturePlace, DepartureDateDay, DepartureDateMonth,
                                               DepartureDateYear, DepartureTimeHour, DepartureTimeMinute, ArrivalTimeHour,
                                               ArrivalTimeMinute, SeatsAvailabe);
                flights[ID] = flightBtn;
            }
            else{
                throw runtime_error("Flight with this ID already exists.");
            }
        } catch (std::exception &e) {
            qDebug() << e.what();
        }

    });
    addWindow->show();
}

void MainWindow::readFromFile()
{
    std::ifstream file("flights.bin", ios::binary);

    if(file.good()){
        while(file.peek() != EOF){
            Flight* rdFlight = new Flight;
            rdFlight->readFromBinary(file);
            flights[rdFlight->getID()] = rdFlight;
            qDebug() << "read";

        }
    }
    else{
        throw std::runtime_error("Open file error");
    }


    file.close();
}

void MainWindow::readFromFile(int rows){
    std::ifstream file("flights.bin", ios::binary);

    if(file.good()){
        while(file.peek() != EOF && rows > 0){
            Flight* rdFlight = new Flight;
            rdFlight->readFromBinary(file);
            flights[rdFlight->getID()] = rdFlight;
            qDebug() << "read";
            rows--;
        }
    }
    else{
        throw std::runtime_error("Open file error");
    }


    file.close();
}

void MainWindow::saveToFile()
{
    std::ofstream file("flights.bin", ios::binary);

    if(file.good()){
        for(auto & item : flights){
            item.second->saveToBinary(file);
            qDebug() << "save";
        }
    }
    else{
        throw std::runtime_error("Open file error");
    }

    file.close();


}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString ID = item->text();

    qDebug() << ID << ", " << flights[ID]->getStatus() << ", " << flights[ID]->getArrivalPlace() << ", " << flights[ID]->getDeparturePlace()
            << ", " << flights[ID]->getDepartureDateDay() << "." << flights[ID]->getDepartureDateMonth() << "." << flights[ID]->getDepartureDateYear()
            << ", " << flights[ID]->getDepartureTimeHour() << ":" << flights[ID]->getDepartureTimeMinute() << ", " << flights[ID]->getArrivalTimeHour()
            << ":" << flights[ID]->getArrivalTimeMinute() << ", " << flights[ID]->getSeatsAvailable();
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString ID = item->text();

    if(isAdminMode){
        EditRemoveModal *editRemoveWindow = new EditRemoveModal(flights[ID], &flights, [=](){ this->searchFlights(); });
        connect(editRemoveWindow, &WindowFlightModal::windowClosed, this, &MainWindow::feedback);
        editRemoveWindow->setMinimumSize(200, 200);
        editRemoveWindow->show();
    }
    else{
        BuyFlightModal *buyWindow = new BuyFlightModal(flights[ID], &tickets);
        connect(buyWindow, &WindowFlightModal::windowClosed, this, &MainWindow::feedback);
        buyWindow->setMinimumSize(200, 200);
        buyWindow->show();

    }
}

void MainWindow::loginSuccess(){
    Login->close();
    qDebug() << "zalogowano";
    show();
}

void MainWindow::feedback(bool isEdit){
    if(isEdit){
        auto info = (EditRemoveModal*) sender();
        info->writeInfo();
    }
    else{
        auto info = (BuyFlightModal*) sender();
        info->writeInfo();
    }
}
