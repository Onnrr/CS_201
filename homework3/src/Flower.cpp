/**
MEHMET ONUR UYSAL
22002609
*/

#include "Flower.h"
#include <iostream>
using namespace std;

Flower::Flower() {
    flowerName = "";
    size = 0;
    head = NULL;
}

Flower::Flower(string flowerName) {
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}

Flower::~Flower() {
    FeatureNode *temp = NULL;
    for (FeatureNode *ptr = head; ptr != NULL; ptr = temp) {
        temp = ptr->next;
        delete ptr;
    }
}

bool Flower::isEmpty() const {
    return size == 0;
}

int Flower::getLength() const {
    return size;
}

string Flower::getName() {
    return flowerName;
}

bool Flower::add(string feature) {
    // First item
    if (head == NULL) {
        head = new FeatureNode;
        head->feature = feature;
        head->next = NULL;
        size++;
        return true;
    }

    // Name check
    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if ((ptr->feature) == feature) {
            return false;
        }
    }

    FeatureNode *prev = NULL;

    FeatureNode *newNode = new FeatureNode;
    newNode->feature = feature;
    newNode->next = NULL;

    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (feature.compare((ptr->feature)) < 0) {
            if (prev == NULL) {
                newNode->next = head;
                head = newNode;
                size++;
                return true;
            }
            else {
                prev->next = newNode;
                newNode->next = ptr;
                size++;
                return true;
            }
        }
        prev = ptr;
    }

    // Last item
    prev->next = newNode;
    newNode->next = NULL;
    size++;
    return true;
}

bool Flower::remove(string feature) {
    FeatureNode *prev = NULL;

    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (ptr->feature == feature) {
            if (prev == NULL) {
                head = ptr->next;
                delete ptr;
                size--;
                return true;
            }
            else {
                prev->next = ptr->next;
                delete ptr;
                size--;
                return true;
            }
        }
        prev = ptr;
    }

    return false;
}

string Flower::printFlower() const {
    string info = "";
    info += flowerName + ": ";

    if (head == NULL) {
        info += "No feature";
        return info;
    }
    else{
        for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next) {
            info += ptr->feature;
            info += ", ";
        }
        return info.substr(0,info.length()-2);
    }

}

bool Flower::hasFeature(string feature) const {
    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (ptr->feature == feature) {
            return true;
        }
    }
    return false;
}
