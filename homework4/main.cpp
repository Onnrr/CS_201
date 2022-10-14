/**
Mehmet Onur Uysal
22002609
*/

#include <iostream>
#include "AlgebraicExpression.h"

using namespace std;

int main() {
    cout << infix2prefix("( 12 + 5 ) - 20 * 4") << endl;
    cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << evaluateInfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << prefix2infix("* + * 100 2 4 - 12 4") << endl;
    cout << prefix2postfix("* + * 100 2 4 - 12 4") << endl;
    cout << evaluatePrefix("* + * 100 2 4 - 12 4") << endl;
    cout << postfix2infix("100 12 2 - 8 * + 4 /") << endl;
    cout << postfix2prefix("100 12 2 - 8 * + 4 /") << endl;
    cout << evaluatePostfix("100 12 2 - 8 * + 4 /") << endl;

    cout << "--------------------------------------------" << endl;

    cout << infix2prefix("56 - 3 * ( 13 + 23 ) + 9") << endl;
    cout << infix2postfix("56 - 3 * ( 13 + 23 ) + 9") << endl;
    cout << evaluateInfix("56 - 3 * ( 13 + 23 ) + 9") << endl;

    cout << prefix2infix("* + - 3 8 14 / 16 6") << endl;
    cout << prefix2postfix("* + - 3 8 14 / 16 6") << endl;
    cout << evaluatePrefix("* + - 3 8 14 / 16 6") << endl;

    cout << postfix2infix("12 7 56 * 4 - 34 + / 5 +") << endl;
    cout << postfix2prefix("12 7 56 * 4 - 34 + / 5 +") << endl;
    cout << evaluatePostfix("12 7 56 * 4 - 34 + / 5 +") << endl;

    cout << endl;
    cout << evaluateInfix("56 - 3 * ( 13 + 23 ) + 9") <<endl;
    cout << evaluatePostfix(infix2postfix("56 - 3 * ( 13 + 23 ) + 9")) << endl;
    cout << evaluatePrefix(infix2prefix("56 - 3 * ( 13 + 23 ) + 9")) << endl;
    cout << endl;

    cout <<evaluatePostfix("12 7 56 * 4 - 34 + / 5 +")<<endl;
    cout << evaluateInfix(postfix2infix("12 7 56 * 4 - 34 + / 5 +")) << endl;
    cout << evaluatePrefix(postfix2prefix("12 7 56 * 4 - 34 + / 5 +")) << endl;
    cout << endl;


    return 0;
}
