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


QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(bool isAdminMode, QWidget *parent = nullptr);
    ~MainWindow();

    bool isAdminMode;

    void searchFlights();

    void addFlight();

    void showTickets();

    void readFromFile();

    void readFromFile(int rows);

    void saveToFile();

    void feedback(bool isEdit);

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::AdminWindow *ui;
    std::map<QString, Flight*> flights;
    std::map<QString, int> tickets;
};
#endif // MAINWINDOW_H
