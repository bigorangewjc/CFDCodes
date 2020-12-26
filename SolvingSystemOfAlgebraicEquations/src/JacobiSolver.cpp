#include "JacobiSolver.h"
#include <cmath>
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CJacobiSolver::CJacobiSolver(const CMatrix &objMat, const CVector &objVecB)
    : m_iRows(objVecB.GetNumRows())
    , m_iCols(objMat.GetNumCols())
    , m_objMat(*(new CMatrix(objMat)))
    , m_objVecB(*(new CVector(objVecB)))
    , m_objVecXPrev(*(new CVector(m_iRows)))
{
    if (m_iRows != m_iCols)
    {
        std::cout << "Matrix's column number " << m_iCols
                  << " is not equal to B's row number " << m_iRows << std::endl;
        abort();
    }
}
CJacobiSolver::~CJacobiSolver()
{
}
void CJacobiSolver::SetTol(const double &dTol)
{
    m_dTol = dTol;
}
void CJacobiSolver::SetInitVec(const CVector &objVecInit)
{
    if (m_iCols != objVecInit.GetNumRows())
    {
        std::cout << "A's column number " << m_iCols
                  << " is not equal to new B's row number " << m_iRows << std::endl;
        abort();
    }
    for (int iI = 0; iI < m_iRows; iI++)
    {
        m_objVecXPrev(iI) = objVecInit(iI);
    }
}
void CJacobiSolver::Solve(CVector &objVecX)
{
    int iIter = 1;
    double dError = 0.0;
    while (1 == iIter || dError > m_dTol)
    {
        // Calculate new estimates
        for (int iI = 0; iI < m_iRows; iI++)
        {
            objVecX(iI) = m_objVecB(iI);
            for (int iJ = 0; iJ < m_iCols; iJ++)
            {
                if (iI != iJ)
                {
                    objVecX(iI) -= m_objMat(iI, iJ) * m_objVecXPrev(iJ);
                }
            }
            objVecX(iI) /= m_objMat(iI, iI);
        }
        // Calculate maximum normalized difference between
        //   two consecutive iteration estimates
        double dTmp = 0.0;
        dError = fabs(objVecX(0) - m_objVecXPrev(0));
        m_objVecXPrev(0) = objVecX(0);
        for (int iI = 1; iI < m_iRows; iI++)
        {
            dTmp = fabs(objVecX(iI) - m_objVecXPrev(iI));
            if (dError < dTmp)
            {
                dError = dTmp;
            }
            m_objVecXPrev(iI) = objVecX(iI);
        }
        std::cout << "iIter = " << iIter << ", dError = " << dError << std::endl;
        iIter++;
    }
}