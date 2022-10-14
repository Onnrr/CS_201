/**
Mehmet Onur Uysal
22002609
*/

#ifndef CHEMICAL_H
#define CHEMICAL_H
#include <string>
using namespace std;

class Chemical {
public:
    Chemical(int id, string type,string location);
    Chemical();
    ~Chemical();
    int getID();
    string getType();
    string getLocation();
    int getLocationRow();
    int getLocationColumn();

private:
    string chemicalType;
    int chemicalID;
    string chemicalLocation;
    char letters[9];
};

#endif
