#ifndef  COMPLEX_H
#define COMPLEX_H
#include <iosfwd>

struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    Complex(const Complex& rhs);
    Complex operator=(const Complex& rhs);

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double e = 1E-6;
    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}
inline std::istream& operator>> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double rhs, const Complex& lhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double rhs, const Complex& lhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double rhs, const Complex& lhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double rhs, const Complex& lhs);

#endif