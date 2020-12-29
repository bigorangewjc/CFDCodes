#include "FdMatrix.h"
#include <iostream>

#include "Matrix.h"
#include "Vector.h"

CFdMatrix::CFdMatrix(const CFdMatrix &objFdMat)
    : m_objMat(*(new CMatrix(objFdMat.m_objMat))), m_objSrc(*(new CVector(objFdMat.m_objSrc)))
{
}

CFdMatrix::~CFdMatrix()
{
    delete &m_objMat;
    delete &m_objSrc;
}

CMatrix& CFdMatrix::GetMat()
{
    return m_objMat;
}

CVector& CFdMatrix::GetVec()
{
    return m_objSrc;
}

CFdMatrix &CFdMatrix::operator+(CFdMatrix &objFdMat)
{
    m_objMat = m_objMat + objFdMat.GetMat();
    return *this;
}

CFdMatrix &CFdMatrix::operator==(CField &objField)
{
    return *this;
}

void CFdMatrix::Print() const
{
}