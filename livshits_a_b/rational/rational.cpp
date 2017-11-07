#include "rational.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Rational::Rational(const int num)
    : num_{ num },
    denum_{ 1 }
{
}

Rational::Rational(const int num, const int denum)
    : num_(num),
    denum_(denum)
{
    if (denum_ == 0)
        throw invalid_argument("Division by zero!");
}

Rational::Rational(const Rational& rhs)
    :   num_(rhs.num_),
        denum_(rhs.denum_)
{
    if (denum_ == 0)
        throw invalid_argument("Division by zero!");
}

Rational& Rational::operator=(const Rational& rhs)

{
    num_ = rhs.num_;
    denum_ = rhs.denum_;

    if (denum_ == 0)
        throw invalid_argument("Division by zero!");

    return *this;
}


Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_*rhs.denum_ + rhs.num_*denum_;
    denum_ *= rhs.denum_;
    correct();
    return *this;
}
Rational& Rational::operator+=(const int rhs)
{
    return operator+=(Rational(rhs));
}

Rational operator+(const Rational& numb1, const Rational& numb2)
{
    Rational res(numb1);
    res += numb2;
    return res;
}
Rational operator+(const Rational& numb1, const int numb2)
{
    Rational res(numb1);
    res += numb2;
    return res;
}
Rational operator+(const int numb1, const Rational& numb2)
{
    Rational res(numb1);
    res += numb2;
    return res;
}


Rational& Rational::operator-=(const Rational& rhs)
{
    num_ = num_*rhs.denum_ - rhs.num_*denum_;
    denum_ *= rhs.denum_;
    correct();
    return *this;
}
Rational& Rational::operator-=(const int rhs)
{
    return operator-=(Rational(rhs));
}

Rational operator-(const Rational& numb1, const Rational& numb2)
{
    Rational res(numb1);
    res -= numb2;
    return res;
}
Rational operator-(const Rational& numb1, const int numb2)
{
    Rational res(numb1);
    res -= numb2;
    return res;
}
Rational operator-(const int numb1, const Rational& numb2)
{
    Rational res(numb1);
    res -= numb2;
    return res;
}


Rational& Rational::operator*=(const Rational& rhs)
{
    num_ *= rhs.num_;
    denum_ *= rhs.denum_;
    correct();
    return *this;
}
Rational& Rational::operator*=(const int rhs)
{
    return operator*=(Rational(rhs));
}

Rational operator*(const Rational& numb1, const Rational& numb2)
{
    Rational res = numb1;
    res *= numb2;
    return res;
}
Rational operator*(const Rational& numb1, const int numb2)
{
    Rational res = numb1;
    res *= numb2;
    return res;
}
Rational operator*(const int numb1, const Rational& numb2)
{
    Rational res = numb1;
    res *= numb2;
    return res;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    num_ *= rhs.denum_;
    denum_ *= rhs.num_;
    correct();
    return *this;
}
Rational& Rational::operator/=(const int rhs)
{
    return operator/=(Rational(rhs));
}

Rational operator/(const Rational& numb1, const Rational& numb2)
{
    Rational res = lhs;
    res /= rhs;
    return res;
}
Rational operator/(const Rational& numb1, const int numb2)
{
    Rational res = numb1;
    res /= numb2;
    return res;
}
Rational operator/(const int numb1, const Rational& numb1)
{
    Rational res = numb1;
    res /= numb2;
    return res;
}

Rational& Rational::operator-()
{
    return *this *= -1;
}

bool operator>(const Rational& numb1, const Rational& numb2)
{
    Rational res(numb1);
    res -= numb2;
    return res.posit_Numb();
}

bool operator<(const Rational& numb1, const Rational& numb2)
{
    Rational res(numb1);
    res -= numb2;
    return !res.posit_Numb();
}

bool operator<=(const Rational& numb1, const Rational& numb2)
{
    return !(numb1 > numb2);
}

bool operator>=(const Rational& numb1, const Rational& numb2)
{
    return !(numb1 < numb2);
}

bool operator==(const Rational& numb1, const Rational& numb2)
{
    Rational delta = numb1 - numb2;
    return (fabs(delta.transf_Double()) < 1E-6);
}

bool operator!=(const Rational& numb1, const Rational& numb2)
{
    return !(numb1 == numb2);
}

int Rational::nod(int numb1, int numb2)
{
    while (numb1 && numb2)
    {
        if (abs(numb1) > abs(numb2))
            numb1 = abs(numb1 % numb2);
        else
            numb2 = abs(numb2 % numb1);
    }
    return (numb1 + numb2);
}


void Rational::Correct()
{
    int temp_nod = nod(num_, denum_);
    num /= temp_nod;
    denum /= temp_nod;

    if (denum_ < 0)
    {
        denum_ *= -1;
        num_ *= -1;
    }
}

double Rational::transf_Double()
{
    return num_ / (double)denum_;
}

bool Rational::posit_Numb()
{
    return (num_ > 0) && (denum_ > 0);
}

ostream& operator<<(std::ostream& ostrm, Rational rhs)
{
    return rhs.writeTo(ostrm);
}

ostream& Rational::writeTo(ostream& ostrm) const
{
    ostrm << leftBrace << _num_ << separator << denum_ << rightBrace;
    return ostrm;
}

