#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>
#include <iostream>

class Rational
{
public:
    Rational();
    Rational(const int num);
    Rational(const int num, const int denum);
    Rational(const Rational& rhs);

    ~Rational() = default;

    Rational& operator=(const Rational& rhs);

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs);

    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const double rhs);

    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int rhs);

    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int rhs);

    Rational& operator-();

    bool posit_Numb();

    double transf_Double();

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    int num_{ 0 };
    int denum_{ 1 };

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };

    void correct();
    int nod(int numb1, int numb2);
};

Rational operator+(const Rational& numb1, const Rational& numb2);
Rational operator+(const Rational& numb1, const int numb2);
Rational operator+(const int numb1, const Rational& numb2);

Rational operator-(const Rational& numb1, const Rational& numb2);
Rational operator-(const Rational& numb1, const int numb2);
Rational operator-(const int numb1, const Rational& numb2);

Rational operator/(const Rational& numb1, const Rational& numb2);
Rational operator/(const Rational& numb1, const int numb2);
Rational operator/(const int numb1, const Rational& numb2);

Rational operator*(const Rational& numb1, const Rational& numb2);
Rational operator*(const Rational& numb1, const int numb2);
Rational operator*(const int numb1, const Rational& numb2);

bool operator==(const Rational& numb1, const Rational& numb2);
bool operator!=(const Rational& numb1, const Rational& numb2);

bool operator<=(const Rational& numb1, const Rational& numb2);
bool operator>=(const Rational& numb1, const Rational& numb2);

bool operator<(const Rational& numb1, const Rational& numb2);
bool operator>(const Rational& numb1, const Rational& numb2);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}
#endif