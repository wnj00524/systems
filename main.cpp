#include <iostream>
#include "headers/craft.h"

int main() {
    int a = 3;
    int *b = &a;
    cout << "A is " << a << " and b is " << b << " which stores " << *b << endl;
    *b = 4;
    cout << "A is " << a << " and b is " << b << " which stores " << *b << endl;

    delete [] b;

    craft a1(3);
    for (int a = 0; a < 15; a ++)
    {
        cout << "Tick " << a +1  << endl;
        a1.tick();
    }

    return 0;
}
