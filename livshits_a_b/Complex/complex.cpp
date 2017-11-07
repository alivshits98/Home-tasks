#include "complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}
Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

Complex::Complex(const Complex& rhs)
    :   re(rhs.re),
        im(rhs.im)
{
}
Complex Complex::operator=(const Complex& rhs)
{
    re = rhs.re;
    im = rhs.im;
    return *this;
}

bool Complex::operator==(const Complex& rhs) const
{
    return ((abs(re - rhs.re) < e) && (abs(im - rhs.im) < e));
}

bool Complex::operator!=(const Complex& rhs) const
{
    return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex& Complex::operator+=(const double rhs)
{
    return operator+=(Complex(rhs));
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(rhs.re + lhs.re, rhs.im + lhs.im);
}
Complex operator+(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re + rhs);
}
Complex operator+(const double rhs, const Complex& lhs)
{
    return Complex(lhs.re + rhs);
}


Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex& Complex::operator-=(const double rhs)
{
    return operator-=(Complex(rhs));
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator-(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re - rhs);
}
Complex operator-(const double rhs, const Complex& lhs)
{
    return Complex(lhs.re - rhs);
}


Complex& Complex::operator*=(const Complex& rhs)
{
    
    re = (re*rhs.re) - (im*rhs.im);
    im = (re*rhs.im) + (im*rhs.re);
    return *this;
}
Complex& Complex::operator*=(const double rhs)
{
    return operator*=(Complex(rhs));
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex number(lhs);
    return number *= rhs;
}
Complex operator*(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re * rhs, lhs.im);
}
Complex operator*(const double rhs, const Complex& lhs)
{
    return Complex(lhs.re * rhs, lhs.im);
}


Complex& Complex::operator/=(const double rhs)
{
    return operator/=(Complex(rhs));
}
Complex& Complex::operator/=(const Complex& rhs)
{
    re = (rhs.re*re + rhs.im*im) / (rhs.re*rhs.re + rhs.im*rhs.im);
    im = (rhs.re*im - rhs.im*re) / (rhs.re*rhs.re + rhs.im*rhs.im);
    return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex number(lhs);
    return number /= rhs;
}
Complex operator/(const Complex& lhs, const double rhs)
{
    Complex number(lhs);
    return number /= rhs;
}
Complex operator/(const double rhs, const Complex& lhs)
{
    Complex number(lhs);
    return number /= rhs;
}

ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good())
    {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace))
        {
            re = real;
            im = imaginary;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
