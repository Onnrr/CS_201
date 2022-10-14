/**
MEHMET ONUR UYSAL
22002609
*/

#ifndef FLOWERLIBRARY_H
#define FLOWERLIBRARY_H
#include <string>
#include "FlowerList.h"

using namespace std;

class FlowerLibrary{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
private:
    FlowerList flowers;
};


#endif
