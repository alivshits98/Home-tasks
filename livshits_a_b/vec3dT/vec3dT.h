#ifndef VEC3D_H
#define VEC3D_H

#include <iosfwd>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

template<typename T>
struct Vec3dT
{
public:
    Vec3dT() = default;
    Vec3dT(const T x, const T y, const T z);

    //деструктор
    ~Vec3dT() = default;

    //конструктор копирования
    Vec3dT(const Vec3dT& v);

    //оператор присваивания
    Vec3dT& operator=(const Vec3dT& v);

    Vec3dT<T>& operator+=(const Vec3dT<T>& v);
    Vec3dT<T>& operator-=(const Vec3dT<T>& v);
    Vec3dT<T>& operator*=(const T numb);
    Vec3dT<T>& operator/=(const T numb);

    bool operator==(const Vec3dT<T>& v);
    bool operator!=(const Vec3dT<T>& v);

    Vec3dT<T>& operator-();

    double length();

    double scal(const Vec3dT<T>& v);

    Vec3dT<T>  vect(const Vec3dT<T>& v);

    bool compareTo(const Vec3dT<T>& v);

    ostream& writeTo(ostream& ostrm) const;

    T x_{ T() };
    T y_{ T() };
    T z_{ T() };
    const double e = 1E-6;
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

template<typename T>
Vec3dT<T>::Vec3dT(const T x, const T y, const T z)
    : x_(x),
    y_(y),
    z_(z)
{
}

template<typename T>
Vec3dT<T>::Vec3dT(const Vec3dT& v)
    : x_(v.x_),
    y_(v.y_),
    z_(v.z_)
{
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator=(const Vec3dT<T>& v)
{
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator-()
{
    return *this *= -1;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator+=(const Vec3dT& v)
{
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator-=(const Vec3dT& v)
{
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator*=(const T numb)
{
    x_ *= numb;
    y_ *= numb;
    z_ *= numb;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator/=(const T numb)
{
    x_ /= numb;
    y_ /= numb;
    z_ /= numb;
    return *this;
}

template<typename T>
Vec3dT<T>& operator+(const Vec3dT<T>& vec1, const Vec3dT<T>& vec2)
{
    Vec3dT<T>temp(vec1);
    temp += vec2;
    return temp;
}

template<typename T>
Vec3dT<T>& operator-(const Vec3dT<T>& vec1, const Vec3dT<T>& vec2)
{
    Vec3dT<T>temp(vec1);
    temp -= vec2;
    return temp;
}

template<typename T>
Vec3dT<T>& operator*(const Vec3dT<T>& vec, const T numb)
{
    Vec3dT<T>temp(vec);
    temp *= numb;
    return temp;
}

template<typename T>
Vec3dT<T>& operator*(const T numb, const Vec3dT<T>& vec)
{
    Vec3dT<T>temp(vec);
    temp *= numb;
    return temp;
}

template<typename T>
Vec3dT<T>& operator/(const Vec3dT<T>& vec, const T numb)
{
    Vec3dT<T>temp(vec);
    temp /= numb;
    return temp;
}

template<typename T>
Vec3dT<T>& operator/(const T numb, const Vec3dT<T>& vec)
{
    Vec3dT<T>temp(vec);
    temp /= numb;
    return temp;
}


template<typename T>
T scal(const Vec3dT<T>& a, const Vec3dT<T>& b)
{
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

template <typename T>
Vec3dT<T>& Vec3dT<T>::mult(const T k)
{
    x *= k;
    y *= k;
    z *= k;
    return *this;
}

template<typename T>
bool Vec3dT<T>::operator==(const Vec3dT& a)
{
    return compareTo(a);
}

template<typename T>
bool Vec3dT<T>::operator!=(const Vec3dT<T>& v)
{
    return !operator==(v);
}

template<>
bool Vec3dT<double>::compareTo(const Vec3dT<double>& v)
{
    return (fabs(x_ - v.x_ < e)) && (fabs(y_ - v.y_ < e)) && (fabs(z_ - v.z_ < e));
}

template<>
bool Vec3dT<float>::compareTo(const Vec3dT<float>& v)
{
    return (fabs(x_ - v.x_ < e)) && (fabs(y_ - v.y_ < e)) && (fabs(z_ - v.z_ < e));
}

template<typename T>
bool Vec3dT<T>::compareTo(const Vec3dT<T>& v)
{
    return (x_ == v.x_ && y_ == v.y_ && z_ == v.z_);
}

template<typename T>
double Vec3dT<T>::length()
{
    return sqrt(x_*x_ + y_*y_ + z_*z_);
}



template<typename T>
double Vec3dT<T>::scal(const Vec3dT<T>& v)
{
    double scalar = v.x_ * x_ + v.y_ * y_ + v.z_ * z_;
    return scalar;
}

template<typename T>
Vec3dT<T> Vec3dT<T>::vect(const Vec3dT<T>& v)
{
    Vec3dT temp(y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_*v.z_, x_*v.y_ - y_*v.x_);
    return temp;

}

template<typename T>
inline std::ostream& operator<<(ostream& ostrm, const Vec3dT<T>& vec)
{
    return vec.writeTo(ostrm);
}

template<typename T>
ostream& Vec3dT<T>::writeTo(ostream& ostrm) const
{
    ostrm << leftBrace << x << separator << y << separator << z << rightBrace << endl;
    return ostrm;
}

#endif

