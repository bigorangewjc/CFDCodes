#include "GaussSolver.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CGaussSolver::CGaussSolver(const CMatrix &objMat, const CVector &objVecB)
    : m_iRows(objVecB.GetNumRows())
    , m_iCols(objMat.GetNumCols())
    , m_objMat(*(new CMatrix(objMat)))
    , m_objVecB(*(new CVector(objVecB)))
{
    if (m_iRows != m_iCols)
    {
        std::cout << "Matrix's column number " << m_iCols
                  << " is not equal to B's row number " << m_iRows << std::endl;
        abort();
    }
}

CGaussSolver::~CGaussSolver()
{
    delete &m_objMat;
    delete &m_objVecB;
}

void CGaussSolver::Solve(CVector &objVecX)
{
    // Forward elimination
    // Complexity: (N-1)*(N-i)*(N-i+1), i = 1,...,N-1
    // Elimilate the iColElim-th variable of X for rows below row iColElim of matrix A
    for (int iColElim = 0; iColElim < m_iCols - 1; iColElim++)
    {
        for (int iRow = iColElim + 1; iRow < m_iRows; iRow++)
        {
            // The element located in lower triangle of matrix will be eliminated
            //   to be zero, so the ratio of the element in lower triangle of matrix
            //   and the diagonal element is zero after eliminating. As a result,
            //   we need to store the quotient in a new variable dRatio.
            double dRatio = m_objMat(iRow, iColElim) / m_objMat(iColElim, iColElim);
            // In fact, there's no need to calculate elements aligned in column iColElim
            for (int iCol = iColElim; iCol < m_iCols; iCol++)
            {
                m_objMat(iRow, iCol) -= dRatio * m_objMat(iColElim, iCol);
            }
            m_objVecB(iRow) -= dRatio * m_objVecB(iColElim);
        }
    }
    // Backward substitution
    objVecX(m_iRows - 1) =
        m_objVecB(m_iRows - 1) / m_objMat(m_iRows - 1, m_iCols - 1);
    double dSum = 0;
    for (int iRow = m_iRows - 2; iRow >= 0; iRow--)
    {
        dSum = 0;
        for (int iCol = iRow + 1; iCol < m_iCols; iCol++)
        {
            dSum += m_objMat(iRow, iCol) * objVecX(iCol);
        }
        objVecX(iRow) = (m_objVecB(iRow) - dSum) / m_objMat(iRow, iRow);
    }
}