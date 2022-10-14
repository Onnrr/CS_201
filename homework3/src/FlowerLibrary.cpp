/**
MEHMET ONUR UYSAL
22002609
*/

#include "FlowerLibrary.h"
#include <iostream>
using namespace std;

FlowerLibrary::FlowerLibrary() {
    flowers = FlowerList();
}

FlowerLibrary::~FlowerLibrary() {}

void FlowerLibrary::addFlower(string name) {
    for (int i = 0; '\0' != name[i]; ++i) {
        if (name[i] < 91 && name[i] > 64 )
            name[i] = name[i] + 32;
    }

    if (flowers.add(name)) {
        cout << name << " has been added into the library" << endl;
    }
    else {
        cout << name << " cannot be added into the library because it already exists." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    for (int i = 0; '\0' != name[i]; ++i) {
        if (name[i] < 91 && name[i] > 64 )
            name[i] = name[i] + 32;
    }

    if (flowers.remove(name)) {
        cout << name << " has been removed from the library" << endl;
    }
    else {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    flowers.listFlowers();
}

void FlowerLibrary::addFeature(string name, string feature) {
    for (int i = 0; '\0' != name[i]; ++i) {
        if (name[i] < 91 && name[i] > 64 )
            name[i] = name[i] + 32;
    }

    for (int i = 0; '\0' != feature[i]; ++i) {
        if (feature[i] < 91 && feature[i] > 64 )
            feature[i] = feature[i] + 32;
    }

    if (!flowers.flowerExists(name)) {
        cout << name << " isn't found in library" << endl;
        return;
    }

    if (flowers.addFeature(name,feature)) {
        cout << feature << " is added into " << name << endl;
        return;
    }
    cout << feature << " already exists in " << name << endl;
}

void FlowerLibrary::removeFeature(string name, string feature) {
    for (int i = 0; '\0' != name[i]; ++i) {
        if (name[i] < 91 && name[i] > 64 )
            name[i] = name[i] + 32;
    }

    for (int i = 0; '\0' != feature[i]; ++i) {
        if (feature[i] < 91 && feature[i] > 64 )
            feature[i] = feature[i] + 32;
    }

    if (!flowers.flowerExists(name)) {
        cout << name << " isn't found in library" << endl;
        return;
    }

    if (flowers.removeFeature(name, feature)) {
        cout << feature << " is removed from " << name << endl;
        return;
    }
    cout << feature << " doesn't exist in " << name << endl;
}

void FlowerLibrary::listFeatures(string name) const {
    for (int i = 0; '\0' != name[i]; ++i) {
        if (name[i] < 91 && name[i] > 64 )
            name[i] = name[i] + 32;
    }

    if (flowers.flowerExists(name)) {
        cout << flowers.listFeatures(name) << endl;
        return;
    }
    cout << name << " isn't found in the library" << endl;
}

void FlowerLibrary::findFlowers(string feature) const {
    for (int i = 0; '\0' != feature[i]; ++i) {
        if (feature[i] < 91 && feature[i] > 64 )
            feature[i] = feature[i] + 32;
    }

    cout << flowers.findFlowers(feature) << endl;
}
