#include <EditRemoveModal.h>

EditRemoveModal::EditRemoveModal(Flight* flight, std::map<QString, Flight*>* flights, std::function<void()> searchFunction)
    : WindowFlightModal(flight){

    isEdit = true;

    this->EditButton = new QPushButton("Edit");

    this->RemoveButton = new QPushButton("Remove");

    this->flights = flights;

    connect(EditButton, &QPushButton::clicked, [=](){
        EditFlightModal *editWindow = new EditFlightModal(flight);
        editWindow->show();
        this->close();
        this->deleteLater();
    });


    connect(RemoveButton, &QPushButton::clicked, [=](){

        QString ID = flight->getID();

        this->flights->erase(ID);

        delete flight;

        searchFunction();

        this->close();
        this->deleteLater();

    });

    vbox->addWidget(EditButton);
    vbox->addWidget(RemoveButton);


}

EditRemoveModal::~EditRemoveModal(){

    delete this->EditButton;

    delete this->RemoveButton;

}

void EditRemoveModal::writeInfo(){

    qDebug() << "Finished edit";
}
