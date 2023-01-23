/**

@file LoginWindow.h
@brief This file contains the declaration of the LoginWindow class.
*/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

/**

@class LoginWindow
@brief The LoginWindow class is a dialog box for logging in to the application.
*/

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    /**
    *@brief Constructs a LoginWindow object with a given mode [admin or user] and parent widget.
    *@param isAdminMode A boolean that indicates whether the login window is in admin or user mode.
    *@param parent A pointer to the parent widget.
    */
    explicit LoginWindow(bool isAdminMode, QWidget *parent = nullptr);
    /**
    *@brief Destroys the LoginWindow object.
    */
    ~LoginWindow();
    /**
    *@brief Indicates whether the login window is in admin or user mode.
    */
    bool isAdminMode;

private slots:
    /**
    *@brief This slot is called when the login button is clicked.
    */
    void on_buttonLogin_clicked();

private:
    Ui::LoginWindow *ui;

signals:
    /**
    *@brief This signal is emitted after a successful login
    */
    void login();
};

#endif // LOGINWINDOW_H
