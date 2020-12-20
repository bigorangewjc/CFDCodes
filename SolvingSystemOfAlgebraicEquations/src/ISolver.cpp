#include "ISolver.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

ISolver::ISolver(const CMatrix &objMat, const CVector &objVecB)
    : m_iRows(objVecB.GetNumRows())
    , m_iCols(objMat.GetNumCols())
    , m_objMat(objMat)
    , m_objVecB(objVecB)
{
    if (m_iRows != m_iCols)
    {
        std::cout << "A's column number " << m_iCols
                  << " is not equal to B's row number " << m_iRows << std::endl;
        abort();
    }
}

ISolver::~ISolver()
{
}

void ISolver::SetNewMat(const CMatrix &objMat)
{
    if (m_iRows != objMat.GetNumRows() ||
        m_iCols != objMat.GetNumCols())
    {
        std::cout << "Size of matrix in solver is (" << m_iRows << " X "
                  << m_iCols << "), which is not equal to objMat's size ("
                  << objMat.GetNumRows() << " X " << objMat.GetNumCols()
                  << ")" << std::endl;
        abort();
    }
    for (int iRow; iRow < m_iRows; iRow++)
    {
        for (int iCol; iCol < m_iCols; iCol++)
        {
            m_objMat(iRow, iCol) = objMat(iRow, iCol);
        }
    }
}

void ISolver::SetNewVecB(const CVector &objVecB)
{
    if (m_iCols != objVecB.GetNumRows())
    {
        std::cout << "A's column number " << m_iCols
                  << " is not equal to new B's number of rows "
                  << m_iRows << std::endl;
        abort();
    }
    for (int iRow; iRow < m_iCols; iRow++)
    {
        m_objVecB(iRow) = objVecB(iRow);
    }
}