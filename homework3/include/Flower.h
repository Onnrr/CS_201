/**
MEHMET ONUR UYSAL
22002609
*/

#ifndef FLOWER_H
#define FLOWER_H
#include <string>
using namespace std;

class Flower{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const ;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    string getName();
    bool hasFeature(string feature) const;
private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode *head;
};
#endif
