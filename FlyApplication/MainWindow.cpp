#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(bool isAdminMode, QWidget *parent)
    : QMainWindow(parent)
    , isAdminMode(isAdminMode)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    try {
        readFromFile();
    } catch (std::exception &e) {
        qDebug() << e.what();
    }

    //connect(ui->listWidget, SIGNAL(itemClicked()), this, SLOT(on_listWidget_itemClicked()));

    //connect(ui->listWidget, SIGNAL(itemDoubleClicked()), this, SLOT(on_listWidget_itemDoubleClicked()));
    ////////////////////////////////////////////// TEST START //////////////////////////////////////////
/*
    Flight *fl1 = new Flight("LH8082", "Boarding", "Krakow", "Warszawa", 17, 18, 2);


    Flight *fl2 = new Flight("FR9021", "Delayed", "Krakow", "Barcelona", 8, 11, 25);


    Flight *fl3 = new Flight("LH9092", "Boarding", "Barcelona", "Krakow", 20, 23, 92);




    flights[QString("LH8082")] = fl1;
    flights[QString("FR9021")] = fl2;
    flights[QString("LH9092")] = fl3;
*/
    ////////////////////////////////////////////// TEST KONIEC //////////////////////////////////////////

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

    flights.clear();

    // upewnic sie czy na pewno dobrze to zrobie
}

void MainWindow::searchFlights()
{
    QLineEdit *inputDeparture = ui->inputDepature;
    QLineEdit *inputArrival = ui->inputArrival;
    QCheckBox *checkBoxArrival = ui->checkBoxArrival;
    QCheckBox *checBoxDeparture = ui->checkBoxDeparture;

    ui->listWidget->clear();

    if(checkBoxArrival->isChecked() && checBoxDeparture->isChecked()){
        for(auto & item : flights){
            if(item.second->getDeparturePlace() == inputDeparture->text() && item.second->getArrivalPlace() == inputArrival->text()){
                QListWidgetItem *flight = new QListWidgetItem(item.first);
                ui->listWidget->addItem(flight);
                flight->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else if(checBoxDeparture->isChecked()){
        for(auto & item : flights){
            if(item.second->getDeparturePlace() == inputDeparture->text()){
                QListWidgetItem *flight = new QListWidgetItem(item.first);
                ui->listWidget->addItem(flight);
                flight->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else if(checkBoxArrival->isChecked()){
        for(auto & item : flights){
            if(item.second->getArrivalPlace() == inputArrival->text()){
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

    ShowTicketsModal *ticketWindow = new ShowTicketsModal(&tickets);
    ticketWindow->setMinimumSize(200, 200);
    ticketWindow->show();

}

void MainWindow::addFlight(){
    AddFlightModal *addWindow = new AddFlightModal([=](QString ID,
                                                   QString Status,
                                                   QString ArrivalPlace,
                                                   QString DeparturePlace,
                                                   int DepartureTime,
                                                   int ArrivalTime,
                                                   int SeatsAvailable) {

        Flight *flightBtn = new Flight(ID, Status, ArrivalPlace, DeparturePlace, DepartureTime, ArrivalTime, SeatsAvailable);

        flights[ID] = flightBtn;

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

    qDebug() << flights[ID]->getID() << ", " << flights[ID]->getStatus() << ", " << flights[ID]->getDeparturePlace() << ", " << flights[ID]->getDepartureTime()
             << ", " << flights[ID]->getArrivalPlace() << ", " << flights[ID]->getArrivalTime() << ", " << flights[ID]->getSeatsAvailable();
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
