/**
MEHMET ONUR UYSAL
22002609
*/

#ifndef FLOWERLIST_H
#define FLOWERLIST_H
#include <string>
#include "Flower.h"

using namespace std;

class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    void listFlowers() const;
    bool addFeature(string flowerName, string feature);
    bool removeFeature(string flowerName, string feature);
    string listFeatures(string flowerName) const;
    string findFlowers(string feature) const;
    bool flowerExists(string name) const;
private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head;
};

#endif
