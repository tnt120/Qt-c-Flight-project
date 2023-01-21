#pragma once

#include <functional>

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

#include <Flight.h>

class EditFlightModal : public QGroupBox
{
    Q_OBJECT
public:
    EditFlightModal(Flight*);
    ~EditFlightModal();

private:
    QVBoxLayout *vbox;

    QLineEdit *statusInput;
    QLabel* statusLabel;

    QLineEdit *arrivalPlaceInput;
    QLabel* arrivalPlaceLabel;

    QLineEdit *departurePlaceInput;
    QLabel* departurePlaceLabel;

    QLineEdit *departureTimeInput;
    QLabel* departureTimeLabel;

    QLineEdit *arrivalTimeInput;
    QLabel* arrivalTimeLabel;

    QLineEdit *seatsAvailableInput;
    QLabel* seatsAvailableLabel;
};
