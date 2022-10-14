/**
Mehmet Onur Uysal
22002609
*/

#include "Chemical.h"
#include <iostream>
using namespace std;

Chemical::Chemical(int id, string type,string location){
    chemicalID = id;
    chemicalType = type;
    chemicalLocation = location;
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

Chemical::Chemical() {
    chemicalID = 0;
    chemicalType = "empty";
    chemicalLocation = "-";
}

Chemical::~Chemical(){}

int Chemical::getID() {
    return chemicalID;
}

int Chemical::getLocationRow() {
    char rowChar = chemicalLocation.at(0);
    for (int i = 0; i < 9; i++) {
        if (letters[i] == rowChar) {
            return i+1;
        }
    }
    return 0;
}

int Chemical::getLocationColumn(){
    char columnChar = chemicalLocation.at(1);
    return columnChar - '0';
}

string Chemical::getType() {
    return chemicalType;
}

 string Chemical::getLocation() {
    return chemicalLocation;
 }
