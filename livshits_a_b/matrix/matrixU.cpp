#include "matrixU.h"
#include <iostream>
using namespace std;

MatrixU::MatrixU()
    : nCol_{ 0 },
    nRow_{ 0 },
    pData{ nullptr }
{
}
MatrixU::MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol)
    : nRow_{ nRow },
    nCol_{ nCol },
    pData(new int[nRow*nCol])
{
}
MatrixU::MatrixU(const MatrixU& matr)
    : nRow_{ matr.nRow_ },
    nCol_{ matr.nCol_ },
    pData(new int[nRow_*nCol_])
{
    pData = matr.pData;
}
MatrixU MatrixU::operator=(const MatrixU& matr)
{
    nRow_ = matr.nRow_;
    nCol_ = matr.nCol_;
    pData = new int[nRow_*nCol_];
    pData = matr.pData;
    return *this;
}
MatrixU MatrixU::operator+=(const MatrixU& matr)
{
    if ((nRow_ != matr.nRow_) || (nCol_ != matr.nCol_))
        throw invalid_argument("Inequality of dimentions!");

    for (ptrdiff_t i = 0; i < nRow_; i++)
        for (ptrdiff_t j = 0; j < nCol_; j++)
            at(i, j) += matr.at(i, j);
    return *this;
}
MatrixU MatrixU::operator-=(const MatrixU& matr)
{
    if ((nRow_ != matr.nRow_) || (nCol_ != matr.nCol_))
        throw invalid_argument("Inequality of dimentions!");

    for (ptrdiff_t i = 0; i < nRow_; i++)
        for (ptrdiff_t j = 0; j < nCol_; j++)
            at(i, j) -= matr.at(i, j);
    return *this;
}
MatrixU MatrixU::operator*=(const int k)
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
        for (ptrdiff_t j = 0; j < nCol_; j++)
            at(i, j) *= k;
    return *this;
}
MatrixU MatrixU::operator/=(const int k)
{
    if (k == 0)
        throw invalid_argument("Division by zero!");
    for (ptrdiff_t i = 0; i < nRow_; i++)
        for (ptrdiff_t j = 0; j < nCol_; j++)
            at(i, j) /= k;
    return *this;
}
bool MatrixU::operator==(const MatrixU& matr)
{
    if ((nRow_ != matr.nRow_) || (nCol_ != matr.nCol_))
        return false;
    for (ptrdiff_t i = 0; i<nRow_; i++)
        for (ptrdiff_t j = 0; j<nCol_; j++)
            if (at(i, j) != matr.at(i, j))
            {
                return false;
            }
    return true;
}
bool MatrixU::operator!=(const MatrixU& matr)
{
    return !(operator==(matr));
}

int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_))
        throw out_of_range("Index is out of range");
    return pData[nCol_*iRow + iCol];
}
const int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)const
{
    if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_))
        throw out_of_range("Index is out of range");
    return pData[nCol_*iRow + iCol];
}
std::ostream& MatrixU::writeTo(std::ostream& ostrm) const
{
    for (int i = 0; i < nRow_; i++)
    {
        for (int j = 0; j < nCol_; j++)
            ostrm << pData[nCol_*i + j] << ' ';
        ostrm << endl;
    }
    ostrm << endl;
    return ostrm;
}
std::ostream& operator<<(std::ostream& ostr, MatrixU matr)
{
    return matr.writeTo(ostr);
}
