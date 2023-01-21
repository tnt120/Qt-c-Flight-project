#pragma once

#include <WindowFlightModal.h>>


class BuyFlightModal : public WindowFlightModal
{
    Q_OBJECT
public:
    BuyFlightModal(Flight* flight, std::map<QString, int>*);
    ~BuyFlightModal();

    void writeInfo() override;

    template<typename T>
    void updateTickets(QString ID, std::map<QString, T>* tickets){
        for(auto & item : *tickets){
            if(item.first == ID){
                item.second++;
            }
            else{
                this->tickets->operator[](ID) = 1;
            }
        }
    }

private:

    QPushButton *BuyButton;

    std::map<QString, int>* tickets;
};
