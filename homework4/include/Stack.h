/**
Mehmet Onur Uysal
22002609
*/

#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack& aStack);
    bool isEmpty() const;
    bool push(string newItem);
    bool pop();
    bool pop(string& stackTop);
    bool getTop(string& stackTop) const;


private:
    struct StackNode {
        string item;
        StackNode *next;
    };

    StackNode *top;

};

#endif
