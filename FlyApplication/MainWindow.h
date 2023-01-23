/**

@file MainWindow.h
@brief This file contains the declaration of the MainWindow class.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <vector>
#include <fstream>
#include <Flight.h>
#include <AddFlightModal.h>
#include <EditFlightModal.h>
#include <EditRemoveModal.h>
#include <BuyFlightModal.h>
#include <WindowFlightModal.h>
#include <ShowTicketsModal.h>
#include <LoginWindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

/**
*@class MainWindow
*@brief The MainWindow class is the main window of the application. It provides functionality for searching and managing flights, as well as buying tickets, adding or search flight.
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /*
    *@brief Constructs a MainWindow object with a given mode and parent widget.
    *It controls all program logic.
    *@param isAdminMode A boolean that indicates whether the main window is in admin mode.
    *@param parent A pointer to the parent widget.
    */
    MainWindow(bool isAdminMode, QWidget *parent = nullptr);
    /**
    *@brief Destroys the MainWindow object.
    */
    ~MainWindow();

    bool isAdminMode;
    /**
    *@brief The function of searching and displaying flights according to the given criteria
    */
    void searchFlights();
    /**
    *@brief The function for adding new Flight object, and adds it to map of flights
    */
    void addFlight();
    /**
    *@brief The function for display  window with user's tickets
    */
    void showTickets();
    /**
    *@brief The function for read all Flights from binary file and save them to map of flights
    */
    void readFromFile();
    /**
    *@brief The function of reading the number of flights specified by the parameter from the binary file and saving them to the flight map
    *@param rows Specifies the number of lots to read from the binary file
    */
    void readFromFile(int rows);
    /**
    *@brief The function for write all Flights to binary file
    */
    void saveToFile();
    /**
    *@brief A function that prints to the console information about whether the window for editing or purchasing a ticket has been closed
    */
    void feedback(bool isEdit);

private slots:
    /**
    *@brief This slot is called when the item from List Widged is clicked, and print information about Flight to console
    *@param item The item from the List Widget that was clicked
    */
    void on_listWidget_itemClicked(QListWidgetItem *item);
    /**
    *@brief This slot is called when the item from List Widged is double-clicked, and create and show obcjet to edit/remove or buy Flight
    *@param item The item from the List Widget that was clicked
    */
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

public slots:
    /**
    *@brief This signal is emitted after a successful login
    */
    void loginSuccess();

private:
    Ui::AdminWindow *ui;
    std::map<QString, Flight*> flights;
    std::map<QString, int> tickets;

    LoginWindow *Login;


};
#endif // MAINWINDOW_H
