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
#include <QDialog>

class AddFlightModal : public QDialog
{
    Q_OBJECT
public:
    AddFlightModal(std::function<void (QString, QString, QString, QString, int, int, int)>);
    ~AddFlightModal();

private:
    QVBoxLayout *vbox;

    QLineEdit *idInput;
    QLabel* idLabel;

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
