#include "vec3d.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

Vec3d::Vec3d(const double x, const double y, const double z)
    : x_(x),
    y_(y),
    z_(z)
{
}

Vec3d::Vec3d(const Vec3d& v)
    : x_(v.x_),
    y_(v.y_),
    z_(v.z_)
{
}

Vec3d& Vec3d::operator=(const Vec3d& v)
{
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
    return *this;
}


bool Vec3d::operator==(const Vec3d& a) const
{
    return fabs(x_ - a.x_) && fabs(y_ - a.y_) && fabs(z_ - a.z_) < e;
}
bool Vec3d::operator!=(const Vec3d& a) const
{
    return !operator==(a);
}

Vec3d& Vec3d::operator+=(const Vec3d& a)
{
    x_ += a.x_;
    y_ += a.y_;
    z_ += a.z_;
    return *this;
}

Vec3d& Vec3d::operator-=(const Vec3d& a)
{
    x_ -= a.x_;
    y_ -= a.y_;
    z_ -= a.z_;
    return *this;
}

Vec3d& Vec3d::operator*=(const double numb)
{
    x_ *= numb;
    y_ *= numb;
    z_ *= numb;
    return *this;
}

Vec3d& Vec3d::operator/=(const double numb)
{
    x_ /= numb;
    y_ /= numb;
    z_ /= numb;
    return *this;
}

Vec3d& Vec3d::operator-()
{
    return *this *= -1;
}

Vec3d& operator+ (const Vec3d& vec1, const Vec3d& vec2)
{
    Vec3d temp(vec1);
    temp += vec2;
    return temp;
}

Vec3d& operator- (const Vec3d& vec1, const Vec3d& vec2)
{
    Vec3d temp(vec1);
    temp -= vec2;
    return temp;
}

Vec3d& operator* (const Vec3d& vec, const double numb)
{
    Vec3d temp(vec);
    temp *= numb;
    return temp;
}
Vec3d& operator* (const double numb, const Vec3d& vec)
{
    Vec3d temp(vec);
    temp *= numb;
    return temp;
}

Vec3d& operator/ (const Vec3d& vec, const double numb)
{
    Vec3d temp(vec);
    temp /= numb;
    return temp;
}
Vec3d& operator/ (const double numb, const Vec3d& vec)
{
    Vec3d temp(vec);
    temp /= numb;
    return temp;
}

double Vec3d::scal(const Vec3d& a)
{
    double sc;
    sc = a.x_*x_ + a.y_*y_ + a.z_*z_;
    return sc;
}

Vec3d Vec3d::vect(const Vec3d& a)
{
    Vec3d s(y_ * a.z_ - z_ * a.y_, z_ * a.x_ - x_*a.z_, x_*a.y_ - y_*a.x_);

    return s;
}

double Vec3d::length()
{
    return sqrt(x_*x_ + y_*y_ + z_*z_);
}

ostream& Vec3d::writeTo(ostream& ostrm) const
{
    ostrm << "(" << x_ << ", " << y_ << ", " << z_ << ")";
    return ostrm;
}

ostream& operator<<(std::ostream& ostrm, Vec3d vec)
{
    return vec.writeTo(ostrm);
}





