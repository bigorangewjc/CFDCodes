#include "FdMatrix.h"
#include <iostream>

#include "Vector.h"

CFdMatrix::CFdMatrix(const CFdMatrix &objFdMat)
    : m_objMat(*(new CMatrix(objFdMat.m_objMat)))
    , m_objSrc(*(new CVector(objFdMat.m_objSrc)))
{
}

CFdMatrix::~CFdMatrix()
{
    delete &m_objMat;
    delete &m_objSrc;
}

void CFdMatrix::Print() const
{
}