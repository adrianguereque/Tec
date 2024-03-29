// Aplicación para prueba de clase Queue.

#include <iostream>
//#include <queue>

using namespace std;

#include "queue.h"    // stack

int main()
{
    queue<int> myqueue;
    int myint;

    cout << "Please enter some integers (enter 0 to end):\n";

    do
    {
        cin >> myint;
        myqueue.push(myint);
    } while (myint);

    cout << "size = " << myqueue.size();

    cout << "myqueue contains: ";
    while (!myqueue.empty())
    {
        cout << ' ' << myqueue.front();
        myqueue.pop();
    }
    cout << '\n';

    return 0;
}