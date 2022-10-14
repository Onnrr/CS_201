/**
Mehmet Onur Uysal
22002609
*/

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    top = NULL;
}

Stack::Stack(const Stack& aStack){
    if (aStack.top == NULL)
        top = NULL;

    else {
        top = new StackNode;
        top->item = aStack.top->item;

        StackNode *newPtr = top;
        for (StackNode *origPtr = aStack.top->next; origPtr != NULL; origPtr = origPtr->next){
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}


Stack::~Stack(){
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const{
    return top == NULL;
}

bool Stack::push(string newItem) {
    StackNode *newNode = new StackNode;
    newNode->item = newItem;
    newNode->next = top;
    top = newNode;

    return true;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }

    StackNode *temp = top;
    top = top->next;
    temp->next = NULL;
    delete temp;
    return true;
}

bool Stack::pop(string& stackTop) {
    if (isEmpty()) {
        return false;
    }
    StackNode *temp = top;
    top = top->next;
    temp->next = NULL;
    stackTop = temp->item;
    delete temp;
    return true;
}

bool Stack::getTop(string& stackTop) const {
    if (isEmpty()) {
        return false;
    }
    stackTop = top->item;
    return true;
}























