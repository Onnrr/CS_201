/**
Mehmet Onur Uysal
22002609
*/

#include "Cabinet.h"
#include <iostream>
#include<string>
#include<sstream>

using namespace std;

Cabinet::Cabinet(int id, int row, int column) {
    cabinetID = id;
    rows = row;
    columns = column;
    numberOfChemicals = 0;
    listOfChemicals = new Chemical*[row];

    for (int i = 0; i < row; i++) {
        listOfChemicals[i] = new Chemical[column];
    }

    letters[0] = 'A';
    letters[1] = 'B';
    letters[2] = 'C';
    letters[3] = 'D';
    letters[4] = 'E';
    letters[5] = 'F';
    letters[6] = 'G';
    letters[7] = 'H';
    letters[8] = 'I';
}

Cabinet::Cabinet() {
    cabinetID = -1;
    rows = 0;
    columns = 0;
    numberOfChemicals = 0;
    listOfChemicals = NULL;
}

Cabinet::~Cabinet() {
    if (listOfChemicals != NULL) {
        for (int i = 0; i < rows; i++) {
            delete[] listOfChemicals[i];
        }
        delete[] listOfChemicals;
    }
}

string Cabinet::placeChemical(int chemID,string type, string location) {
    char columnChar = location.at(1);
    int column = columnChar - '1';
    int row;
    char rowChar = location.at(0);
    for (int i = 0; i < 9; i++) {
        if (letters[i] == rowChar) {
            row = i;
        }
    }

    if (listOfChemicals[row][column].getType() != "empty") {
        return "OCCUPIED";
    }
    if (type == "combustive" && combustiveNear(location)) {
        return "COMBUSTIVE";
    }
    listOfChemicals[row][column] = Chemical(chemID,type,location);
    numberOfChemicals++;
    return "SUCCES";
}

void Cabinet::showContent() {
    cout << "ID: " << cabinetID << ", " << rows << "x" << columns << ", empty: " << getEmptySlots() << ". Chemicals: ";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (listOfChemicals[i][j].getType() != "empty") {
                cout << listOfChemicals[i][j].getLocation() << ": " << listOfChemicals[i][j].getID() << ", ";
            }
        }
    }
    cout << endl;
    cout << "  ";
    for (int i = 0; i < columns; i++) {
        cout << i+1 << " ";
    }
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (j == 0) {
                cout << letters[i] << " ";
            }
            if (listOfChemicals[i][j].getType() == "retardant") {
                cout << "r ";
            }
            else if (listOfChemicals[i][j].getType() == "combustive") {
                cout << "c ";
            }
            else {
                cout << "+ ";
            }
        }
        cout << endl;
    }
}

int Cabinet::getRows() {
    return rows;
}

int Cabinet::getColumns() {
    return columns;
}

int Cabinet::getID() {
    return cabinetID;
}

int Cabinet::getEmptySlots() {
    return rows*columns - numberOfChemicals;
}

Chemical* Cabinet::getChemical(int id) {
    if (numberOfChemicals == 0) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (listOfChemicals[i][j].getID() == id) {
                return &listOfChemicals[i][j];
            }
        }
    }
    return NULL;
}

Cabinet& Cabinet::operator=(const Cabinet &cabinet) {
    this->cabinetID = cabinet.cabinetID;
    this->rows = cabinet.rows;
    this->columns = cabinet.columns;
    this->numberOfChemicals = cabinet.numberOfChemicals;

    this->listOfChemicals = new Chemical*[cabinet.rows];

    for (int i = 0; i < cabinet.rows; i++) {
        this->listOfChemicals[i] = new Chemical[cabinet.columns];
    }

    for (int i = 0; i < cabinet.rows; i++) {
        for (int j = 0; j < cabinet.columns; j++) {
            this->listOfChemicals[i][j] = cabinet.listOfChemicals[i][j];
        }
    }
    return *this;
}

bool Cabinet::combustiveNear(string location) {
    char columnChar = location.at(1);
    int column = columnChar - '1';
    int row;
    char rowChar = location.at(0);
    for (int i = 0; i < 9; i++) {
        if (letters[i] == rowChar) {
            row = i;
        }
    }
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            if (i >= 0 && i < rows && j >= 0 && j < columns) {
                if (listOfChemicals[i][j].getType() == "combustive") {
                    return true;
                }
            }
        }
    }
    return false;
}

void Cabinet::printAvailableLocations(string location,string chemType) {
    char columnChar = location.at(1);
    int column = columnChar - '1';
    int row;
    char rowChar = location.at(0);
    for (int i = 0; i < 9; i++) {
        if (letters[i] == rowChar) {
            row = i;
        }
    }

    string availableLocations = "";
    int distance = 1;
    bool found = false;

    if (chemType == "retardant") {
        while (!found) {
            for (int i = row - distance; i <= row + distance; i++) {
                for (int j = column - distance; j <= column + distance; j++) {
                    if (i >= 0 && i < rows && j >= 0 && j < columns) {
                        if (listOfChemicals[i][j].getType() == "empty") {
                            stringstream locationLetter;
                            locationLetter << letters[i];
                            locationLetter << (j+1);
                            string newLocation;
                            locationLetter >> newLocation;
                            availableLocations.append(newLocation);
                            availableLocations.append(", ");
                            found = true;
                        }
                    }
                }
            }
            distance++;
        }
    }
    else if (chemType == "combustive") {
        while (!found) {
            for (int i = row - distance; i <= row + distance; i++) {
                for (int j = column - distance; j <= column + distance; j++) {
                    if (i >= 0 && i < rows && j >= 0 && j < columns) {
                        stringstream locationLetter;
                        locationLetter << letters[i];
                        locationLetter << (j+1);
                        string newLocation;
                        locationLetter >> newLocation;
                        if (listOfChemicals[i][j].getType() == "empty" && !combustiveNear(newLocation)) {
                            availableLocations.append(newLocation);
                            availableLocations.append(", ");
                            found = true;
                        }
                    }
                }
            }
            distance++;
        }
    }
    availableLocations = availableLocations.substr(0, availableLocations.length() - 2);
    cout << availableLocations;
}

bool Cabinet::chemIDExists(int id) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (listOfChemicals[i][j].getID() == id) {
                return true;
            }
        }
    }
    return false;
}

void Cabinet::removeChemical(int id) {
    if (chemIDExists(id)) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (listOfChemicals[i][j].getID() == id) {
                    listOfChemicals[i][j] = Chemical();
                    numberOfChemicals--;
                    return;
                }
            }
        }
    }
}


