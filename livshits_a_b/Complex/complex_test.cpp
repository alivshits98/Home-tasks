#include "complex.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{

    Complex z(0.0, 0);
    cout << z << endl;
    z += Complex(8.0, 1);
    cout << z << endl;
    z -= Complex(5.0, 2);
    cout << z << endl;
    z *= 7.0;
    cout << z << endl;
    z *= Complex(2.0, 2);
    cout << z << endl;
    z /= 2.0;
    cout << z << endl;
    z /= Complex(4.0, 3);
    cout << z << endl;

    return 0;
}