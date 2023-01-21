#pragma once

#include <functional>

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QPushButton>
#include <vector>
#include <QDialog>

#include <Flight.h>

class WindowFlightModal : public QDialog
{
    Q_OBJECT
public:
    WindowFlightModal(Flight*);
    ~WindowFlightModal();

protected:
    QVBoxLayout *vbox;

    QListWidget *FlightsInformation;

    QListWidgetItem *itemID;
    QListWidgetItem *itemStatus;
    QListWidgetItem *itemArrivalPlace;
    QListWidgetItem *itemDeparturePlace;
    QListWidgetItem *itemDepartureTime;
    QListWidgetItem *itemArrivalTime;
    QListWidgetItem *itemSeatsAvailabe;

    bool isEdit = false;

    virtual void writeInfo() = 0;

signals:
    void windowClosed(bool isEdit);

};

