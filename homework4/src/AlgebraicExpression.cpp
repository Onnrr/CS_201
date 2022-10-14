/**
Mehmet Onur Uysal
22002609
*/

/**
Mehmet Onur Uysal
22002609
*/

#include <iostream>
#include "AlgebraicExpression.h"
#include "Stack.h"
#include <vector>
#include<sstream>

using namespace std;

double evaluatePrefix( const string exp){
    Stack aStack;
    double result;
    Stack tokens = getTokens(exp);;

    while(!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (isdigit(item.at(0))) {
            aStack.push(item);
        }
        else {
            double firstD;
            double secondD;
            string firstOp;
            string secondOp;
            aStack.pop(firstOp);
            aStack.pop(secondOp);
            stringstream firstStream;
            stringstream secondStream;
            firstStream << firstOp;
            secondStream << secondOp;
            firstStream >> firstD;
            secondStream >> secondD;
            if (item == "+") {
                result = firstD + secondD;
            }
            else if (item == "-") {
                result = firstD - secondD;
            }
            else if (item == "*") {
                result = firstD * secondD;
            }
            else if ( item == "/") {
                result = firstD / secondD;
            }
            stringstream resultStream;
            resultStream << result;
            string resultString;
            resultStream >> resultString;
            aStack.push(resultString);
        }
    }
    double finalR;
    string finalRe;
    aStack.getTop(finalRe);

    stringstream finalStream;
    finalStream << finalRe;
    finalStream >> finalR;

    return finalR;
}

double evaluatePostfix( const string exp){
    Stack aStack;
    double result;
    Stack tkns = getTokens(exp);
    Stack tokens;

    while (!tkns.isEmpty()) {
        string item;
        tkns.pop(item);
        tokens.push(item);
    }

    while(!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (isdigit(item.at(0))) {
            aStack.push(item);
        }
        else {
            double firstD;
            double secondD;
            string firstOp;
            string secondOp;
            aStack.pop(secondOp);
            aStack.pop(firstOp);
            stringstream firstStream;
            stringstream secondStream;
            firstStream << firstOp;
            secondStream << secondOp;
            firstStream >> firstD;
            secondStream >> secondD;
            if (item == "+") {
                result = firstD + secondD;
            }
            else if (item == "-") {
                result = firstD - secondD;
            }
            else if (item == "*") {
                result = firstD * secondD;
            }
            else if (item == "/") {
                result = firstD / secondD;
            }
            stringstream resultStream;
            resultStream << result;
            string resultString;
            resultStream >> resultString;
            aStack.push(resultString);
        }
    }
    return result;
}

double evaluateInfix( const string exp ) {
    string postFix = infix2postfix(exp);
    return evaluatePostfix(postFix);
}

string prefix2postfix( const string exp ) {
    Stack aStack;
    Stack tokens = getTokens(exp);

    while(!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (item == "*" || item == "/" || item == "+" || item == "-") {
            string operand1;
            string operand2;
            aStack.pop(operand1);
            aStack.pop(operand2);
            string temp = operand1 + " " + operand2 + " " + item;

            aStack.push(temp);
        }
        else {
            aStack.push(item);
        }
    }
    string result;
    aStack.getTop(result);
    return result;
}

string postfix2prefix( const string exp ) {
    Stack aStack;
    Stack tkns = getTokens(exp);
    Stack tokens;

    while (!tkns.isEmpty()) {
        string item;
        tkns.pop(item);
        tokens.push(item);
    }

    while (!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (item == "*" || item == "/" || item == "+" || item == "-") {
            string operand1;
            string operand2;
            aStack.pop(operand1);
            aStack.pop(operand2);
            string temp = item + " " + operand2 + " " + operand1;

            aStack.push(temp);
        }
        else {
            aStack.push(item);
        }
    }
    string result = "";
    while (!aStack.isEmpty()) {
        string temp;
        aStack.pop(temp);
        result += temp;
    }

    return result;
}

string infix2prefix( const string exp ) {
    string newStr = "( " + exp + " )";
    string result = "";
    Stack aStack;
    Stack tokens = getTokens(newStr);

    while (!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (isdigit(item.at(0))) {
            result += " " + item;
        }
        else if (item == ")") {
            aStack.push(item);
        }
        else if (item == "(") {
            string top;
            aStack.getTop(top);
            while(top != ")") {
                result += " " + top;
                aStack.pop();
                if (aStack.isEmpty()) { break; }
                aStack.getTop(top);
            }
            aStack.pop();
        }

        else if (item == "*" || item == "/" || item == "+" || item == "-") {
            string top;
            aStack.getTop(top);
            if (top == "*" || top == "/" || top == "+" || top == "-") {
                int priority = getPriority(item);

                while (priority < getPriority(top)) {
                    result += " " + top;
                    aStack.pop();
                    aStack.getTop(top);
                }
            }
            aStack.push(item);
        }
    }

    while(!aStack.isEmpty()) {
        string top;
        aStack.getTop(top);
        aStack.pop();
        result += top;
    }
    Stack resultR = getTokens(result);
    string finalR = "";
    while (!resultR.isEmpty()) {
        string item;
        resultR.pop(item);
        if (!resultR.isEmpty()) {
            finalR += item + " ";
        }
        else {
            finalR += item;
        }
    }

    return finalR.erase(finalR.size()-1,finalR.size());

}

string infix2postfix( const string exp ) {
    string result = "";
    string newString = "( " + exp + " )";
    Stack aStack;
    Stack tkns = getTokens(newString);
    Stack tokens;

    while (!tkns.isEmpty()) {
        string item;
        tkns.pop(item);
        tokens.push(item);
    }

    while (!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (isdigit(item.at(0))) {
            if (result == "") {
                result += item;
            }
            else {
                result += " " + item;
            }
        }
        else if (item == "(") {
            aStack.push(item);
        }
        else if (item == ")") {
            string top;
            aStack.getTop(top);
            while(top != "(") {
                result += " " + top;
                aStack.pop();
                if (aStack.isEmpty()) { break; }
                aStack.getTop(top);
            }
            aStack.pop();
        }

        else if (item == "*" || item == "/" || item == "+" || item == "-") {
            string top;
            aStack.getTop(top);
            if (top == "*" || top == "/" || top == "+" || top == "-") {
                int priority = getPriority(item);

                while (priority <= getPriority(top)) {
                    result += " " + top;
                    aStack.pop();
                    aStack.getTop(top);
                }
            }
            aStack.push(item);
        }
    }

    while(!aStack.isEmpty()) {
        string top;
        aStack.getTop(top);
        aStack.pop();
        result += top;
    }

    return result;
}

string prefix2infix( const string exp ) {
    Stack aStack;
    Stack tokens = getTokens(exp);

    while (!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (item == "*" || item == "/" || item == "+" || item == "-") {
            string operand1;
            string operand2;
            aStack.pop(operand1);
            aStack.pop(operand2);
            string temp = "( " + operand1 + " " + item + " " + operand2 + " )";
            aStack.push(temp);
        }
        else {
            aStack.push(item);
        }
    }
    string result;
    aStack.getTop(result);
    return result;
}

string postfix2infix( const string exp ) {
    Stack aStack;
    Stack tkns = getTokens(exp);
    Stack tokens;

    while (!tkns.isEmpty()) {
        string item;
        tkns.pop(item);
        tokens.push(item);
    }

    while (!tokens.isEmpty()) {
        string item;
        tokens.pop(item);
        if (item == "*" || item == "/" || item == "+" || item == "-") {
            string operand1;
            string operand2;
            aStack.pop(operand1);
            aStack.pop(operand2);
            string temp = "( " + operand2 + " " + item + " " + operand1 + " )";
            aStack.push(temp);
        }
        else {
            aStack.push(item);
        }
    }
    string result;
    aStack.getTop(result);
    return result;
}


Stack getTokens(string in) {
    Stack tokens;
    string newItem = "";
    for (int i = 0; i < in.size(); i++) {
        if (in.at(i) == ' ') {
            tokens.push(newItem);
            newItem = "";
            continue;
        }
        newItem += in.at(i);
    }
    tokens.push(newItem);
    return tokens;
}

int getPriority(string operatorr) {
    if (operatorr == "-" || operatorr == "+") {
        return 1;
    }
    else if (operatorr == "*" || operatorr == "/") {
        return 2;
    }
    return 0;
}


