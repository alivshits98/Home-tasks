#include "vec3d.h"
#include "vec3d.cpp"

int main()
{
    Vec3d a;
    Vec3d b(1, 2, 3);
    Vec3d c(b);
    a = b;
    b.scal(a);
    cout << a << endl;
    cout << b << endl;

    return 0;
}