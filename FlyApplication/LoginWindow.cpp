#include "LoginWindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow(bool isAdminMode, QWidget *parent) :
    QDialog(parent)
    , isAdminMode(isAdminMode)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->inputPassword->setEchoMode(QLineEdit::Password);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_buttonLogin_clicked()
{

    std::ifstream file("logowanie.txt");
    std::string valueLogin;
    std::string valuePassword;
    std::string valueIsAdmin;

    try {
        if(file.good()){
            while(!file.eof()){
                file >> valueLogin;
                file >> valuePassword;
                file >> valueIsAdmin;

                if(ui->inputLogin->text() == QString::fromStdString(valueLogin) && ui->inputPassword->text() == QString::fromStdString(valuePassword)){
                    if(isAdminMode && valueIsAdmin == "admin"){
                        emit login();
                    }
                    else if(!isAdminMode){
                        emit login();
                    }
                }
            }
        }
        else{
            throw std::runtime_error("Open file error");
        }
    } catch (std::exception &e) {
        qDebug() << e.what();
        exit(-1);
    }





    file.close();
}
