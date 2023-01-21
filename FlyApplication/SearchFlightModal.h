#pragma once

//#include <functional>

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

#include <Flight.h>

class SearchFlightModal : public QGroupBox{

    Q_OBJECT
public:
    SearchFlightModal();
    ~SearchFlightModal();

    Flight searchFlights();

private:

};
