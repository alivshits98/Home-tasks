#include "rational.h"
#include <iostream>
#include <sstream>
using namespace std;

bool testParse(const std::string& str)
{
    istringstream istrm(str);
    Rational r;
    istrm >> r;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << r << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << r << endl;
    }
    return istrm.good();
}

int main()
{
    Rational r(1, 2);
    r.Correct(r);
    cout << r << endl;
    r += Rational(1, 4);
    r.Correct(r);
    cout << r << endl;
    r -= Rational(2, 3);
    r.Correct(r);
    cout << r << endl;
    r *= Rational(3, 5);
    r.Correct(r);
    cout << r << endl;
    r /= Rational(7, 9);
    r.Correct(r);
    cout << r << endl;
    Rational s(4, 3);
    Rational k(5, 6);
    bool h = k > Rational(3, 8);
    cout << h << endl;
    bool n = s < Rational(5, 6);
    cout << n << endl;
    bool f = s == k;
    cout << f << endl;
    bool w = k != Rational(1, 6);
    cout << w << endl;
    Rational a(1, 8);
    Rational* b(&a);
    Rational c(*b);
    cout << c << endl;
    Rational p(4, 5);
    Rational& u(p);
    cout << u << endl;
    testParse("{3/7}");
    testParse("{0/ 9}");
    testParse("{3/ 5");

    try
    {
        Rational nul(7, 0);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
