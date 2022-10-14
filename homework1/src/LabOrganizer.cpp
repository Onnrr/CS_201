/**
Mehmet Onur Uysal
22002609
*/

#include "LabOrganizer.h"
#include <iostream>
#include<cmath>
using namespace std;

LabOrganizer::LabOrganizer() {
    numberOfCabinets = 0;
    listOfCabinets = NULL;
}

LabOrganizer::~LabOrganizer() {
    if (listOfCabinets != NULL) {
        for (int i = 0; i < numberOfCabinets; i++) {
            delete listOfCabinets[i];
        }
        delete[] listOfCabinets;
    }
}

void LabOrganizer::addCabinet(int id,int row,int column) {
    if (idExists(id)) {
        cout << "Cannot add the cabinet: ID " << id << " already in the system" << endl;
        return;
    }
    if (row > 9 || column > 9) {
        cout << "Cannot add the cabinet: dimensions are out of bounds" << endl;
        return;
    }
    else if (numberOfCabinets == 0) {
        numberOfCabinets++;
        listOfCabinets = new Cabinet*[numberOfCabinets];
        listOfCabinets[numberOfCabinets-1] = new Cabinet(id,row,column);
    }
    else {
        numberOfCabinets++;
        Cabinet** tempList = new Cabinet*[numberOfCabinets];
        for (int i = 0; i < numberOfCabinets-1; i++) {
            tempList[i] = listOfCabinets[i];
        }
        tempList[numberOfCabinets-1] = new Cabinet(id,row,column);
        delete[] listOfCabinets;
        listOfCabinets = tempList;
    }
    cout << "Added a cabinet: ID " << id << " and dimensions " << row << " to " << column << endl;
}

void LabOrganizer::removeCabinet(int id) {
    if (!idExists(id)) {
        cout << "Cabinet " << id << " does not exist in the system" << endl;
        return;
    }
    if (numberOfCabinets == 1) {
        numberOfCabinets--;
        delete listOfCabinets[numberOfCabinets];
        delete[] listOfCabinets;
        listOfCabinets = NULL;
    }
    else {
        for (int i = 0; i < numberOfCabinets; i++) {
            if (listOfCabinets[i]->getID() == id) {
                delete listOfCabinets[i];
                listOfCabinets[i] = listOfCabinets[numberOfCabinets-1];
            }
        }
        numberOfCabinets--;
        Cabinet** tempList = new Cabinet*[numberOfCabinets];
        for (int i = 0; i < numberOfCabinets; i++) {
            tempList[i] = listOfCabinets[i];
        }
        delete[] listOfCabinets;
        listOfCabinets = tempList;
    }
    cout << "Cabinet " << id << " has been removed" << endl;
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    string result;
    int cabinetIndex;
    bool chemicalExists = false;
    if (!idExists(cabinetId)) {
        cout << "Cabinet " <<  cabinetId << " does not exist in the system" << endl;
        return;
    }

    for (int i = 0; i < numberOfCabinets; i++) {
        if (listOfCabinets[i]->chemIDExists(chemID)) {
            cout << "Chemical with ID " << chemID << " already exists in the system" << endl;
            return;
        }
    }
    for (int i = 0; i < numberOfCabinets; i++) {
        if (listOfCabinets[i]->getID() == cabinetId) {
            result = listOfCabinets[i]->placeChemical(chemID,chemType,location);
            cabinetIndex = i;
        }
    }
    if (result == "OCCUPIED") {
        cout << "Location " << location << " in cabinet " << cabinetId << " is already occupied. Nearest possible locations for this chemical: ";
        listOfCabinets[cabinetIndex]->printAvailableLocations(location,chemType);
        cout << endl;
        return;
    }
    if (result == "COMBUSTIVE") {
        cout << "Location " << location << " in cabinet " << cabinetId << " is not suitable for a combustive chemical. Nearest possible locations for this chemical: ";
        listOfCabinets[cabinetIndex]->printAvailableLocations(location,chemType);
        cout << endl;
        return;
    }
    if (result == "SUCCES") {
        cout << chemType << " chemical with ID " << chemID << " has been placed at location " << location << " at cabinet " << cabinetId << endl;
        return;
    }
}

void LabOrganizer::findChemical(int id) {
    if (numberOfCabinets == 0) {
        cout << "Chemical " << id << " is not in the system" << endl;
        return;
    }
    for (int i = 0; i < numberOfCabinets; i++) {
        if (listOfCabinets[i]->chemIDExists(id)) {
            Chemical chem = *(listOfCabinets[i]->getChemical(id));
            cout << "Chemical " << id << " is at location " << chem.getLocation() << " in cabinet " << listOfCabinets[i]->getID() << endl;
            return;
        }
    }
    cout << "Chemical " << id << " is not in the system" << endl;
}

void LabOrganizer::removeChemical(int id) {
    if (numberOfCabinets == 0) {
        cout << "Chemical " << id << " is not in the system" << endl;
        return;
    }
    for (int i = 0; i < numberOfCabinets; i++) {
        if (listOfCabinets[i]->chemIDExists(id)) {
            listOfCabinets[i]->removeChemical(id);
            cout << "Chemical " << id << " removed from cabinet " << listOfCabinets[i]->getID() << endl;
        }
    }
    cout << "Chemical " << id << " is not in the system" << endl;
}

void LabOrganizer::listCabinets() {
    if (numberOfCabinets == 0) {
        cout << "There are no cabinets in the system" << endl;
        return;
    }
    cout << "List of all cabinets" << endl;
    for (int i = 0; i < numberOfCabinets; i++) {
        cout << "ID: " << listOfCabinets[i]->getID() << ", Dim: " << listOfCabinets[i]->getRows() << "x" << listOfCabinets[i]->getColumns() <<  ", number of empty slots: " << listOfCabinets[i]->getEmptySlots() << endl;
    }
}

void LabOrganizer::cabinetContents(int id) {
    if (!idExists(id)) {
        cout << "Cabinet " << id << " does not exist in the system";
        return;
    }
    for (int i = 0; i < numberOfCabinets; i++) {
        if (listOfCabinets[i]->getID() == id) {
            listOfCabinets[i]->showContent();
        }
    }
}

bool LabOrganizer::idExists(int id) {
    if (numberOfCabinets == 0) {
        return false;
    }
    for (int i = 0; i < numberOfCabinets; i++) {
        if (listOfCabinets[i]->getID() == id) {
            return true;
        }
    }
    return false;
}
