/**
Mehmet Onur Uysal
22002609
*/

#ifndef CABINET_H
#define CABINET_H
#include <string>
#include "Chemical.h"
using namespace std;

class Cabinet
{
public:
    Cabinet(int id, int row, int column);
    Cabinet();
    ~Cabinet();
    int getID();
    int getRows();
    int getColumns();
    int getEmptySlots();
    string placeChemical(int chemID,string type, string location);
    void showContent();
    Chemical* getChemical(int id);
    Cabinet& operator=(const Cabinet &cabinet);
    bool chemIDExists(int id);
    void removeChemical(int id);
    Chemical* getSurroundings(string location);
    void printAvailableLocations(string location,string chemType);
    bool combustiveNear(string location);

private:
    int cabinetID;
    int rows;
    int columns;
    int numberOfChemicals;
    char letters[9];
    Chemical** listOfChemicals;
};

#endif
