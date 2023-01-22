#pragma once

#include <WindowFlightModal.h>


class BuyFlightModal : public WindowFlightModal
{
    Q_OBJECT
public:
    BuyFlightModal(Flight* flight, std::map<QString, int>*);
    ~BuyFlightModal();

    void writeInfo() override;

    template<typename T>
    void updateTickets(QString ID, std::map<QString, T>* tickets){

        if(tickets->size() == 0){
            tickets->operator[](ID) = 1;
        }
        else{
            if(tickets->find(ID) == tickets->end()){
                tickets->operator[](ID) = 1;
            }
            else{
                tickets->operator[](ID)++;
            }
        }
    }

private:

    QPushButton *BuyButton;
};
