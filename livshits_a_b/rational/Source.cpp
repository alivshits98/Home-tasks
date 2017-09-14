//конструктор, деструктор, конструктор копирования, присваивание

#include <iostream>
#include <sstream>

class Rational
{

public:
    Rational() = default; //конструктор по умолчанию

    Rational(const int num) :num_(num) {}

    Rational(const int num, const int denum) :num_(num), denum_(denum)
    {
       /* if (0==denum) //нарушение инварианта
            throw ...  */
    }

    //привести число к каноническому виду: числитель - целое, знаменатель - натуральное
    //создать метод с нахождением НОД (алгоритм Евклида), 
    //разделить числитель и знаменатель на НОД, разобраться со знаками

    //~ - деструктор С МОДИФИКАТОРОМ ДОСТУПА PRIVATE!!!
    ~Rational() = default;

private:
    int num_{ 0 };
    int denum_{ 1 };

    static const char leftBrace{ '{' };
    static const char rightBrace{ '}' };
    static const char separator{ ',' };

};

int main()
{
    using namespace std;
    Rational z;
   // z += Rational(8, 2);
    
    return 0;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rat)
{
    return rat.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rat)
{
    return rat.readFrom(istrm);
}
