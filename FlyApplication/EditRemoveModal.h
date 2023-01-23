/**
@file EditRemoveModal.h
@brief This file contains the declaration of the EditRemoveModal class.
*/

#pragma once

#include <EditFlightModal.h>
#include <WindowFlightModal.h>

/**
*@class EditRemoveModal
*@brief The EditRemoveModal class is a dialog box for editing or removing a flight.
*/

class EditRemoveModal : public WindowFlightModal
{
    Q_OBJECT
public:
    /*
    *@brief Constructs an EditRemoveModal object with a given flight, a pointer to a map of flights, and a callback function.
    * Creates a window with information about flight and two buttons "Edit" or "Remove" to edit or remove given flight.
    * Contains onClick methods, after click "Edit" button, create new EditFlightModal object, to edit given flight.
    * After click "Remove" button removes given flight from flights map.
    *@param flight A pointer to the flight to be edited or removed.
    *@param flights A pointer to the map of flights.
    *@param callback A function that is called when the flight is removed and updates List Widget to present current flight map.
    */
    EditRemoveModal(Flight*, std::map<QString, Flight*>*, std::function<void()>);
    /**
    *@brief Destroys the EditRemoveModal object.
    */
    ~EditRemoveModal();
    /**
    *@brief Writes the information about close window to console.
    */
    void writeInfo() override;

private:
    /**
    *@brief The "Edit" button.
    */
    QPushButton *EditButton;
    /**
    *@brief The "Remove" button.
    */
    QPushButton *RemoveButton;
    /**
    *@brief A pointer to the map of flights.
    */
    std::map<QString, Flight*>* flights;
};
