#pragma once

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include <QDialog>

class ShowTicketsModal : public QDialog
{
    Q_OBJECT
public:
    ShowTicketsModal(std::map<QString, int>*);
    ~ShowTicketsModal();

private:
    QVBoxLayout *vbox;

    QListWidget *TicketListWidget;

    std::map<QString, int>* tickets;
};


