#pragma once

#include <EditFlightModal.h>
#include <WindowFlightModal.h>

class EditRemoveModal : public WindowFlightModal
{
    Q_OBJECT
public:
    EditRemoveModal(Flight*, std::map<QString, Flight*>*, std::function<void()>);
    ~EditRemoveModal();

    void writeInfo() override;

private:

    QPushButton *EditButton;
    QPushButton *RemoveButton;

    std::map<QString, Flight*>* flights;
};
