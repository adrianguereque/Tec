// Aplicación para prueba de clase Stack.

#include <iostream>
//#include <stack>

using namespace std;

#include "stack.h"    // stack

int main()
{
    stack<int> mystack;
    int myint;

    cout << "Please enter some integers (enter 0 to end):\n";

    do {
        cin >> myint;
        mystack.push(myint);
    } while (myint);

    cout << "size = " << myqueue.size();

    cout << "mystack contains: ";
    while (!mystack.empty()) {
        cout << ' ' << mystack.top();
        mystack.pop();
    }
    cout << '\n';

    return 0;
}