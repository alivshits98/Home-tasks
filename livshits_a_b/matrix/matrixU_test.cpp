#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    MatrixU a;
    cout << a;
    MatrixU b(1, 5);
    cout << b;
    a = b;
    cout << a;
    return 0;
}