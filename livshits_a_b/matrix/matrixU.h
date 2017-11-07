#ifndef MATRIXU_H
#define MATRIXU_H

#include <iosfwd>
#include <cstddef>

class MatrixU
{
public:
    ~MatrixU() = default;
    MatrixU();
    MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol);
    MatrixU(const MatrixU& Matr);
    MatrixU operator=(const MatrixU& matr);
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    MatrixU operator+=(const MatrixU& matr);
    MatrixU operator-=(const MatrixU& matr);
    MatrixU operator*=(const int k);
    MatrixU operator/=(const int k);
    bool operator==(const MatrixU& matr);
    bool operator!=(const MatrixU& matr);

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int* pData{ nullptr };
};
std::ostream& operator<<(std::ostream& ostr, MatrixU matr);

#endif

