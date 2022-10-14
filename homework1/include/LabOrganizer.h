/**
Mehmet Onur Uysal
22002609
*/

#ifndef __LABORGANIZER_H
#define __LABORGANIZER_H
#include <string>
#include "Cabinet.h"
using namespace std;

class LabOrganizer{
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
private:
    bool idExists(int id);
    Cabinet* getCabinet(int id);
    int numberOfCabinets;
    Cabinet** listOfCabinets;

};

#endif // LABORGANIZER_H
