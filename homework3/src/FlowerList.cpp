/**
MEHMET ONUR UYSAL
22002609
*/

#include "FlowerList.h"
#include <iostream>
using namespace std;

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}

FlowerList::FlowerList(const FlowerList& aList) {
    if (aList.isEmpty()) {
        size = 0;
        head = NULL;
    }
    else {
        size = aList.size;
        head = new FlowerNode;
        head->f = aList.head->f;

        FlowerNode *newPtr = head;

        for (FlowerNode *ptr = aList.head->next; ptr != NULL; ptr = ptr->next) {
            newPtr->next = new FlowerNode;
            newPtr = newPtr->next;
            newPtr->f = ptr->f;
        }
        newPtr->next = NULL;
    }
}

FlowerList::~FlowerList() {
    FlowerNode *temp = NULL;
    for (FlowerNode *ptr = head; ptr != NULL; ptr = temp) {
        temp = ptr->next;
        delete ptr;
    }
}

bool FlowerList::isEmpty() const {
    return size == 0;
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::add(string flowerName) {
    // First item of list
    if (isEmpty()) {
        head = new FlowerNode;
        head->f = Flower(flowerName);
        head->next = NULL;
        size++;
        return true;
    }

    // Name check
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if ((ptr->f).getName() == flowerName) {
            return false;
        }
    }

    // Checking order and adding

    FlowerNode *prev = NULL;

    FlowerNode *newNode = new FlowerNode;
    newNode->f = Flower(flowerName);
    newNode->next = NULL;

    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (flowerName.compare((ptr->f).getName()) < 0) {
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

    // If the new node is the last item
    prev->next = newNode;
    newNode->next = NULL;
    size++;
    return true;
}

bool FlowerList::remove(string flowerName) {
    FlowerNode *prev = NULL;

    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if ((ptr->f).getName() == flowerName) {
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

void FlowerList::listFlowers() const {
    if (head == NULL) {
        cout << "Library is empty" << endl;
        return;
    }
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        cout << (ptr->f).printFlower() << endl;
    }
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (flowerName == (ptr->f).getName()) {
            flower = ptr->f;
            return true;
        }
    }
    return false;
}

bool FlowerList::addFeature(string flowerName, string feature) {
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (flowerName == (ptr->f).getName()) {
            if ((ptr->f).add(feature)) {
                return true;
            }
        }
    }
    return false;
}

bool FlowerList::removeFeature(string flowerName, string feature) {
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (flowerName == (ptr->f).getName()) {
            if ((ptr->f).remove(feature)) {
                return true;
            }
        }
    }
    return false;
}

string FlowerList::listFeatures(string flowerName) const {
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if (flowerName == (ptr->f).getName()) {
            return (ptr->f).printFlower();
        }
    }
}

string FlowerList::findFlowers(string feature) const {
    string flowers = feature + " flowers: ";

    bool found = false;
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if ((ptr->f).hasFeature(feature)) {
            flowers += (ptr->f).getName() + ", ";
            found = true;
        }
    }

    if (!found) {
        flowers += "there is no such flower";
    }
    else {
        flowers = flowers.substr(0,flowers.length()-2);
    }

    return flowers;
}

bool FlowerList::flowerExists(string name) const {
    for (FlowerNode *ptr = head; ptr != NULL; ptr = ptr->next) {
        if ((ptr->f).getName() == name) {
            return true;
        }
    }
    return false;
}

