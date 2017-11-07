#ifndef VEC3D_H
#define VEC3D_H
#include <iosfwd>

struct Vec3d
{
public:
    Vec3d() = default;
    Vec3d(const double x, const double y, const double z);

    //деструктор
    ~Vec3d() = default;

    //конструктор копирования
    Vec3d(const Vec3d& v);

    //оператор присваивания
    Vec3d& operator=(const Vec3d& v);

    bool operator==(const Vec3d& a) const;
    bool operator!=(const Vec3d& a) const;

    Vec3d& operator+=(const Vec3d& a);
    Vec3d& operator-=(const Vec3d& a);
    Vec3d& operator*=(const double numb);
    Vec3d& operator/=(const double numb);

    double length();
    double scal(const Vec3d& a);
    Vec3d vect(const Vec3d& a);

    Vec3d& operator-();

    std::ostream& writeTo(std::ostream& ostrm) const;

    double x_{ 0 };
    double y_{ 0 };
    double z_{ 0 };
    const double e = 1E-6;
    static const char leftbrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

Vec3d& operator+(const Vec3d& vec1, const Vec3d& vec2);
Vec3d& operator-(const Vec3d& vec1, const Vec3d& vec2);

Vec3d& operator*(const double numb, const Vec3d& vec);
Vec3d& operator*(const Vec3d& vec, const double numb);

Vec3d& operator/(const double numb, const Vec3d& vec);
Vec3d& operator/(const Vec3d& vec, const double numb);

std::ostream& operator<<(std::ostream& ostrm, Vec3d vec);

#endif