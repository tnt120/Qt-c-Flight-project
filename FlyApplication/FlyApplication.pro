QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DEFINES += "APP_NAME=Admin"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddFlighModal.cpp \
    BuyFlightModal.cpp \
    EditFlightModal.cpp \
    EditRemoveModal.cpp \
    Flight.cpp \
    LoginWindow.cpp \
    ShowTicketsModal.cpp \
    WindowFlightModal.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AddFlightModal.h \
    BuyFlightModal.h \
    EditFlightModal.h \
    EditRemoveModal.h \
    Flight.h \
    LoginWindow.h \
    MainWindow.h \
    ShowTicketsModal.h \
    WindowFlightModal.h

FORMS += \
    LoginWindow.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
